#include <iostream>

#include "spravochnik.h"
#include "utilites.h"
#include "cli.h"

using namespace std;

int main()
{
	/*spravochnik.insert("Dmitriy Gordeev", Contacts({80000000000, 70000000000}, {"a@mail.com"}, Adress("Street", "1")));
	spravochnik.insert("A AA",            Contacts({ 60000000000 },              { "b@com", "a"},  Adress("Prospect", "10B")));
	*/

	get_spravochnik("C:\\spravochnik.txt");

	bool isRunning = true;

	while (isRunning)
	{
		std::string command;

		cout << "---------------------\ns - print all spravochnik\np - print contacts of a person by first and last names\nc - change person's contacts\na - add person\n0 - exit\n";
		cin  >> command;

		switch (command[0])
		{
		case 's':
			cout << spravochnik.to_string();
			break;

		case 'p':
			get_person();
			break;

		case 'a':
		{
			Contacts contacts;
			std::string name = get_name();

			set_phone(contacts);
			set_mail(contacts);
			set_adress(contacts);

			spravochnik.insert(name, contacts);
			break;
		}

		case 'c':
		{
			Contacts& person = get_person();

			cout << "---------------------\np - change person's phone\nm - change person's mail\na - change person's address\n";
			cin >> command;

			switch (command[0])
			{
			case 'p':
				set_phone(person);
				break;

			case 'm':
				set_mail(person);
				break;

			case 'a':
				set_adress(person);
				break;

			default:
				cout << "Unknown command\n";
			}
			break;
		}

		case '0':
			isRunning = false;
			break;

		default:
			cout << "Unknown command\n";
		}
	}

	set_file("C:\\spravochnik.txt", spravochnik.to_file());
}
