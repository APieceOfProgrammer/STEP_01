#pragma once

#include <iostream>

#include "spravochnik.h"

using namespace std;

std::string get_name()
{
	string firstName, secondName;
	cout << "---------------------\nType person's first name: ";
	cin >> firstName;

	cout << "Type person's second name: ";
	cin >> secondName;

	return firstName + " " + secondName;
}

Contacts& get_person()
{
	string name = get_name();

	Contacts& person = spravochnik.get(name);

	cout << "---------------------\nName: " << name << ";\n" << person.to_string();

	return person;
}

void set_phone(Contacts& person)
{
	long long phone;
	cout << "Type phone number: ";
	cin >> phone;

	person.phones.push_back(phone);
}

void set_mail(Contacts& person)
{
	std::string mail;
	cout << "Type mail: ";
	cin >> mail;

	person.mails.push_back(mail);
}

void set_adress(Contacts& person)
{
	std::string temp;
	cout << "Type street: ";
	cin >> temp;
	person.adress.street = temp;

	cout << "Type home: ";
	cin >> temp;
	person.adress.home = temp;
}
