/* Student Name: Fleur Blanckaert, Gabriel Dietrich
   Student ID: 100747083, 100764733
   Date: 25th September, 2020
   Program: Lab2_Classes - OOP 3200
   Description: 
*/ 

#include <iostream>     // for cin and cout
#include <iomanip> 		// for output formatting
#include <sstream>
#include <stdexcept>	// for invalid_argument
#include <string>		// for getline
#include "MyConsoleInput.h" // Provided by Tom Tsiliopoulous (For ConsoleInput::ReadInteger())
#include "WorkTicket.h"


using namespace std;

int main()
{
	//Declarations
	WorkTicket ticket[3];
	int ticketInput;
	string clientInput;
	int dayInput;
	int monthInput;
	int yearInput;
	string descriptionInput;
	int i = 0;
	const int ARRAY_SIZE = 3;

	//Created two work ticket objects and initialized ticket 2 data members to ticket 1 values
	WorkTicket ticket1(1, "CA100", 02, 12, 2020, "Laptop needs to be rebooted");
	WorkTicket ticket2 = ticket1;

	//Demonstrating the copy constructor
	cout << endl << "Ticket Number\t" << "Client ID\t" << "Work Ticket Date\t" << "Issue Description\t" << endl;
	cout << ticket1.ShowWorkTicket() << endl
		 << ticket2.ShowWorkTicket() << endl;

	//Demonstrating the conversion operator
	string ticket3;

	ticket3 = string(ticket1);
	cout << endl <<"The ticket now looks like " << ticket3 << endl;

	//Demonstrating the equality operator
	cout << endl << "Ticket 1: " << ticket1.ShowWorkTicket();
	cout << endl << "Ticket 2: " << ticket2.ShowWorkTicket() << endl;
	cout << endl << "Does ticket 1 match ticket 2? " << (ticket1 == ticket2) << endl;

	//Demonstrating assignment operator
	WorkTicket ticket4; //For testing purposes
	ticket1 = ticket4;
	
	cout << endl << "Ticket 1: " << ticket1.ShowWorkTicket();
	cout << endl << "Ticket 2: " << ticket4.ShowWorkTicket() << endl;
	
	cout << endl << "Ticket 1 should now have the value of ticket 4 (default constructor) " << ticket1.ShowWorkTicket() << endl;

	//Demonstration cout with userInput
	WorkTicket ticket5;

	//Create and call a validate function on ticket5
		cin >> ticket5;
		cout << ticket5;

		
	//Output Header
	//cout << endl << "IT Support Tracking Application" << endl
	//	<< "===============================" << endl << endl;

	//	while (i < ARRAY_SIZE)
	//	{
	//		try
	//		{

	//			cout << "Entry " << "[" << i + 1 << "]" << endl;
	//			//Prompts user to enter Work Ticket Number
	//			cout << "The Ticket Number is: ";
	//			ticketInput = MyConsoleInput::ReadInteger(1);

	//			//Prompts user for client id number
	//			cout << "The Client ID is: ";
	//			getline(cin, clientInput);

	//			//Prompts user for work ticket date
	//			cout << "The Work Ticket Date is: \nDay: ";
	//			dayInput = MyConsoleInput::ReadInteger(1, 31);

	//			cout << "Month: ";
	//			monthInput = MyConsoleInput::ReadInteger(1, 12);

	//			cout << "Year: ";
	//			yearInput = MyConsoleInput::ReadInteger(2000, 2099);

	//			//Prompts user for issue description
	//			cout << "The Issue Description is: ";
	//			getline(cin, descriptionInput);

	//			//Sets user Input
	//			ticket[i].SetWorkTicket(ticketInput, clientInput, dayInput, monthInput, yearInput, descriptionInput);
	//			cout << endl;

	//			//Display copy Constructor

	//			
	//			i++;
	//		}
	//		catch (const invalid_argument& ex)
	//		{
	//			cerr << "\nException occurred: " << ex.what() << endl;
	//			
	//		}
	//	}
	
	////Displays output
	//cout << endl << "Ticket Number\t" << "Client ID\t" << "Work Ticket Date\t" << "Issue Description\t" << endl;
	//for (int i = 0; i < 3; i++)
	//{
	//	cout << ticket[i].ShowWorkTicket() << endl;
	//}

	return 0;

}
