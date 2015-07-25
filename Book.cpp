/*========================================================================================
	Object Oriented Programming COCS2131 - Assignment 2 - Library system
	@author       : Nguyen Hoang Giang
	student Number: s3090347
	instructor    : Barend Scholtus
	Date          : 20/09/2005

  ========================================================================================
*/
// Book.cpp: implementation of the Book class.
//
//////////////////////////////////////////////////////////////////////

#include "Book.h"
#include "Utilities.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
vector<string> Book::isbnList;
string Book::CATEGORY[] = {"Business", "Marketing", "Finance", "Programming", "Database"};
int Book::posCount = 0;

Book::Book()
{
	title = "";
	edition = 1;
	isbn = "";
	publisher = "";
	printYear = 0;
	noOfPages = 0;
	noOfCopies = 0;
	noOfBorrows = 0;
	category = BUSINESS;
}

Book::Book(string tit)
{
	Book();
	title = tit;
}

Book::~Book()
{

}

/*
Write all attributes of this book to textfile
*/
void Book::writeAttributes(char* fileName)
{
	ofstream of;
	of.open(fileName, ios::app);
	ostringstream ost;
	ost << title << ":";
	ost << edition << ":";
	ost << authors.size() << ":";
	for(int i = 0; i < authors.size(); i++)
	{
		ost << authors[i] << ":";
	}
	
	ost << isbn << ":";
	ost << publisher << ":";
	ost << printYear << ":";
	ost << noOfPages << ":";
	ost << noOfCopies << ":";
	ost << noOfBorrows << ":";
	ost << getCategory() << "\n";

	string data = ost.str();
	Utilities::writeString(data, of);
}

/*
Read attributes for this book
*/
void Book::readAttributes(char* fileName)
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

	title = strtok(s, ":");
	edition = atoi(strtok(NULL, ":"));
	
	int n = atoi(strtok(NULL, ":"));
	for(int j = 0; j < n; j++)
	{
		authors.push_back(strtok(NULL, ":"));
	}

	isbn = strtok(NULL, ":");
	publisher = strtok(NULL, ":");
	printYear = atoi(strtok(NULL, ":"));
	noOfPages = atoi(strtok(NULL, ":"));
	noOfCopies  = atoi(strtok(NULL, ":"));
	noOfBorrows = atoi(strtok(NULL, ":"));
	category = static_cast<Category>(atoi(strtok(NULL, ":")));	
}

/*
Overload extraction operator
*/
ostream& operator <<(ostream& os, Book& b)
{
	return b.printDetails(os);
}

/*
Overload insertion operator
*/
istream& operator >>(istream& is, Book& b)
{
	return b.getDetails(is);
}

/* 
Input the detail for this book with unique ISBN
*/
istream& Book::getDetails(istream& is)
{
	string tmpISBN;
	vector<string>::iterator iter = Book::isbnList.begin();
	tmpISBN = Utilities::readString(is, 51, "ISBN");
	
	while(iter != Book::isbnList.end())
	{
		if(*iter++ == tmpISBN)
		{
			cout << "This ISBN already exists" << endl;
			return is;
		}
	}
	
	Book::isbnList.push_back(tmpISBN);
	isbn = tmpISBN;
	title = Utilities::readString(is, 61, "Title");
	Utilities::readInt(is,edition, "Edition");
	
	int noOfAuthors;
	bool keepGoing = true;
	Utilities::readInt(is, noOfAuthors, "Number of author");
	if(noOfAuthors > 5)
	{
		cout << "The maximum number of authors is 5\n";
		keepGoing = Utilities::readBool(is, "Do you want to enter 5 authors", 'y', 'n');
	}
	if(!keepGoing)
	{
		cout << "The book will not be saved" << endl;
		return is;
	}
	
	string tmp;
	
	for(int i = 0; i < noOfAuthors; i++)
	{
		ostringstream ost;
		ost << "Author[";
		ost << i+1 << "]";
		tmp = Utilities::readString(is, 41, ost.str());
		authors.push_back(tmp);
	}

	publisher = Utilities::readString(is, 61, "Publisher");
	Utilities::readInt(is, printYear, "Year of printing");
	Utilities::readInt(is, noOfPages, "Number of pages");
	Utilities::readInt(is, noOfCopies, "Number of copies");
	category = static_cast<Category> (Utilities::readStringOptions(is, 5, CATEGORY));
	
	return is;
}

/*
Quick list details of this book on 1 line
*/
ostream& Book::printDetails(ostream& os)
{	
	os.unsetf(ios::right);
	os << setw(25) << setiosflags(ios::left) << title << " ";
	os << setw(15) << authors[0] << " ";
	os.unsetf(ios::left);
	os << setw(7) << setiosflags(ios::right) << edition << " ";
	os.unsetf(ios::right);
	os << setw(11) << setiosflags(ios::left) << Book::CATEGORY[getCategory()] << " ";
	os.unsetf(ios::left);
	os << setw(7) << noOfCopies << " " << setw(7) << noOfBorrows << endl;
	os.unsetf(ios::left);
	
	return os;
}

/*
overload less than comparision operator
*/
bool Book::operator<(const Book& b1) const
{
	return title < b1.title;
}

/*
overload equal comparision operator
*/
bool Book::operator==(const Book& b1) const
{
	return title == b1.title;
}
