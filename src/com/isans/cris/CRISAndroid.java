package com.isans.cris;

import java.util.Vector;

public class CRISAndroid {
	
	/*
	public class Polar{
		public double linear = 0.0;
		public double angular = 0.0;
		public Polar(double linear, double angular){
			this.linear = linear;
			this.angular = angular;
		}
		
	}
	public class Pose{
		public double x = 0.0;
		public double y = 0.0;
		public double theta = 0.0;
		public Pose(double x, double y, double theta){
			this.x = x;
			this.y = y;
			this.theta = theta;
		}
	}
	public class MapInfo{
		public double x = 0.0;
		public double y = 0.0;
		public int type = -1;
	}
	*/
	/* this is used to load the 'cris' library on application
     * startup. The library has already been unpacked into
     * /data/data/com.isans.cris/lib/libcris.so at
     * installation time by the package manager.
     */
	static {
	      System.loadLibrary("cris");
	}	
	
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
	public native boolean GoToPose(Vector<Double> target);
	public native boolean Stop();
	public native boolean SetLed(int which);
	public native boolean Command(int cmd); 
	// blocking function
	public native boolean MoveDeltaB(double delta);
	public native boolean TurnDeltaB(double delta);
	public native boolean GoToPoseB(Vector<Double> target);
	
	// displacement 
	public native boolean SetMaxVelocity(Vector<Double> velocity);
	public native Vector<Double> GetMaxVelocity();
	public native void SetMaxAcceleration(Vector<Double> acceleration);
	public native Vector<Double> GetMaxAcceleration();
	public native void SetVelocity(Vector<Double> velocity);
	public native Vector<Double> GetVelocity();
	public native Vector<Double> GetMap();
}
