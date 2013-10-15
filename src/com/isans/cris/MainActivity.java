package com.isans.cris;

import android.os.Bundle;
import android.app.Activity;
import android.util.Log;
import android.view.Menu;
import android.view.View;

public class MainActivity extends Activity implements View.OnClickListener {
	
	private static final String TAG = "cris";
	private CRISAndroid cris = new CRISAndroid();
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
		super.onStart();
	}
	@Override
	protected void onStop() {
		// TODO Auto-generated method stub		
		super.onStop();
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
