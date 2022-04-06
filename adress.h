#pragma once

#include <string>

using namespace std;

struct Adress
{
	string street;
	string home;

	Adress()
	{
	}

	Adress(string street, string home)
	{
		this->street = street;
		this->home = home;
	}

	string to_string()
	{
		return "Adress: " + street + ", " + home;
	}

	string to_file()
	{
		return street + '\'' + home;
	}
};