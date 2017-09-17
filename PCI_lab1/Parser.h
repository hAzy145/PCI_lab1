#pragma once
#include "iParser.h"
class Parser : public iParser
{
public:

	// from iParser
	virtual string getDID(string str) override;
	virtual string getVID(string str) override;
	virtual string getDIDText(string str) override;
	virtual string getVIDText(string str) override;
};

