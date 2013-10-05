

#include "CConfigFile.h"
#include "CPoses.h"
#include "iClebo.h"

#include <iostream>
using namespace std;
void main()
{	
	cris::CConfigFile config("conf.ini");
	
	iClebo robot;
		
	robot.loadConfig(config, "IK_1");
	robot.initialize();
	while(1)
	{
		robot.doProcess();

		robot.SetVelocity(Polar(0,0.1));
		robot.MoveForward();
	}

	int a;
	cin >> a; 
}