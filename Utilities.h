/*========================================================================================
	Object Oriented Programming COCS2131 - Assignment 2 - Library system
	@author       : Nguyen Hoang Giang
	student Number: s3090347
	instructor    : Barend Scholtus
	Date          : 20/09/2005

  ========================================================================================
*/
#ifndef UTILITIES_H
#define UTILITIES_H

#include <string>
#include <iostream>
#include <cctype>
#include <sstream>
#include <fstream>
#include <ctime>
#include "Book.h"

using namespace std;

/*
Definition of the Utilites class
*/
class Utilities
{
private:
	template<typename T>

	static T convertTo(const string& str, T& toT)
	{
		istringstream(str) >> toT;
		return toT;
	}

public:	
	static string readString(istream&, int, string);
	static bool readInt(istream&, int&, string);
	static bool readDouble(istream&, double&, string);
	static bool readBool(istream&, string, char, char);
	static int readStringOptions(istream&, int, const string[]);	
	
	static struct tm getCurrentDate();
	static string dateToString(struct tm);
	static void writeString(string, ofstream&);
	static string readFileString(ifstream&, int);
};


#endif
