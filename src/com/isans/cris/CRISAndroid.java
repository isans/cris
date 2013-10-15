package com.isans.cris;

public class CRISAndroid {
	
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
}
