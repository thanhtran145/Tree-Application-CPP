#pragma once
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

//PreCondition: spaces (boolean true or false)
//PostCondition: returns a string including space character(s) or without space character 
string inputString(string prompt, bool spaces)
{
	string input = "";

	cout << prompt;
	if (spaces)
		getline(cin, input);
	else
	{
		cin >> input;
		cin.clear();
		cin.ignore(999, '\n');
	}
	return input;
}

//PreCondition: valid string of options
//PostCondition: returns an uppercase  of the option (char)
char inputChar(string prompt, string options)
{
	char input;
	do
	{
		cout << prompt;
		if (!(cin >> input))
		{
			cout << "ERROR: Invalid input. Must be a character type.\n";
			cin.clear();
			cin.ignore(999, '\n');
		}
		else
		{
			bool found = false;
			for (int i = 0; i < options.length(); i++)
				if ((toupper(options.at(i))) == toupper(input))
				{
					found = true;
					break;
				}
			if (found)
			{
				cin.clear();
				cin.ignore(999, '\n');
				break;
			}
			else
				cout << "ERROR: Invalid input. Must be one of '" << options << "' character.\n";
		}
	} while (true);
	return toupper(input);
}

//PreCondition: valid yes (char) or no (char)
//PostCondition: returns an uppercase  yes (char) or no (char) 
char inputChar(string prompt, char yes, char no)
{
	char input;
	do
	{
		cout << prompt;
		if (!(cin >> input))
		{
			cout << "ERROR: Invalid input. Must be a character type.\n";
			cin.clear();
			cin.ignore(999, '\n');
		}
		else if (tolower(input) != tolower(yes) && tolower(input) != tolower(no))
			cout << "ERROR: Invalid input. Must be a '" << static_cast<char>(toupper(yes)) << "' or '" << static_cast<char>(toupper(no)) << "' character.\n";
		else
		{
			cin.clear();
			cin.ignore(999, '\n');
			break;
		}
	} while (true);
	return toupper(input);
}

//PreCondition: alphaOrDigit (boolean true or false)
//PostCondition: returns an alphabet or a digit character
char inputChar(string prompt, bool alphaOrDigit)
{
	char input;
	do
	{
		cout << prompt;
		if (!(cin >> input))
		{
			cout << "ERROR: Invalid input. Must be a character type.\n";
			cin.clear();
			cin.ignore(999, '\n');
		}
		else if (alphaOrDigit && !isalpha(input))
			cout << "ERROR: Invalid input. Must be an alphabet character.\n";
		else if (!alphaOrDigit && !isdigit(input))
			cout << "ERROR: Invalid input. Must be a digit character.\n";
		else
		{
			cin.clear();
			cin.ignore(999, '\n');
			break;
		}
	} while (true);
	return input;
}

//PreCondition: NA
//PostCondition: returns any character
char inputChar(string prompt)
{
	char input;
	do
	{
		cout << prompt;
		if (!(cin >> input))
		{
			cout << "ERROR: Invalid input. Must be a character type.\n";
			cin.clear();
			cin.ignore(999, '\n');
		}
		else
			break;
	} while (true);
	cin.clear();
	cin.ignore(999, '\n');
	return toupper(input);
}

//PreCondition: NA
//PostCondition: returns any integer value
int inputInteger(string prompt)
{
	int input;
	do
	{
		cout << prompt;
		if (!(cin >> input))
		{
			cout << "ERROR: Invalid input. Must be an integer type.\n";
			cin.clear();
			cin.ignore(999, '\n');
		}
		else
			break;
	} while (true);
	cin.clear();
	cin.ignore(999, '\n');
	return input;
}

//PreCondition: posNeg (boolean true or false)
//PostCondition: returns a positive integer value (posNeg = true) or a negative integer value (poseNeg = false)
int inputInteger(string prompt, bool posNeg)
{
	int input;
	do
	{
		cout << prompt;
		if (!(cin >> input))
		{
			cout << "ERROR: Invalid input. Must be an integer type.\n";
			cin.clear();
			cin.ignore(999, '\n');
		}
		else if (posNeg && input <= 0)
			cout << "ERROR: Invalid input. Must be a positive number.\n";
		else if (!posNeg && input >= 0)
			cout << "ERROR: Invalid input. Must be a negative number.\n";
		else
			break;
	} while (true);
	cin.clear();
	cin.ignore(999, '\n');
	return input;
}

