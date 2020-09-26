#include "WorkTicket.h"


#include <iomanip>
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

//Method to display user's Work Ticket Number
string WorkTicket::ShowWorkTicket() const
{
	stringstream string;

	string << (ticketNumber) << "\t\t" << (clientId) << "\t\t" << setw(2) << (ticketDay) << "/" << setw(2) << (ticketMonth) << "/" << (ticketYear) << "\t\t"
		<< (issueDescription);

	return string.str();
}

bool WorkTicket::SetWorkTicket(int number, string id, int day, int month, int year, string description)
{

	SetTicketNumber(number);
	SetClientID(id);
	SetTicketDate(day, month, year);
	SetIssueDescription(description);
	return true;

}

