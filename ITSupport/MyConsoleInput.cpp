#include <iostream>
#include <iomanip>
#include <cmath>
#include <limits> // numeric_limits
#include <cfloat>  // for limits of a double DBL_MIN and DBL_MAX
#include <sstream> 		// stringstream

#include "MyConsoleInput.h"
using namespace std;


// ReadDouble function definition
double MyConsoleInput::ReadDouble(const double MIN, const double MAX)
{

	double validNumber = 0.0; // holds the user input

	cin >> validNumber;       // try to get input

	// remove any remaining characters from the buffer.
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

		if (cin.fail())            // if user input fails...
		{
			cin.clear(); // Reset the fail() state of the cin object.
			cin.sync();  // clear the buffer 
			cin.ignore();
			// report the problem to the user.
			throw invalid_argument("* Invalid input. Please try again and enter a numeric value.\n");
;
		}
		else if (validNumber < MIN || validNumber > MAX)// if value is outside range...
		{
			stringstream errorMessage;

			errorMessage << " * Invalid input. Please Enter a value between " << MIN << " and " << MAX << ". Redo Entry!.\n";
			
			// report the problem to the user.
			throw invalid_argument(errorMessage.str());
		}

		return validNumber; // returns a valid value to the calling function.

}

// ReadInteger function definition
int MyConsoleInput::ReadInteger(const int MIN, const int MAX)
{

	double validNumber = 0.0; // holds the user input

	validNumber = ReadDouble(MIN, MAX); // Get user input as a double

		// if(abs(validNumber - (int) validNumber) > 0.00000001) // Alternative
		if (validNumber > (int)validNumber)      // If user input is not a whole number
		{
			// report the problem to the user.
			throw invalid_argument(" * Invalid input. Please enter whole number. Redo Entry!\n");
		}
		return (int)validNumber; // returns a valid value to the calling function.

}