#pragma once
#include <windows.h>
#include <devguid.h>
#include <setupapi.h>
#include <cfgmgr32.h>
#include <map>
#include "iParser.h"
using namespace std;

#pragma comment (lib, "setupapi.lib")

class DeviceInfo
{
private:
	HDEVINFO hDevInfo;			//device info set that contains requested device information elements
	multimap<string, string> deviceIdMap, vendorIdMap;
	string wcharToString(LPCTSTR);
public:
	DeviceInfo(LPCTSTR enumarator);
	multimap<string, string> getDeviceIdMap();
	multimap<string, string> getVendorIdMap();
	bool findDevices(iParser *p);
	~DeviceInfo();
};

