#pragma once

#include <vector>
#include <string>

#include "adress.h"
#include "to_string.h"

using namespace std;

struct Contacts
{
	vector<long long> phones;
	vector<string>    mails;
	Adress            adress;

	Contacts()
	{
	}

	Contacts(vector<string> phones, vector<string> mails, Adress adress)
	{
		for (auto i : phones)
		{
			this->phones.push_back(stoll(i));
		}

		this->mails  = mails;
		this->adress = adress;
	}

	string to_string(string sep = ";\n")
	{
		return ::to_string("Phone", phones) + sep + ::to_string("Mail", mails) + sep + adress.to_string() + sep;
	}

	string to_file()
	{
		return ::to_string(phones) + '"' + ::to_string(mails) + '"' + adress.to_file();
	}
};
