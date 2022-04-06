#pragma once

#include <map>
#include <string>

#include "contacts.h"

using namespace std;

struct Spravochnik
{
	map<string, Contacts> spravochnik;

	void insert(string key, Contacts value)
	{
		spravochnik.insert(pair<string, Contacts>(key, value));
	}

	Contacts& get(string key)
	{
		return spravochnik[key];
	}

	string to_string(string sep = "---------------------\n", string sep_info = ";\n")
	{
		if (spravochnik.size() == 0)
		{
			return "No info";
		}

		string ret;

		for (auto i : spravochnik)
		{
			ret += sep + "FIO: " + i.first + sep_info + i.second.to_string(sep_info);
		}

		return ret;
	}

	string to_file()
	{
		string ret;

		for (auto i : spravochnik)
		{
			ret += '\n' + i.first + '"' + i.second.to_file();
		}

		return ret;
	}
};

Spravochnik spravochnik;
