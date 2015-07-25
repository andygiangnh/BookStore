/*========================================================================================
	Object Oriented Programming COCS2131 - Assignment 2 - Library system
	@author       : Nguyen Hoang Giang
	student Number: s3090347
	instructor    : Barend Scholtus
	Date          : 20/09/2005

  ========================================================================================
*/
// Loan.cpp: implementation of the Loan class.
//
//////////////////////////////////////////////////////////////////////

#include "Loan.h"
#include "Utilities.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
int Loan::posCount = 0;

Loan::Loan()
{
	borrowerID = "";
	bookISBN = "";
	bookBarcode = "";
	borrowDuration = 0;
	dueDate = Utilities::getCurrentDate();
}

/*
Constructor takes one parameter of barcode
*/
Loan::Loan(string bBarcode)
{
	borrowerID = "";
	bookISBN = "";
	borrowDuration = 0;
	dueDate = Utilities::getCurrentDate();
	bookBarcode = bBarcode;
}

/* Use this constructor to create loan */
Loan::Loan(string bBarcode, string bISBN, string bID, int duration)
{
	bookBarcode = bBarcode;
	bookISBN = bISBN;
	borrowerID = bID;
	borrowDuration = duration;
	dueDate = Utilities::getCurrentDate();
	dueDate.tm_mday += duration;
}

/*
Destructor
*/
Loan::~Loan()
{

}

/*
Write all attributes of this loan to textfile
*/
void Loan::writeAttributes(char* fileName)
{
	ofstream of;
	of.open(fileName, ios::app);
	ostringstream ost;
	
	ost << borrowerID << ":";
	ost << bookISBN << ":";
	ost << bookBarcode << ":";
	ost << borrowDuration << ":";

	ost << dueDate.tm_year << ":";
	ost << dueDate.tm_mon << ":";
	ost << dueDate.tm_mday << ":";
	ost << dueDate.tm_hour << ":";
	ost << dueDate.tm_min << ":";
	ost << dueDate.tm_sec << ":";
	ost << dueDate.tm_wday << "\n";

	string data = ost.str();
	Utilities::writeString(data, of);
}

/*
Read back from text file into memory
*/
void Loan::readAttributes(char* fileName)
{
	ifstream ifs(fileName);
	string tmp = Utilities::readFileString(ifs, posCount++);
	char s[150];
	const char* p = tmp.c_str();
	for(int i = 0; i < tmp.length(); i++)
	{
		s[i] = *(p+i);
	}
	s[tmp.length()] = '\0';

	borrowerID = strtok(s, ":");
	bookISBN = strtok(NULL, ":");
	bookBarcode = strtok(NULL, ":");
	borrowDuration = atoi(strtok(NULL, ":"));

	dueDate.tm_year = atoi(strtok(NULL, ":"));
	dueDate.tm_mon = atoi(strtok(NULL, ":"));
	dueDate.tm_mday = atoi(strtok(NULL, ":"));
	dueDate.tm_hour = atoi(strtok(NULL, ":"));
	dueDate.tm_min = atoi(strtok(NULL, ":"));
	dueDate.tm_sec = atoi(strtok(NULL, ":"));
	dueDate.tm_wday = atoi(strtok(NULL, ":"));
}

/*
Overload less comparision
*/
bool Loan::operator <(const Loan& loan) const
{
	return bookBarcode < loan.bookBarcode;
}

/*
Overload equal comparision
*/
bool Loan::operator ==(const Loan& loan) const
{
	return bookBarcode == loan.bookBarcode;
}

/*
Print detail of this loan
*/
ostream& Loan::printDetails(ostream& os)
{
	os << setw(15) << setiosflags(ios::left) << bookBarcode << " ";
	os << setw(15) << setiosflags(ios::left) << borrowerID << " ";
	os << setw(15) << setiosflags(ios::left) << bookISBN << " ";
	os << Utilities::dateToString(dueDate) << endl;
	os.unsetf(ios::left);

	return os;
}

/*
Overload extraction operator
*/
ostream& operator<<(ostream& os, Loan& loan)
{
	return loan.printDetails(os);
}
