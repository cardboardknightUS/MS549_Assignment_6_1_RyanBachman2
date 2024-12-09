/*
	Ryan Bachman
	University of Advancing Technology
	MS549 - Data Structures and Testing
	Fall 2024, Grad 2

	Assignment 6.1 - Project - Hash Tables
	functions.h
*/

#pragma once
#include <iostream>
#include <chrono>
#include <iomanip>
#include <vector>

// Allows you to use iostream statements without the use of .
using namespace std;

int mainMenu();

int linearProbingMenu();

string generateRandom(const int len);

chrono::high_resolution_clock::time_point getStartTime();

chrono::high_resolution_clock::time_point getEndTime();

chrono::duration<double> elapsedTime(chrono::high_resolution_clock::time_point startHigh, chrono::high_resolution_clock::time_point endHigh);

void getResults(chrono::duration<double> htInsertTime100, chrono::duration<double> htInsertTime1000, chrono::duration<double> htInsertTime10000, chrono::duration<double> htInsertTime100000);