#pragma once
#include <windows.h>

class iParser
{
public:
	virtual LPCTSTR getDID(LPCTSTR str) = 0;
	virtual LPCTSTR getVID(LPCTSTR str) = 0;
	virtual LPCTSTR getDIDText(LPCTSTR str) = 0;
	virtual LPCTSTR getVIDText(LPCTSTR str) = 0;
};

