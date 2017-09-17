#include "DeviceInfo.h"



DeviceInfo::DeviceInfo(LPCTSTR enumarator)
{
	hDevInfo = SetupDiGetClassDevs(NULL, enumarator, NULL, DIGCF_ALLCLASSES | DIGCF_PRESENT);
}


DeviceInfo::~DeviceInfo()
{
}

map<LPCTSTR, LPCTSTR> DeviceInfo::getDeviceIdMap()
{
	return deviceIdMap;
}

map<LPCTSTR, LPCTSTR> DeviceInfo::getVendorIdMap()
{
	return vendorIdMap;
}