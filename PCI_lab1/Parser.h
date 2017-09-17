#pragma once
#include "iParser.h"
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std; 
class Parser : public iParser
{
private:
	string vidKey = "VEN_";
	string separator = "&";
	string didKey = "DEV_";
	string fileName = "base.txt";
public:

	// from iParser
	virtual string getDID(string str) override;
	virtual string getVID(string str) override;
	//winapi doesn't produce accurate txt form for vendorID and deviceID, so that's why we use file with base "base.txt".
	virtual string getDIDText(string strV, string strD) override;
	virtual string getVIDText(string str) override;
};

