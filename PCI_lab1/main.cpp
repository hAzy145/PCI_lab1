#include <iostream>
#include <string>
#include <Windows.h>
#include "DeviceInfo.h"
#include "iParser.h"
#include "Parser.h"
using namespace std;


int main()
{
	DeviceInfo info(TEXT("PCI"));
	iParser *p = new Parser;
	info.findDevices(p);
	multimap<string, string> did = info.getDeviceIdMap();
	multimap<string, string> vid = info.getVendorIdMap();
	multimap<string, string>::iterator it1, it2;
	for (it1 = did.begin(), it2 = vid.begin(); it1 != did.end(); it1++, it2++)
	{
		cout << "Vendor ID: " << (*it2).first << "(" << (*it2).second << ")\t\tDevice ID: " << (*it1).first << "(" << (*it1).second << ")\n";
	}
	system("pause");
	return 0;
}