#pragma once
#include <windows.h>
#include <iostream>
using namespace std;

class iParser
{
public:
	virtual string getDID(string str) = 0;
	virtual string getVID(string str) = 0;
	virtual string getDIDText(string str) = 0;
	virtual string getVIDText(string str) = 0;
};

