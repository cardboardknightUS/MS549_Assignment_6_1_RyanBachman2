/*
	Ryan Bachman
	University of Advancing Technology
	MS549 - Data Structures and Testing
	Fall 2024, Grad 2

	Assignment 6.1 - Project - Hash Tables
	functions.cpp
*/

#include "functions.h"
#include "hashTable.h"

// Allows you to use iostream statements without the use of .
using namespace std;

// Outputs the main menu options to the user using only cout.
int mainMenu()
{
	cout << "\n\nRyan Bachman's Assignment 6.1 Project" << endl;
	cout << "1: Add a Key/Value Pair" << endl;
	cout << "2: Remove a Key/Value Pair" << endl;
	cout << "3: Retrieve a Key/Value Pair" << endl;
	cout << "4: Retrieve All Key/Value Pairs" << endl;
	cout << "5: Testing" << endl;
	cout << "6: Linear Probing Hash Table" << endl;
	cout << "7: Exit Program" << endl;

	return 0;
}

// Outputs the main menu options to the user using only cout.
int linearProbingMenu()
{
	cout << "\n\nLinear Probing Hash Table Menu" << endl;
	cout << "1: Add a Key/Value Pair" << endl;
	cout << "2: Remove a Key/Value Pair" << endl;
	cout << "3: Retrieve a Key/Value Pair" << endl;
	cout << "4: Retrieve All Key/Value Pairs" << endl;
	cout << "5: Add Maximum Values to test Linear Probing" << endl;
	cout << "6: Testing WITH Linear Probing" << endl;
	cout << "7: Main Menu" << endl;

	return 0;
}

// Generates a string of random alphanumeric characters with a length that the user can choose.
string generateRandom(const int len)
{
	static const char alphanumeric[] =
		"0123456789"
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		"abcdefghijklmnopqrstuvwxyz";

	string tmp_s;
	tmp_s.reserve(len);

	for (int i = 0; i < len; ++i)
	{
		tmp_s += alphanumeric[rand() % (sizeof(alphanumeric) - 1)];
	}

	return tmp_s;
}

// Get the time when the function is called for start time.
chrono::high_resolution_clock::time_point getStartTime()
{
	// Code for a HIGH RESOLUTION timing.
	auto startHigh = chrono::high_resolution_clock::now();

	return startHigh;
}

// Get the time when the function is called for end time.
chrono::high_resolution_clock::time_point getEndTime()
{
	// Code for a HIGH RESOLUTION timing.
	auto endHigh = chrono::high_resolution_clock::now();

	return endHigh;
}

// Calculate the time elapsed between getStartTime() and getEndTime() so this can be reused anywhere.
chrono::duration<double> elapsedTime(chrono::high_resolution_clock::time_point startHigh, chrono::high_resolution_clock::time_point endHigh)
{
	chrono::duration<double> elapsedHighRes = endHigh - startHigh;

	cout << fixed << setprecision(5) << "The operation took " << elapsedHighRes.count() << " seconds.\n" << endl;

	return elapsedHighRes;
}

// Output the results in a pretty format to the user.
void getResults(chrono::duration<double> htInsertTime100, chrono::duration<double> htInsertTime1000, chrono::duration<double> htInsertTime10000, chrono::duration<double> htInsertTime100000)
{
	cout << "----------------------------------------------------------------------------------------------------------------" << endl;
	cout << "|                                           R   E   S   U   L   T   S                                          |" << endl;
	cout << "----------------------------------------------------------------------------------------------------------------" << endl;
	cout << "| Additions            | 100                 | 1,000             | 10,000             | 100,000                |" << endl;
	cout << "----------------------------------------------------------------------------------------------------------------" << endl;
	cout << "| Insert Runtime       | " << htInsertTime100.count() << "             | " << htInsertTime1000.count() << "           | " << htInsertTime10000.count() << "            | " << htInsertTime100000.count() << "                |" << endl;
	cout << "----------------------------------------------------------------------------------------------------------------" << endl;
}