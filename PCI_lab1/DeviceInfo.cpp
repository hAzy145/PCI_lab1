#include "DeviceInfo.h"



DeviceInfo::DeviceInfo(LPCTSTR enumarator)
{
	hDevInfo = SetupDiGetClassDevs(NULL, enumarator, NULL, DIGCF_ALLCLASSES | DIGCF_PRESENT);
}


DeviceInfo::~DeviceInfo()
{
}

map<string, string> DeviceInfo::getDeviceIdMap()
{
	return deviceIdMap;
}

map<string, string> DeviceInfo::getVendorIdMap()
{
	return vendorIdMap;
}

bool DeviceInfo::findDevices(iParser *parser)
{
	if (hDevInfo == INVALID_HANDLE_VALUE)
		return false;
	return true;
}