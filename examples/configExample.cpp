

#include "CConfigFile.h"

#include <iostream>
using namespace std;
void main()
{	
	cris::CConfigFile config("conf.ini");
	if( config.sectionExists("iclebo") )
	{
		std::string vendorID = config.read_string("iclebo", "vendorID", "");
		cout << "vendorID: " << vendorID << ", ";
		double rate = config.read_double("iclebo", "process_rate", 0.0);
		cout << "rate: " << rate;
		float wheel_base		= config.read_float("iclebo", "wheel_base", 0);
		cout << ", wheel_base: " << wheel_base << endl;
	
	}
	int a;
	cin >> a; 
}