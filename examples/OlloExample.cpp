

#include "CConfigFile.h"
#include "Ollo.h"

#include <iostream>
using namespace std;
void main()
{	
	cris::CConfigFile config("conf.ini");
	
	OLLO robot;
		
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