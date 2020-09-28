/* Student Name: Fleur Blanckaert, Gabriel Dietrich
   Student ID: 100747083, 100764733
   Date: 25th September, 2020
   Program: Lab2_Classes - OOP 3200
   Description: This application creates a class called WorkTicket, which represents the client's
				request for IT support.	The class is copied into anew constructor. Later on, the
				application demonstrates the usability of the operators "==", "=", ">>", and "<<".
*/
#include "WorkTicket.h"
#include <iomanip>
#include <iostream>
#include <sstream> 		// stringstream
#include <string>		// for getline
#include <sstream> 		// stringstream

using namespace std;


//Parameterized Constructor for WorkTicket Class
WorkTicket::WorkTicket(int number, string id, int day, int month, int year, string description)
{
	ticketNumber = number;
	clientId = id;
	ticketDay = day;
	ticketMonth = month;
	ticketYear = year;
	issueDescription = description;
}

//Copy Constructor
WorkTicket::WorkTicket(const WorkTicket& copyTicket)
{
	ticketNumber = copyTicket.ticketNumber;
	clientId = copyTicket.clientId;
	ticketDay = copyTicket.ticketDay;
	ticketMonth = copyTicket.ticketMonth;
	ticketYear = copyTicket.ticketYear;
	issueDescription = copyTicket.issueDescription;

	// Testing puposes - Indicates if Copy constructor worked properly
	cout << endl << "A work ticket object was copied" << endl;
	cout << "Ticket Number\t" << "Client ID\t" << "Work Ticket Date\t" << "Issue Description\t" << endl;
}

//Conversion Operator
WorkTicket::operator string() const
{
	stringstream string;
	string << "Work Ticket # " << (ticketNumber)
		<< " - " << (clientId)
		<< " (" << (ticketDay) << "/" << setw(2) << (ticketMonth) << "/" << (ticketYear) << "): "
		<< (issueDescription);

	return string.str();
}

//Equality Operator 
bool WorkTicket::operator==(const WorkTicket& matchTicket) const
{

	if (GetTicketNumber() == matchTicket.GetTicketNumber() &&
		GetClientId() == matchTicket.GetClientId() &&
		GetTicketDate() == matchTicket.GetTicketDate() &&
		GetIssueDescription() == matchTicket.GetIssueDescription())
	{
		return true;
	}

}

//Assignment Operator
WorkTicket WorkTicket::operator=(const WorkTicket& newTicket)
{
	SetTicketNumber(newTicket.GetTicketNumber());
	SetClientID(newTicket.GetClientId());
	SetTicketDate(newTicket.ticketDay, newTicket.ticketMonth, newTicket.ticketYear);
	SetIssueDescription(newTicket.GetIssueDescription());

	cout << endl << "A work ticket object was assigned" << endl;
	return newTicket;
}

//Method to display user's Work Ticket Number
string WorkTicket::ShowWorkTicket() const
{
	stringstream string;

	string << (ticketNumber) << "\t\t" << (clientId) << "\t\t" << setw(2) << (ticketDay) <<
		"/" << setw(2) << (ticketMonth) << "/" << (ticketYear) << "\t\t" << (issueDescription);

	return string.str();
}

//Method to set user input
bool WorkTicket::SetWorkTicket(int number, string id, int day, int month, int year, string description)
{
	SetTicketNumber(number);
	SetClientID(id);
	SetTicketDate(day, month, year);
	SetIssueDescription(description);
	return true;

}

//Prompts user to enter attributes of WorkTicket
istream& operator>>(istream& in, WorkTicket& userInput)
{
	int MIN_AMOUNT = 1;
	int MAX_DAY = 31;
	int MAX_MONTH = 12;
	int MIN_YEAR = 2000;
	int MAX_YEAR = 2099;
	int i = 0;
	
	while (i < 1)
	{
		//Throws exception
		try
		{
			//Prompts user to enter a ticket number
			cout << "The Ticket Number is: ";
			while (true)
			{
				if (in.fail())            //if user input fails
				{
					in.clear(); // Reset the fail() 
					in.sync();  // clear the buffer 
					in.ignore();
				}

				in >> userInput.ticketNumber;
				if (userInput.ticketNumber < MIN_AMOUNT)
				{
					cout << "Please enter a positive whole number: ";
				}
				else
				{
					break;
				}

			}
			//Prompts user for client id number
			cout << "The Client ID is: ";
			in >> userInput.clientId;

			//Prompts user for work ticket date
			cout << "The Work Ticket Date is: \nDay: ";
			while (true)
			{
				in >> userInput.ticketDay;
				if (userInput.ticketDay < MIN_AMOUNT || userInput.ticketDay > MAX_DAY)
				{
					cout << "Please enter a number between " << MIN_AMOUNT << " and " << MAX_DAY << ": ";
				}
				else
				{
					break;
				}
			}

			cout << "Month: ";
			while (true)
			{
				in >> userInput.ticketMonth;
				if (userInput.ticketMonth < MIN_AMOUNT || userInput.ticketMonth > MAX_MONTH)
				{
					cout << "Please enter a number between " << MIN_AMOUNT << " and " << MAX_MONTH << ": ";
				}
				else
				{
					break;
				}
			}

			cout << "Year: ";
			while (true)
			{
				in >> userInput.ticketYear;
				if (userInput.ticketYear < MIN_YEAR || userInput.ticketYear > MAX_YEAR)
				{
					cout << "Please enter a number between " << MIN_YEAR << " and " << MAX_YEAR << ": ";
				}
				else
				{
					break;
				}
			}

			//Prompts user to enter description
			while(true)
			{
				getline(in, userInput.issueDescription);
				if (userInput.issueDescription == "")
				{
					cout << "The Issue Description is : ";
				}
				else
				{				
					break;
				}
			}

			//getline(in, userInput.issueDescription);
			//in >> userInput.issueDescription;

		}
		//Executes exception
		catch (const invalid_argument& ex)
		{
			cerr << "\nException occurred: " << ex.what() << endl;

		}
		return in;
	}
}

// Displays attributes entered by user
ostream& operator<<(ostream& out, const WorkTicket userOutput)
{
	out << userOutput.ShowWorkTicket();
	return out;
}