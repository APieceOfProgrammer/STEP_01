#pragma once

#include <fstream>

#include "spravochnik.h"

using namespace std;

vector<string> parse(string str, string delimiter)
{
	int pos = 0;
	string token;
	vector<string> temp;

	while ((pos = str.find(delimiter)) != string::npos)
	{
		token = str.substr(0, pos);
		temp.push_back(token);
		str.erase(0, pos + delimiter.length());
	}
	temp.push_back(str);

	return temp;
}

void set_file(string name, string info)
{
	ofstream file(name);

	if (file.is_open())
	{
		file << info;
	}
}

void get_spravochnik(string name)
{
	ifstream file(name);
	std::string line;

	if (file.is_open())
	{
		getline(file, line);

		while (getline(file, line))
		{
			auto info = parse(line, "\"");
			auto adress = parse(info[3], "'");

			spravochnik.insert(info[0], Contacts(parse(info[1], "'"), parse(info[2], "'"), Adress(adress[0], adress[1])));
		}
	}
}
