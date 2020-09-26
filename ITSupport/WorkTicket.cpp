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

