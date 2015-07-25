/*========================================================================================
	Object Oriented Programming COCS2131 - Assignment 2 - Library system
	@author       : Nguyen Hoang Giang
	student Number: s3090347
	instructor    : Barend Scholtus
	Date          : 20/09/2005

  ========================================================================================
*/

// BookCopy.cpp: implementation of the BookCopy class.
//
//////////////////////////////////////////////////////////////////////

#include "BookCopy.h"
#include "Utilities.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
vector<string> BookCopy::barcodeList;
string BookCopy::STATUS[] = {"Storeroom", "Library", "Onloan", "Lost"};
int BookCopy::posCount = 0;

/*
Default constructor
*/
BookCopy::BookCopy()
{
	barcode = "";
	status = INLIBRARY;
	noOfBorrowed = 0;
	borrowedDate = Utilities::getCurrentDate();
	borrowDuration = 0;
	bookISBN = "";
}

/*
Constructor take isbn as parameter
*/
BookCopy::BookCopy(string isbn)
{
	barcode = "";
	status = INLIBRARY;
	noOfBorrowed = 0;
	borrowedDate = Utilities::getCurrentDate();
	borrowDuration = 0;
	bookISBN = isbn;	
}

BookCopy::~BookCopy()
{

}

/*
Write all attributes of this bookcopy to textfile
*/
void BookCopy::writeAttributes(char* fileName)
{
	ofstream of;
	of.open(fileName, ios::app);
	ostringstream ost;

	ost << barcode << ":";
	ost << getStatus() << ":";
	ost << noOfBorrowed << ":";
	
	ost << borrowedDate.tm_year << ":";
	ost << borrowedDate.tm_mon << ":";
	ost << borrowedDate.tm_mday << ":";
	ost << borrowedDate.tm_hour << ":";
	ost << borrowedDate.tm_min << ":";
	ost << borrowedDate.tm_sec << ":";
	ost << borrowedDate.tm_wday << ":";
	
	ost << borrowDuration << ":";
	ost << bookISBN << "\n";

	string data = ost.str();
	Utilities::writeString(data, of);
}

/*
Read back attributes for this book copy from text file
*/
void BookCopy::readAttributes(char* fileName)
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
	barcode = strtok(s, ":");
	status = static_cast<Status>(atoi(strtok(NULL, ":")));
	noOfBorrowed = atoi(strtok(NULL, ":"));
	
	borrowedDate.tm_year = atoi(strtok(NULL, ":"));
	borrowedDate.tm_mon = atoi(strtok(NULL, ":"));
	borrowedDate.tm_mday = atoi(strtok(NULL, ":"));
	borrowedDate.tm_hour = atoi(strtok(NULL, ":"));
	borrowedDate.tm_min = atoi(strtok(NULL, ":"));
	borrowedDate.tm_sec = atoi(strtok(NULL, ":"));
	borrowedDate.tm_wday = atoi(strtok(NULL, ":"));
	
	borrowDuration = atoi(strtok(NULL, ":"));
	bookISBN = strtok(NULL, ":");
}

/*
Overload extraction operator
*/
ostream& operator<<(ostream& os, BookCopy& bc)
{
	return bc.printDetailsList(os);
}

/*
Overload insertion operator
*/
istream& operator>>(istream& is, BookCopy& bc)
{
	return bc.getDetails(is);
}

/*
Print details of this book copy
*/
ostream& BookCopy::printDetailsList(ostream& os)
{
	os.unsetf(ios::right);
	os << setw(15) << setiosflags(ios::left) << barcode << " ";
	os << setw(11) << BookCopy::STATUS[getStatus()] << " ";	
	os << setw(12) << bookISBN << " ";
	os.unsetf(ios::left);
	os << setw(8) << setiosflags(ios::right) << borrowDuration << " ";
	
	if(status == ONLOAN)
	{
		os << setiosflags(ios::left) << Utilities::dateToString(borrowedDate);
	}
	os << endl;
	os.unsetf(ios::right);

	return os;
}

/*
Quick list details of this book copy on 1 line
*/
void BookCopy::printDetails(ostream& os)
{
	os << "Barcode: " << barcode << "\n";
	os << "Book ISBN: " << bookISBN << "\n";
	os << "Status: " << BookCopy::STATUS[getStatus()] << "\n";
	os << "Number of borrows: " << noOfBorrowed << "\n";
	os << "Borrow duration: " << borrowDuration << endl;
}

/* 
Input detail for this bookcopy with unique barcode
*/
istream& BookCopy::getDetails(istream& is)
{
	string tmpBarcode = Utilities::readString(is, 41, "Barcode");
	vector<string>::iterator iter = BookCopy::barcodeList.begin();

	while(iter != BookCopy::barcodeList.end())
	{
		if(*iter++ == tmpBarcode)
		{
			cout << "This barcode already exists" << endl;
			return is;
		}
	}
	
	BookCopy::barcodeList.push_back(tmpBarcode);
	barcode = tmpBarcode;
	status = static_cast<Status> (Utilities::readStringOptions(is, 4, STATUS));
	Utilities::readInt(is, borrowDuration, "Borrow duration");
		
	return is;
}

/*
Overload less than operator
*/
bool BookCopy::operator<(const BookCopy& bc1) const
{
	return barcode < bc1.barcode;
}

/*
Overload equal operator
*/
bool BookCopy::operator==(const BookCopy& bc1) const
{
	return barcode == bc1.barcode;
}