//PreCondition: start (integer) and greater (boolean true or false)
//PostCondition: returns an integer value greater than start or lesser than start
int inputInteger(string prompt, int start, bool greater)
{
	int input;
	do
	{
		cout << prompt;
		if (!(cin >> input))
		{
			cout << "ERROR: Invalid input. Must be an integer type.\n";
			cin.clear();
			cin.ignore(999, '\n');
		}
		else if (greater && input < start)
			cout << "ERROR: Invalid input. Must be a greater than or equal to " << start << ".\n";
		else if (!greater && input > start)
			cout << "ERROR: Invalid input. Must be a lesser than or equal to " << start << ".\n";
		else
			break;
	} while (true);
	cin.clear();
	cin.ignore(999, '\n');
	return input;
}

//PreCondition: startRange (integer) and endRange (integer)
//PostCondition: returns an integer value within range (startRannge and endRange)
int inputInteger(string prompt, int startRange, int endRange)
{
	int input;
	do
	{
		cout << prompt;
		if (!(cin >> input))
		{
			cout << "ERROR: Invalid input. Must be an integer type.\n";
			cin.clear();
			cin.ignore(999, '\n');
		}
		else if (!(input >= min(startRange, endRange) && input <= max(startRange, endRange)))
			cout << "ERROR: Invalid input. Must be from " << startRange << ".." << endRange << ".\n";
		else
			break;
	} while (true);
	cin.clear();
	cin.ignore(999, '\n');
	return input;
}

//PreCondition: NA
//PostCondition: returns any double value
double inputDouble(string prompt)
{
	double input;
	do
	{
		cout << prompt;
		if (!(cin >> input))
		{
			cout << "ERROR: Invalid input. Must be a double type.\n";
			cin.clear();
			cin.ignore(999, '\n');
		}
		else
			break;
	} while (true);
	cin.clear();
	cin.ignore(999, '\n');
	return input;
}

//PreCondition: posNeg (boolean true or false)
//PostCondition: returns a positive double value (posNeg = true) or a negative double value (poseNeg = false)
double inputDouble(string prompt, bool posNeg)
{
	double input;
	do
	{
		cout << prompt;
		if (!(cin >> input))
		{
			cout << "ERROR: Invalid input. Must be a double type.\n";
			cin.clear();
			cin.ignore(999, '\n');
		}
		else if (posNeg && input <= 0.0)
			cout << "ERROR: Invalid input. Must be a positive number.\n";
		else if (!posNeg && input >= 0.0)
			cout << "ERROR: Invalid input. Must be a negative number.\n";
		else
			break;
	} while (true);
	cin.clear();
	cin.ignore(999, '\n');
	return input;
}

//PreCondition: start(integer) and greater(boolean true or false)
//PostCondition: returns an integer value greater than start or lesser than start
double inputDouble(string prompt, double start, bool posNeg)
{
	double input;
	do
	{
		cout << prompt;
		if (!(cin >> input))
		{
			cout << "ERROR: Invalid input. Must be a double type.\n";
			cin.clear();
			cin.ignore(999, '\n');
		}
		else if (posNeg && input <= start)
			cout << "ERROR: Invalid input. Must be greater than or equal to " << start << ".\n";
		else if (!posNeg && input >= start)
			cout << "ERROR: Invalid input. Must be lesser than or equal to " << start << ".\n";
		else
			break;
	} while (true);
	cin.clear();
	cin.ignore(999, '\n');
	return input;
}

//PreCondition: startRange (integer) and endRange (integer)
//PostCondition: returns an integer value within range (startRannge and endRange)
double inputDouble(string prompt, double startRange, double endRange)
{
	double input;
	do
	{
		cout << prompt;
		if (!(cin >> input))
		{
			cout << "ERROR: Invalid input. Must be a double type.\n";
			cin.clear();
			cin.ignore(999, '\n');
		}
		else if (!(input >= min(startRange, endRange) && input <= max(startRange, endRange)))
			cout << "ERROR: Invalid input. Must be from " << startRange << ".." << endRange << ".\n";
		else
			break;
	} while (true);
	cin.clear();
	cin.ignore(999, '\n');
	return input;
}

//PreCondition: a String prompt
//PostCondition: returns true if the answer is yes otherwise return false
bool inquire(string prompt)
{
	char input = inputChar(prompt, 'Y', 'N');
	if (input == 'Y')
		return true;
	else
		return false;
}
