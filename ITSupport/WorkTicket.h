#pragma once

#ifndef WORK_TICKET

#define WORK_TICKET

#include <string>

using namespace std;

class WorkTicket
{ 
public:

	//Default Constructor
	WorkTicket() : ticketNumber(0), clientId(""), ticketDay(1), ticketMonth(1), ticketYear(2000), issueDescription("") {}

	//Parameterized Constructor
	WorkTicket(int number, string id, int day, int month, int year, std::string description);

	//Accessors;
	int GetTicketNumber() const
	{
		return ticketNumber;
	}

	string GetClientId() const
	{
		return clientId;
	}
	int GetTicketDate() const { return ticketDay, ticketMonth, ticketYear; }
	string GetIssueDescription() const { return issueDescription; }

	//Accessor Method
	string ShowWorkTicket() const;

	// Mutators
	void SetTicketNumber(int number) { ticketNumber = number; }
	void SetClientID(string id) { clientId = id; }
	void SetTicketDate(int day, int month, int year) { ticketDay = day; ticketMonth = month; ticketYear = year; (ticketDay, ticketMonth, ticketYear); }
	void SetIssueDescription(string description) { issueDescription = description; }

	// Mutator Method
	bool SetWorkTicket(int number, string id, int day, int month, int year, string description);

	//Members will only be accessible inside the class
private:
	int ticketNumber;
	string clientId;
	int ticketDay;
	int ticketMonth;
	int ticketYear;
	string issueDescription;

	//Validates ticket number
	int ValidateNumber(int ticketNumber) const; // Double representing the validated value
	int ValidateDate(int ticketDay, int ticketMonth, int ticketYear) const; // Double representing the validated value

};

#endif /*Defined (WORK_TICKET) class*/

