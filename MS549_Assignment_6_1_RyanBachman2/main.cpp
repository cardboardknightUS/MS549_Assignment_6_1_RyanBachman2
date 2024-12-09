/*
	Ryan Bachman
	University of Advancing Technology
	MS549 - Data Structures and Testing
	Fall 2024, Grad 2

	Assignment 6.1 - Project - Hash Tables
	main.cpp
*/

#include "functions.h"
#include "hashTable.h"

// Allows you to use iostream statements without the use of .
using namespace std;

// This assignment will be used to show understanding of hash tables by allowing inserts, deletions and retrieval of hash value pairs.
// There will also be a troubleshooting section for timing insertions and deletions for hash tables.
int main()
{
	bool programLoop = true; // Set a variable for looping the program.
	HashTable<int, string> ht;
	int key = 0;
	int testKey = 0;

	// Begin FULL program loop...
	while (programLoop == true)
	{
		int menuChoice;

		mainMenu(); // Output main menu to the user.

		cout << "Please select a menu item (1 through 7): ";
		cin >> menuChoice; // Get input from the user for going through the main menu.
		cout << endl;

		if (menuChoice == 1) // Add a key-value pair to the hash table.
		{
			string userInput;

			cout << "Please enter a value to add to the Key Table: ";
			cin >> userInput;
			cout << endl;

			ht.add(key, userInput);
			key++;
		}
		else if (menuChoice == 2) // Remove a key-value pair from the hash table.
		{
			string userInput;

			cout << "Please enter a value to remove from the Key Table: ";
			cin >> userInput;
			cout << endl;

			try
			{
				ht.remove(userInput);
			}
			catch (const exception& e)
			{
				cerr << e.what() << endl;
			}
		}
		else if (menuChoice == 3) // Search for a specific value housed in the hash table and return the key for that value if it's found.
		{
			string userInput;

			cout << "Please enter a value to retrieve from the Key Table: ";
			cin >> userInput;
			cout << endl;

			try
			{
				auto result = ht.getByValue(userInput);
				cout << "The value of " << userInput << " is associated with Key: " << result.first << endl;
			}
			catch (const exception& e)
			{
				cerr << e.what() << endl;
			}

		}
		else if (menuChoice == 4) // Return all of the key-value pairs in the hash table, in order.
		{
			cout << "All key-value pairs:" << endl;

			for (const auto& pair : ht.getAll())
			{
				cout << "Key: " << pair.first << ", Value: " << pair.second << endl;
			}
		}
		else if (menuChoice == 5) // Testing Area
		{
			// BEGIN TESTING PROTOCOLS FOR ADDING N ELEMENTS TO THE HASH TABLE AND RETURN TIMING DETAILS.
			// HASH TABLE INSERTS
			// HASH TABLE TIMING FOR 100 ELEMENTS
			HashTable<int, string> ht100;

			cout << "Inserting 100 elements into the Hash Table..." << endl;

			// Get the start time to get algorithm time calculations.
			chrono::high_resolution_clock::time_point startTime = getStartTime();

			// Loop through the Hash Table 100 times.
			for (int i = 0; i < 100; i++)
			{
				ht100.add(testKey, generateRandom(12));
				++testKey;
			}

			// Get the end time to get algorithm time calculations.
			chrono::high_resolution_clock::time_point endTime = getEndTime();

			cout << "100 elements inserted into the Hash Table..." << endl;

			// Print out elapsed time to the user.
			chrono::duration<double> htInsertTime100 = elapsedTime(startTime, endTime);

			// HASH TABLE TIMING FOR 1,000 ELEMENTS
			HashTable<int, string> ht1000;

			cout << "\nInserting 1,000 elements into the Hash Table..." << endl;

			// Get the start time to get algorithm time calculations.
			startTime = getStartTime();

			testKey = 0;

			// Loop through the Hash Table 1,000 times.
			for (int i = 0; i < 1000; i++)
			{
				ht1000.add(testKey, generateRandom(12));
				++testKey;
			}

			// Get the end time to get algorithm time calculations.
			endTime = getEndTime();

			cout << "1,000 elements inserted into the Hash Table..." << endl;

			// Print out elapsed time to the user.
			chrono::duration<double> htInsertTime1000 = elapsedTime(startTime, endTime);

			// BST TIMING FOR 10,000 ELEMENTS
			HashTable<int, string> ht10000;

			cout << "\nInserting 10,000 elements into the Hash Table..." << endl;

			// Get the start time to get algorithm time calculations.
			startTime = getStartTime();

			testKey = 0;

			// Loop through the Hash Table 10,000 times.
			for (int i = 0; i < 10000; i++)
			{
				ht10000.add(testKey, generateRandom(12));
				++testKey;
			}

			// Get the end time to get algorithm time calculations.
			endTime = getEndTime();

			cout << "10,000 elements inserted into the Hash Table..." << endl;

			// Print out elapsed time to the user.
			chrono::duration<double> htInsertTime10000 = elapsedTime(startTime, endTime);

			// BST TIMING FOR 100,000 ELEMENTS
			HashTable<int, string> ht100000;

			cout << "\nInserting 100,000 elements into the Hash Table..." << endl;

			// Get the start time to get algorithm time calculations.
			startTime = getStartTime();

			testKey = 0;

			// Loop through the Hash Table 100,000 times.
			for (int i = 0; i < 100000; i++)
			{
				ht1000.add(testKey, generateRandom(12));
				++testKey;
			}

			// Get the end time to get algorithm time calculations.
			endTime = getEndTime();

			cout << "100,000 elements inserted into the Hash Table..." << endl;

			// Print out elapsed time to the user.
			chrono::duration<double> htInsertTime100000 = elapsedTime(startTime, endTime);
			// END OF HASH TABLE INSERTS

			getResults(htInsertTime100, htInsertTime1000, htInsertTime10000, htInsertTime100000);
		}
		else if (menuChoice == 6) // Open the Linear Probing hashing table menu with additional features.
		{
			bool linearProbingLoop = true; // Set a variable for looping the program.
			HashTable<int, string> htlp; // Create the linear probing hash table to be used in this menu.
			int lpKey = 0;
			int lpTestKey = 0;
			
			// Begin Linear Probing Hash Table program loop...
			while (linearProbingLoop == true)
			{
				int linearProbingMenuChoice;

				linearProbingMenu();

				cout << "Please select a menu item (1 through 7): ";
				cin >> linearProbingMenuChoice; // Get input from the user for going through the linear probing menu.
				cout << endl;

				if (linearProbingMenuChoice == 1) // Add a key-value pair to the linear probing hash table.
				{
					string userInput;

					cout << "Please enter a value to add to the Key Table: ";
					cin >> userInput;
					cout << endl;

					htlp.add(lpKey, userInput);
					lpKey++;
				}
				else if (linearProbingMenuChoice == 2) // Remove a key-value pair from the linear probing hash table.
				{
					string userInput;

					cout << "Please enter a value to remove from the Key Table: ";
					cin >> userInput;
					cout << endl;

					try
					{
						htlp.remove(userInput);
					}
					catch (const exception& e)
					{
						cerr << e.what() << endl;
					}
				}
				else if (linearProbingMenuChoice == 3) // Search for a specific value housed in the linear probing hash table and return the key for that value if it's found.
				{
					string userInput;

					cout << "Please enter a value to retrieve from the Key Table: ";
					cin >> userInput;
					cout << endl;

					try
					{
						auto result = htlp.getByValue(userInput);
						cout << "The value of " << userInput << " is associated with Key: " << result.first << endl;
					}
					catch (const exception& e)
					{
						cerr << e.what() << endl;
					}

				}
				else if (linearProbingMenuChoice == 4) // Return all of the key-value pairs in the linear probing hash table, in order.
				{
					cout << "All key-value pairs:" << endl;

					for (const auto& pair : htlp.getAll())
					{
						cout << "Key: " << pair.first << ", Value: " << pair.second << endl;
					}
				}
				else if (linearProbingMenuChoice == 5) // Add 102 elements to a linear probing hash table with a size of 101 elements to see if linear probing is working as expected.
				{
					cout << "Inserting 102 elements into the Linear Probing Hash Table..." << endl;

					// Get the start time to get algorithm time calculations.
					chrono::high_resolution_clock::time_point startTime = getStartTime();

					// Loop through the Hash Table 102 times to force linear probing.
					for (int i = 0; i < 103; i++)
					{
						htlp.add(testKey, generateRandom(12));
						++testKey;
					}

					// Get the end time to get algorithm time calculations.
					chrono::high_resolution_clock::time_point endTime = getEndTime();

					cout << "102 elements inserted into the Hash Table..." << endl;
					cout << "The default size of the hash table for testing linear probing is 101 elements so this means linear probing is working as expected!" << endl;

					// Print out elapsed time to the user.
					chrono::duration<double> bstInsertTime100 = elapsedTime(startTime, endTime);
				}
				else if (linearProbingMenuChoice == 6) // Testing Area
				{
					// BEGIN TESTING PROTOCOLS FOR ADDING N ELEMENTS TO THE LINEAR PROBING HASH TABLE AND RETURN TIMING DETAILS.
					// LINEAR PROBING HASH TABLE INSERTS
					// LINEAR PROBING HASH TABLE TIMING FOR 100 ELEMENTS
					HashTable<int, string> ht100;

					cout << "Inserting 100 elements into the Linear Probing Hash Table..." << endl;

					// Get the start time to get algorithm time calculations.
					chrono::high_resolution_clock::time_point startTime = getStartTime();

					// Loop through the Hash Table 100 times.
					for (int i = 0; i < 100; i++)
					{
						ht100.add(testKey, generateRandom(12));
						++testKey;
					}

					// Get the end time to get algorithm time calculations.
					chrono::high_resolution_clock::time_point endTime = getEndTime();

					cout << "100 elements inserted into the Linear Probing Hash Table..." << endl;

					// Print out elapsed time to the user.
					chrono::duration<double> htInsertTime100 = elapsedTime(startTime, endTime);

					// HASH TABLE TIMING FOR 1,000 ELEMENTS
					HashTable<int, string> ht1000;

					cout << "\nInserting 1,000 elements into the Linear Probing Hash Table..." << endl;

					// Get the start time to get algorithm time calculations.
					startTime = getStartTime();

					testKey = 0;

					// Loop through the Hash Table 1,000 times.
					for (int i = 0; i < 1000; i++)
					{
						ht1000.add(testKey, generateRandom(12));
						++testKey;
					}

					// Get the end time to get algorithm time calculations.
					endTime = getEndTime();

					cout << "1,000 elements inserted into the Linear Probing Hash Table..." << endl;

					// Print out elapsed time to the user.
					chrono::duration<double> htInsertTime1000 = elapsedTime(startTime, endTime);

					// BST TIMING FOR 10,000 ELEMENTS
					HashTable<int, string> ht10000;

					cout << "\nInserting 10,000 elements into the Linear Probing Hash Table..." << endl;

					// Get the start time to get algorithm time calculations.
					startTime = getStartTime();

					testKey = 0;

					// Loop through the Hash Table 10,000 times.
					for (int i = 0; i < 10000; i++)
					{
						ht10000.add(testKey, generateRandom(12));
						++testKey;
					}

					// Get the end time to get algorithm time calculations.
					endTime = getEndTime();

					cout << "10,000 elements inserted into the Linear Probing Hash Table..." << endl;

					// Print out elapsed time to the user.
					chrono::duration<double> htInsertTime10000 = elapsedTime(startTime, endTime);

					// BST TIMING FOR 100,000 ELEMENTS
					HashTable<int, string> ht100000;

					cout << "\nInserting 100,000 elements into the Linear Probing Hash Table..." << endl;

					// Get the start time to get algorithm time calculations.
					startTime = getStartTime();

					testKey = 0;

					// Loop through the Hash Table 100,000 times.
					for (int i = 0; i < 100000; i++)
					{
						ht1000.add(testKey, generateRandom(12));
						++testKey;
					}

					// Get the end time to get algorithm time calculations.
					endTime = getEndTime();

					cout << "100,000 elements inserted into the Linear Probing Hash Table..." << endl;

					// Print out elapsed time to the user.
					chrono::duration<double> htInsertTime100000 = elapsedTime(startTime, endTime);
					// END OF HASH TABLE INSERTS

					getResults(htInsertTime100, htInsertTime1000, htInsertTime10000, htInsertTime100000);
				}
				else if (linearProbingMenuChoice == 7) // End the linear probing menu loop and go back to the main menu.
				{
					linearProbingLoop = false;
				}
			}
		}
		else if (menuChoice == 7) // Close the program.
		{
			return 0;
		}
		else
		{
			cout << "Please enter a valid number from 1 to 7.\n" << endl;
		}
	} // ... End FULL program loop.

	cout << "\n" << endl;
	system("pause");
	return 0;
}