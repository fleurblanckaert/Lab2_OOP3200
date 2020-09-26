/* Student Name: Fleur Blanckaert, Gabriel Dietrich
   Student ID: 100747083, 100764733
   Date: 25th September, 2020
   Program: Lab2_Classes - OOP 3200
   Description:
*/
#include "WorkTicket.h"
#include <iomanip>
#include <iostream>
#include <sstream> 		// stringstream
#include <string>		// for getline
#include <sstream> 		// stringstream

#include "MyConsoleInput.h"

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

	cout << endl << "A work ticket object was copied" << endl;
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

	string << (ticketNumber) << "\t\t" << (clientId) << "\t\t" << setw(2) << (ticketDay) << "/" << setw(2) << (ticketMonth) << "/" << (ticketYear) << "\t\t"
		<< (issueDescription);

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

istream& operator>>(istream& in, WorkTicket& userInput)
{
	int i = 0;
	while (i<1)
	{
		
		cout << "The Ticket Number is: ";
		in >> userInput.ticketNumber;

		//Prompts user for client id number
		cout << "The Client ID is: ";
		in >> userInput.clientId;

		//Prompts user for work ticket date
		cout << "The Work Ticket Date is: \nDay: ";
		in >> userInput.ticketDay;

		cout << "Month: ";
		in >> userInput.ticketMonth;

		cout << "Year: ";
		in >> userInput.ticketYear;

		cout << "The Issue Description is: ";
		in >> userInput.issueDescription;
		return in;
		
	} 

	
		
}

ostream& operator<<(ostream& out, const WorkTicket userInput)
{
	
		out << userInput.ShowWorkTicket();
		return out;

}
