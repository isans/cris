package com.isans.cris;

import java.util.HashMap;
import java.util.Iterator;

import android.hardware.usb.UsbConstants;
import android.hardware.usb.UsbDevice;
import android.hardware.usb.UsbDeviceConnection;
import android.hardware.usb.UsbEndpoint;
import android.hardware.usb.UsbInterface;
import android.hardware.usb.UsbManager;
import android.os.Bundle;
import android.app.Activity;
import android.app.PendingIntent;
import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.content.IntentFilter;
import android.util.Log;
import android.view.Menu;
import android.view.View;

public class MainActivity extends Activity implements View.OnClickListener {

	
    public static UsbDevice sDevice = null;
	private boolean mStop = false;
	private boolean mStopped = true;
	
	private static final String ACTION_USB_PERMISSION =
		    "com.android.example.USB_PERMISSION";
	private static final String TAG = "cirs";
		
	private static final String VID_PID = "0403:6001";
	public CRISAndroid cris = new CRISAndroid();
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
		
		findViewById(R.id.move_forward_btn).setOnClickListener(this);
		findViewById(R.id.move_backward_btn).setOnClickListener(this);
        findViewById(R.id.turn_left_btn).setOnClickListener(this);
        findViewById(R.id.turn_right_btn).setOnClickListener(this);
        findViewById(R.id.test1_btn).setOnClickListener(this);
        findViewById(R.id.test2_btn).setOnClickListener(this);
        findViewById(R.id.test3_btn).setOnClickListener(this);
	}
	
	@Override
	protected void onStart() {
		// TODO Auto-generated method stub
		mStop = false;
    	if(mStopped)
    		enumerate();
		super.onStart();
	}

	private void enumerate() {
		// TODO Auto-generated method stub
		l("enumerating");
		UsbManager usbman = (UsbManager) getSystemService(USB_SERVICE);

		HashMap<String, UsbDevice> devlist = usbman.getDeviceList();
		Iterator<UsbDevice> deviter = devlist.values().iterator();
		PendingIntent pi = PendingIntent.getBroadcast(this, 0, new Intent(
				ACTION_USB_PERMISSION), 0);

		while (deviter.hasNext()) {
			UsbDevice d = deviter.next();
			l("Found device: "
					+ String.format("%04X:%04X", d.getVendorId(),
							d.getProductId()));
			if (String.format("%04X:%04X", d.getVendorId(), d.getProductId()).equals(VID_PID)) 
			{
				// we need to upload the hex file, first request permission
				l("Device under: " + d.getDeviceName());
				registerReceiver(mPermissionReceiver, new IntentFilter(ACTION_USB_PERMISSION));
				if (!usbman.hasPermission(d))
					usbman.requestPermission(d, pi);
				else
					mainloop(d);
				break;
			}
		}
		l("no more devices found");
	}

	@Override
	protected void onStop() {
		// TODO Auto-generated method stub
		mStop = true;
    	unregisterReceiver(mPermissionReceiver);
		super.onStop();
	}
	private final BroadcastReceiver mPermissionReceiver = new BroadcastReceiver() {
		@Override
		public void onReceive(Context context, Intent intent) {
			if (intent.getAction().equals(ACTION_USB_PERMISSION)) {
				if (!intent.getBooleanExtra(
						UsbManager.EXTRA_PERMISSION_GRANTED, false)) {
					e("Permission not granted :(");
				} else {
					l("Permission granted");
					UsbDevice dev = (UsbDevice) intent
					.getParcelableExtra(UsbManager.EXTRA_DEVICE);
					if (dev != null) {
						if (String.format("%04X:%04X", dev.getVendorId(),
								dev.getProductId()).equals(VID_PID)) {
							mainloop(dev);//has new thread
						}
					} else {
						e("device not present!");
					}
				}
			}
		}
	};
	private void mainloop(UsbDevice d) {
		// TODO Auto-generated method stub
		sDevice = d;// not really nice...
		new Thread(mLoop).start();
	}

	private Runnable mLoop = new Runnable() {

		@Override
		public void run() {
			// TODO Auto-generated method stub
			UsbDevice dev = sDevice;
			if (dev == null)
				return; 
			UsbManager usbm = (UsbManager) getSystemService(USB_SERVICE);
			UsbDeviceConnection conn = usbm.openDevice(dev);
			l("Interface Count: "+dev.getInterfaceCount());
			l("Using "+String.format("%04X:%04X", sDevice.getVendorId(), sDevice.getProductId()));

			if(!conn.claimInterface(dev.getInterface(0), true)) 
				return;
			
			conn.controlTransfer(0x40, 0, 0, 0, null, 0, 0);//reset
			conn.controlTransfer(0x40, 0, 1, 0, null, 0, 0);//clear Rx
			conn.controlTransfer(0x40, 0, 2, 0, null, 0, 0);//clear Tx
			conn.controlTransfer(0x40, 0x03, 0x4138, 0, null, 0, 0);//baudrate 9600

			UsbEndpoint epIN = null;
			UsbEndpoint epOUT = null;
			
			byte counter = 0;
			
			UsbInterface usbIf = dev.getInterface(0);				
			for(int i = 0; i < usbIf.getEndpointCount(); i++)
			{
				l("EP: "+String.format("0x%02X", usbIf.getEndpoint(i).getAddress()));
				if(usbIf.getEndpoint(i).getType() == UsbConstants.USB_ENDPOINT_XFER_BULK)
				{
					l("Bulk Endpoint");
					if(usbIf.getEndpoint(i).getDirection() == UsbConstants.USB_DIR_IN)
						epIN = usbIf.getEndpoint(i);
					else
						epOUT = usbIf.getEndpoint(i);
				}
				else
				{
					l("Not Bulk");
				}
			}				
			for(;;)//this is the main loop for transferring	
			{	
				conn.bulkTransfer(epOUT, new byte[]{counter}, 1, 0);
				try {
					Thread.sleep(1000);
				} catch (InterruptedException e) {
					e.printStackTrace();
				}
				
				if(mStop){
					mStopped = true;
					return;
				}
				l("sent "+counter);
				counter++;
				counter = (byte) (counter % 16);
			}
		}		
	};
	private void l(String s) {
		// TODO Auto-generated method stub
		Log.d("FTDI_USB", ">==< " + s.toString() + " >==<");
	}

	private void e(String s) {
		// TODO Auto-generated method stub
		Log.e("FTDI_USB", ">==< " + s.toString() + " >==<");
	}
	
	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		// Inflate the menu; this adds items to the action bar if it is present.
		getMenuInflater().inflate(R.menu.main, menu);
		return true;
	}
	public void onClick(View v) {
		
        if( v.getId() == R.id.move_forward_btn ) 
        	cris.MoveForward();
        else if( v.getId() == R.id.move_backward_btn) 
        	cris.MoveBackward();
        else if( v.getId() == R.id.turn_left_btn) 
        	cris.TurnLeft();
        else if( v.getId() == R.id.turn_right_btn) 
        	cris.TurnRight();
        else if( v.getId() == R.id.test1_btn){        	
        	double[] vel = cris.GetVelocity();
        	
        	if( vel.length == 2 ){
        		Log.d(TAG, "linear: " + String.valueOf(vel[0]));
        		Log.d(TAG, "angular: " + String.valueOf(vel[1]));
        	}
        }
        else if( v.getId() == R.id.test2_btn) 
        	cris.TurnRight();
        else if( v.getId() == R.id.test3_btn) 
        	cris.TurnRight();
       
	}
}
