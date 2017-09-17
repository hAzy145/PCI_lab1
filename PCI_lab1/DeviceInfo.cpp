#include "DeviceInfo.h"



DeviceInfo::DeviceInfo(LPCTSTR enumarator)
{
	hDevInfo = SetupDiGetClassDevs(NULL, enumarator, NULL, DIGCF_ALLCLASSES | DIGCF_PRESENT);
}


DeviceInfo::~DeviceInfo()
{
}

multimap<string, string> DeviceInfo::getDeviceIdMap()
{
	return deviceIdMap;
}

multimap<string, string> DeviceInfo::getVendorIdMap()
{
	return vendorIdMap;
}

bool DeviceInfo::findDevices(iParser *parser)
{
	if (hDevInfo == INVALID_HANDLE_VALUE)
		return false;
	SP_DEVINFO_DATA DeviceInfoData;
	TCHAR szDeviceInstanceID[MAX_DEVICE_ID_LEN];
	CONFIGRET status;
	for (int i = 0; ; i++) {
		DeviceInfoData.cbSize = sizeof(DeviceInfoData);
		if (!SetupDiEnumDeviceInfo(hDevInfo, i, &DeviceInfoData))
			break;

		status = CM_Get_Device_ID(DeviceInfoData.DevInst, szDeviceInstanceID, MAX_PATH, 0);
		if (status != CR_SUCCESS)
			continue;
		string did = parser->getDID(wcharToString(szDeviceInstanceID));
		string vid = parser->getVID(wcharToString(szDeviceInstanceID));
		string vidText = parser->getVIDText(vid);
		string didText = parser->getDIDText(vid, did);
		deviceIdMap.insert(deviceIdMap.end(), { did, didText });
		vendorIdMap.insert(vendorIdMap.end(), { vid, vidText });
	}
	return true;
}

string DeviceInfo::wcharToString(LPCTSTR strW)
{
	wstring wStr = strW;
	string str = string(wStr.begin(), wStr.end());
	return str;
}