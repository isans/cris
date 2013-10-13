package com.isans.cris;

import android.os.Bundle;
import android.app.Activity;
import android.view.Menu;
import android.view.View;

public class MainActivity extends Activity implements View.OnClickListener {

	public CRISAndroid cris = new CRISAndroid();
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
		
		findViewById(R.id.move_forward_btn).setOnClickListener(this);
		findViewById(R.id.move_backward_btn).setOnClickListener(this);
        findViewById(R.id.turn_left_btn).setOnClickListener(this);
        findViewById(R.id.turn_right_btn).setOnClickListener(this);
        
		// Initialize();
        // setVelocity()
       
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
       
	}
}
