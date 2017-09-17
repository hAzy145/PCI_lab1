#include "Parser.h"


//Get DID from string "PCI//....VEN_*VenID*&...DEV_*DevID*&..."
//didKey = "DEV_"
string Parser::getDID(string str)
{
	size_t pos = str.find(didKey) + didKey.size();
	string temp = str.substr(pos, str.length() - pos);
	string result = temp.substr(0, temp.find(separator));
	transform(result.begin(), result.end(), result.begin(), ::tolower);
	return result;
}

//Get VID from string "PCI//....VEN_*VenID*&..."
//vidKey = "VEN_"
string Parser::getVID(string str)
{
	size_t pos = str.find(vidKey) + vidKey.size();
	string temp = str.substr(pos, str.length() - pos);
	string result = temp.substr(0, temp.find(separator));
	transform(result.begin(), result.end(), result.begin(), ::tolower);
	return result;
}

string Parser::getDIDText(string strV, string strD)
{
	//in our file vendor ids starts with new line, device ids - with tabulation
	strD.insert(strD.begin(), '\t');
	strV.insert(strV.begin(), '\n');
	ifstream ifs(fileName);
	if (!ifs.is_open())
		return string("No such file(""base.txt"")");
	//get size of file
	ifs.seekg(0, ios::end);
	streamsize size = ifs.tellg();
	ifs.seekg(0, ios::beg);

	//create buffer for data of file
	vector<char> buffer(size);
	ifs.read(buffer.data(), size);
	//find VID
	vector<char>::iterator found = search(buffer.begin(), buffer.end(), strV.begin(), strV.end());
	//find DID
	vector<char>::iterator found2 = search(found, buffer.end(), strD.begin(), strD.end());
	if (found == buffer.end() || found2 == buffer.end())
		return string("Can't find VID/PID in database.");
	found2 += strD.length();
	while (*found2._Ptr == ' ')
		found2++;
	//DID text form ends with \n
	string result;
	while (*found2._Ptr != '\n')
	{
		result.push_back(*found2._Ptr);
		found2++;
	}
	ifs.clear();
	ifs.close();
	return result;
}

string Parser::getVIDText(string str)
{
	//vendor starts with new line
	str.insert(str.begin(), '\n');
	ifstream ifs(fileName);
	if (!ifs.is_open())
		return string("No such file(""base.txt"")");
	ifs.seekg(0, ios::end);
	streamsize size = ifs.tellg();
	ifs.seekg(0, ios::beg);

	vector<char> buffer(size);
	ifs.read(buffer.data(), size);
	vector<char>::iterator found = search(buffer.begin(), buffer.end(), str.begin(), str.end());
	if (found == buffer.end())
		return string("Can't find VID/PID in database.");
	found += str.length();
	while (*found._Ptr == ' ')
		found++;
	string result;
	while (*found._Ptr != '\n')
	{
		result.push_back(*found._Ptr);
		found++;
	}
	ifs.clear();
	ifs.close();
	return result;
}
