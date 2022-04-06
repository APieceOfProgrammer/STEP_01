#pragma once

#include <string>
#include <vector>

using namespace std;

string to_string(string val)
{
	return val;
}

template<class type>
string to_string(string word, vector<type> val)
{
	if (val.size() == 0)
	{
		return "No " + word + 's';
	}

	string ret = word;

	if (val.size() > 1)
	{
		ret += 's';
	}

	ret += ": " + to_string(val[0]);

	for (auto i = val.begin() + 1; i != val.end(); i++)
	{
		ret += ", " + to_string(*i);
	}

	return ret;
}

template<class type>
string to_string(vector<type> val)
{
	if (val.size() == 0)
	{
		return "";
	}

	string ret = to_string(val[0]);

	for (auto i = val.begin() + 1; i != val.end(); i++)
	{
		ret += '\'' + to_string(*i);
	}

	return ret;
}
