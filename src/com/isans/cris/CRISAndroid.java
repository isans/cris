package com.isans.cris;

import java.io.IOException;
import java.util.Vector;

import android.hardware.usb.UsbDevice;
import android.hardware.usb.UsbDeviceConnection;
import android.hardware.usb.UsbEndpoint;
import android.hardware.usb.UsbInterface;
import android.hardware.usb.UsbManager;
import android.util.Log;

public class CRISAndroid {
	
	private RequestQueue sendQueue;
	private Thread sendHandler;
	private UsbManager usbManager;
	private UsbDevice usbDevice;
	private UsbDeviceConnection usbConnection;
	private UsbEndpoint endInpoint;
	private UsbEndpoint endOutpoint;
	private UsbInterface intf;
	
	public CRISAndroid(){
		sendHandler = new Thread(new SenderThread());
	}
	/* this is used to load the 'cris' library on application
     * startup. The library has already been unpacked into
     * /data/data/com.isans.cris/lib/libcris.so at
     * installation time by the package manager.
     */
	static {		
		System.loadLibrary("cris");
	}	
	
	// cris information	
	public native int GetState();
	public native double GetProcessRate();
	public native String GetVendorID();
	// contact USB
	public native static int SendData(byte[] data);
	public native static byte[] GetData();	
	// action
	public native boolean Initialize();
	public native boolean MoveForward();
	public native boolean MoveBackward();
	public native boolean TurnLeft();
	public native boolean TurnRight();		
	public native boolean MoveDelta(double delta);
	public native boolean TurnDelta(double delta);
	public native boolean GoToPose(double x, double y, double theta);
	public native boolean Stop();
	public native boolean SetLed(int which);
	public native boolean Command(int cmd); 
	// blocking function
	public native boolean MoveDeltaB(double delta);
	public native boolean TurnDeltaB(double delta);
	public native boolean GoToPoseB(double x, double y, double theta);	
	// displacement 
	public native void SetMaxVelocity(double linear, double angular);
	public native double[] GetMaxVelocity();
	public native void SetMaxAcceleration(double linear, double angular);
	public native double[] GetMaxAcceleration();
	public native void SetVelocity(double linear, double angular);
	public native double[] GetVelocity();
	public native double[] GetMap();
	
	public void sendData(byte[] buffer){
		sendQueue.enqueue(buffer);
	}
	public int readData(byte[] buffer, int timeout) throws InterruptedException{
		return usbConnection.bulkTransfer(endInpoint, buffer, buffer.length, timeout);
	}
	public void closePort() throws IOException, InterruptedException{
		int count = 0;
		while( !sendQueue.isEmtpy() && (count < 3) ){
			Thread.sleep(1000);
			count++;
		}
		usbConnection.releaseInterface(intf);
		usbConnection.close();
		
		if( sendHandler != null && sendHandler.isAlive() ){
			sendHandler.interrupt();
		}
	}
	class SenderThread implements Runnable{
		
		@Override
		public void run() {
			// TODO Auto-generated method stub
			byte[] buffer;
			int timeout = 2000;
			try
			{
				while(!Thread.currentThread().isInterrupted())
				{
					buffer = sendQueue.dequeue();
					usbConnection.bulkTransfer(endOutpoint, buffer, buffer.length, timeout);
					Thread.sleep(10);
				}
			}
			catch( Exception e)
			{
				sendQueue.clearQueue();
			}
		}		
	}
}
