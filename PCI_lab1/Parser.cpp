#include "Parser.h"


//Get DID from string like "PCI//....VEN_*VenID*&...DEV_*DevID*&..."
//didKey = "DEV_"
string Parser::getDID(string str)
{
	size_t pos = str.find(didKey) + didKey.size();
	string temp = str.substr(pos, str.length() - pos);
	return temp.substr(0, temp.find(separator));
}

//Get VID from string like "PCI//....VEN_*VenID*&..."
//vidKey = "VEN_"
string Parser::getVID(string str)
{
	size_t pos = str.find(vidKey) + vidKey.size();
	string temp = str.substr(pos, str.length() - pos);
	return temp.substr(0, temp.find(separator));
}

string Parser::getDIDText(string str)
{
	return string();
}

string Parser::getVIDText(string str)
{
	return string();
}
