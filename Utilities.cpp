/*========================================================================================
	Object Oriented Programming COCS2131 - Assignment 2 - Library system
	@author       : Nguyen Hoang Giang
	student Number: s3090347
	instructor    : Barend Scholtus
	Date          : 20/09/2005

  ========================================================================================
*/
#include "Utilities.h"

/*
read a string from input with a maximum length
*/
string Utilities::readString(istream& is, int maxLength, string prompt)
{
   string s;
   
   cout << prompt << ": ";   
   while(true)
   {
      getline(is ,s);
      if(s.length() >= maxLength)
      {         
         cerr << "Exceed maximum length!\n";
         cout << "Please re-enter\n" << prompt << ": ";
		 continue;
      }
      break;
   }
   return s;
}

/*
read an option from a list
return the selected option
*/
int Utilities::readStringOptions(istream& is, int numOfOptions, const string options[])
{
	int choice;
	
	cout << "Choose one of these options" << endl;
	for(int i = 0; i < numOfOptions; ++i)
	{
		cout << setiosflags(ios::fixed) << i + 1 << ")" << options[i] << '\n';
	}
	while(true)
	{
		if(readInt(is, choice, "Choice"))
		{
			if(choice > 0 && choice <= numOfOptions)
			{
				break;
			}
			cout << "Wrong choice!" << endl;
		}
	}
	return choice-1;
}

/*
read an integer, max length is 9
*/
bool Utilities::readInt(istream& is, int& value, string prompt)
{
	string s = readString(is, 10, prompt);
	const char* p = s.c_str();
	char c;
	
	for(int i = 0; i < s.length(); ++i)
    {
        if(!isdigit(c=*(p+i)))
        {
            if(i || c != '-')
			{
				return false;
			}
		}
	}

	convertTo(s, value);
	
	return true;
}

/*
read a double, max length is 9
*/
bool Utilities::readDouble(istream& is, double& value, string prompt)
{
	string s = readString(is, 10, prompt);
	const char *p = s.c_str();
	char c;
	int dotFlag = 0;

	for(int i = 0; i < s.length(); ++i)
	{
		if(!isdigit(c=*(p+i)))
		{
			if(((i || c != '-') && c != '.') || (c == '.' && dotFlag))
			{
				return false;
			}
			if(c == '.')
				dotFlag = 1;
		}		
	}
	convertTo(s, value);
	   
	return true;
}

/*
read a boolean
*/
bool Utilities::readBool(istream& is, string prompt, char t, char f)
{
	string userInput = readString(is,2, prompt);
	char userChoice = userInput[0];

	if(userChoice == t)
	{
		return true;
	}
	else if(userChoice == f)
	{
		return false;
	}
	cout << "Wrong input!\nPlease re-enter" << endl;

	return readBool(is, prompt, t, f);
}

struct tm Utilities::getCurrentDate()
{
	time_t now = time(NULL);
	struct tm *currentDate = localtime(&now);
			
	return *currentDate;
}

/*
Convert a date in struct tm to string
*/
string Utilities::dateToString(struct tm date)
{
	time_t now = mktime(&date);
	string tmp = ctime(&now);
	return tmp.substr(0, tmp.length() - 1);
}

/*
write a string to end of a file
*/
void Utilities::writeString(string s, ofstream& of)
{
	for(int i = 0; i < s.length(); i++)
	{
		of.put(s[i]);
	}
}

/*
Read a line from a file provide its line number
*/
string Utilities::readFileString(ifstream& ifs, int pos)
{
	ostringstream ost;
	string result;
	char ch;
	for(int i = 0; i < pos;)
	{
		ifs.get(ch);
		if(ch == '\n')
		{
			i++;
		}
	}
	while(ifs)
	{
		ifs.get(ch);
		if(ch == '\n')
		{
			break;
		}
		ost << ch;
	}
	result = ost.str();
	
	return result;
}
