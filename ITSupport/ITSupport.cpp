/* Student Name: Fleur Blanckaert, Gabriel Dietrich
   Student ID: 100747083, 100764733
   Date: 19th September, 2020
   Program: Lab1_Classes - OOP 3200
   Description: This is an application that creates a class called WorkTicket, which represents a
                a client's request for support.
*/ 

#include <iostream>     // for cin and cout
#include <iomanip> 		// for output formatting
#include <stdexcept>	// for invalid_argument
#include <string>		// for getline
#include "MyConsoleInput.h" // Provided by Tom Tsiliopoulous (For ConsoleInput::ReadInteger())
#include "WorkTicket.h"


using namespace std;

int main()
{
	//Declarations
	WorkTicket ticket[3];
	WorkTicket ticket1;
	int ticketInput;
	string clientInput;
	int dayInput;
	int monthInput;
	int yearInput;
	string descriptionInput;
	int i = 0;
	const int ARRAY_SIZE = 3;
	
	//Default Values
	cout << endl << "Ticket Number\t" << "Client ID\t" << "Work Ticket Date\t" << "Issue Description\t" << endl;
	cout << ticket1.ShowWorkTicket() << endl;


	//Output Header
	cout << endl << "IT Support Tracking Application" << endl
		<< "===============================" << endl << endl;

		while (i < ARRAY_SIZE)
		{
			try
			{

				cout << "Entry " << "[" << i + 1 << "]" << endl;
				//Prompts user to enter Work Ticket Number
				cout << "The Ticket Number is: ";
				ticketInput = MyConsoleInput::ReadInteger(1);


				//Prompts user for client id number
				cout << "The Client ID is: ";
				getline(cin, clientInput);


				//Prompts user for work ticket date
				cout << "The Work Ticket Date is: \nDay: ";
				dayInput = MyConsoleInput::ReadInteger(1, 31);

				cout << "Month: ";
				monthInput = MyConsoleInput::ReadInteger(1, 12);

				cout << "Year: ";
				yearInput = MyConsoleInput::ReadInteger(2000, 2099);

				//Prompts user for issue description
				cout << "The Issue Description is: ";
				getline(cin, descriptionInput);

				//Sets user Input
				ticket[i].SetWorkTicket(ticketInput, clientInput, dayInput, monthInput, yearInput, descriptionInput);
				cout << endl;

				i++;
			}
			catch (const invalid_argument& ex)
			{
				cerr << "\nException occurred: " << ex.what() << endl;
				
			}
		}
	
	//Displays output
	cout << endl << "Ticket Number\t" << "Client ID\t" << "Work Ticket Date\t" << "Issue Description\t" << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << ticket[i].ShowWorkTicket() << endl;
	}

	return 0;

}
