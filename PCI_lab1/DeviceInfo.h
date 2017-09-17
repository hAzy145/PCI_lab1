#pragma once
#include <windows.h>
#include <devguid.h>
#include <setupapi.h>
#include <cfgmgr32.h>
#include <map>
using namespace std;

#pragma comment (lib, "setupapi.lib")

class DeviceInfo
{
private:
	HDEVINFO hDevInfo;			//device info set that contains requested device information elements
	map<LPCTSTR, LPCTSTR> deviceIdMap, vendorIdMap;
public:
	DeviceInfo(LPCTSTR enumarator);
	map<LPCTSTR, LPCTSTR> getDeviceIdMap();
	map<LPCTSTR, LPCTSTR> getVendorIdMap();
	bool findDevices();
	~DeviceInfo();
};

