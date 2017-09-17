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
	map<string, string> deviceIdMap, vendorIdMap;
public:
	DeviceInfo(LPCTSTR enumarator);
	map<string, string> getDeviceIdMap();
	map<string, string> getVendorIdMap();
	bool findDevices(iParser *p);
	~DeviceInfo();
};

