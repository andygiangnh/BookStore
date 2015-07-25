/*========================================================================================
	Object Oriented Programming COCS2131 - Assignment 2 - Library system
	@author       : Nguyen Hoang Giang
	student Number: s3090347
	instructor    : Barend Scholtus
	Date          : 20/09/2005

  ========================================================================================
*/

// DataHolder.cpp: implementation of the DataHolder class.
//
//////////////////////////////////////////////////////////////////////

#include "DataHolder.h"
#include "Book.h"
#include "BookCopy.h"
#include "Borrower.h"
#include "Utilities.h"

#include <iostream>
#include <string>

using namespace std;


//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
int DataHolder::bookCount = 0;
int DataHolder::bookCopyCount = 0;
int DataHolder::borrowerCount= 0;
int DataHolder::loanCount = 0;

DataHolder::DataHolder()
{

}

DataHolder::~DataHolder()
{
	
}

/*
Write number of books, book copies, borrowers and loans
*/
void DataHolder::writeCounts(char* fileName)
{
	ofstream of(fileName);
	ostringstream ost;
	ost << bookCount << ":";
	ost << bookCopyCount << ":";
	ost << borrowerCount << ":";
	ost << loanCount << "\n";
	string data = ost.str();
	Utilities::writeString(data, of);
}

/*
Read number of books, book copies, borrowers and loans
*/
void DataHolder::readCounts(char* fileName)
{
	ifstream ifs(fileName);
	char s[20];
	ifs.getline(s, 20);
	int count = 0;
	for(int i = 0; i < 20; i++)
	{
		if(s[i] == ':')
		{
			count++;
		}
	}
	if(count != 3)
	{
		return;
	}
	bookCount = atoi(strtok(s, ":"));
	bookCopyCount = atoi(strtok(NULL, ":"));
	borrowerCount = atoi(strtok(NULL, ":"));
	loanCount = atoi(strtok(NULL, ":"));
}

/*
Save the book to text file
*/
void DataHolder::saveBook(char* fileName)
{
	vector<Book*>::iterator iter = bookVec.begin();
	
	while(iter != bookVec.end())
	{
		(*iter)->writeAttributes(fileName);
		bookCount++;
		iter++;
	}
}

/*
Load the book back from textfile
*/
void DataHolder::loadBook(char* fileName)
{
	int n = bookCount;
	Book* book;
	for(int i = 0; i < n; i++)
	{
		book = new Book();
		book->readAttributes(fileName);
		insertBook(book);
	}
}

/*
Save book copy to textfile
*/
void DataHolder::saveBookCopy(char* fileName)
{
	vector<BookCopy*>::iterator iter = bookCopyVec.begin();

	while(iter != bookCopyVec.end())
	{
		(*iter)->writeAttributes(fileName);
		bookCopyCount++;
		iter++;
	}
}

/*
Load book copy from textfile
*/
void DataHolder::loadBookCopy(char* fileName)
{
	int n = bookCopyCount;
	BookCopy* bc;
	for(int i = 0; i < n; i++)
	{
		bc = new BookCopy();
		bc->readAttributes(fileName);
		insertBookCopy(bc);
	}
}

/*
Save borrower to textfile
*/
void DataHolder::saveBorrower(char* fileName)
{
	vector<Borrower*>::iterator iter = borrowerVec.begin();

	while(iter != borrowerVec.end())
	{
		(*iter)->writeAttributes(fileName);
		borrowerCount++;
		iter++;
	}
}

/*
Load borrower from textfile
*/
void DataHolder::loadBorrower(char* fileName)
{
	int n = borrowerCount;
	Borrower* br;
	for(int i = 0; i < n; i++)
	{
		br = new Borrower();
		br->readAttributes(fileName);
		insertBorrower(br);
	}
}

/*
Save loan to textfile
*/
void DataHolder::saveLoan(char* fileName)
{
	set<Loan*, compareLessLoans>::iterator iter = loanSet.begin();

	while(iter != loanSet.end())
	{
		(*iter)->writeAttributes(fileName);
		loanCount++;
		iter++;
	}
}

/*
load loan from textfile
*/
void DataHolder::loadLoan(char* fileName)
{	
	int n = loanCount;
	Loan* loan;
	for(int i = 0; i < n; i++)
	{
		loan = new Loan();
		loan->readAttributes(fileName);
		insertLoan(loan);
	}
}

/*
Save system data to textfiles
*/
void DataHolder::save(char* bookFile, char* bookCopyFile, char* borrowerFile, char* loanFile)
{
	bookCount = 0;
	bookCopyCount = 0;
	borrowerCount= 0;
	loanCount = 0;
	
	saveBook(bookFile);
	saveBookCopy(bookCopyFile);
	saveBorrower(borrowerFile);
	saveLoan(loanFile);
	writeCounts("counts.txt");
}

/*
Load system data from textfiles
*/
void DataHolder::load(char* bookFile, char* bookCopyFile, char* borrowerFile, char* loanFile)
{
	readCounts("counts.txt");
	loadBook(bookFile);
	loadBookCopy(bookCopyFile);
	loadBorrower(borrowerFile);
	loadLoan(loanFile);
}

/*
insert a loan into the list
*/
void DataHolder::insertLoan(Loan* loan)
{
	loanSet.insert(loan);
}

/*
print all loan in the list
*/
void DataHolder::printLoanSet()
{
	for_each(loanSet.begin(), loanSet.end(), displayLoan());	
}

/*
delete a loan from the list
*/
bool DataHolder::deleteLoan(string bookBarcode)
{
	Loan* loan = new Loan(bookBarcode);
	set<Loan*, compareLessLoans>::iterator iter = loanSet.find(loan);
	if(iter == loanSet.end())
	{
		return false;
	}
	loanSet.erase(loan);
	return true;
}
/*
search a loan on its barcode
*/
Loan* DataHolder::searchLoan(string barcode)
{
	Loan* loan = new Loan(barcode);
	set<Loan*, compareLessLoans>::iterator iter = loanSet.find(loan);
	if(iter == loanSet.end())
	{
		return NULL;
	}
	return *iter;
}

/*
insert a book into the list
*/
void DataHolder::insertBook(Book* book)
{
	bookVec.push_back(book);
}

/*
print all the book in the list
*/
void DataHolder::printBookVec()
{
	for_each(bookVec.begin(), bookVec.end(), displayBook());
}

/*
sort the book list by title, 1st author or number of copies
*/
void DataHolder::sortBookVec(int type)
{
	if(type == 1) /* sort regarding title of books */
	{
		sort(bookVec.begin(), bookVec.end(), compareLessBookTitle());
		return;
	}
	if(type == 2) /* sort regarding 1st author of books */
	{
		sort(bookVec.begin(), bookVec.end(), compareLessBookAuthor());
		return;
	}
	/* sort regarding number of compies of books */
	sort(bookVec.begin(), bookVec.end(), compareLessBookCopies());
}

/*
delete a book with title from the list
*/
bool DataHolder::deleteBook(string title)
{
	vector<Book*>::iterator iter = bookVec.begin();
	
	int pos = 0;
	while(iter != bookVec.end())
	{
		if((*iter++)->getTitle() == title)
		{
			bookVec.erase(bookVec.begin() + pos);
			return true;
		}
		pos++;
	}
	return false;
}

/*
search a book by isbn
*/
Book* DataHolder::searchBook(string isbn)
{
	vector<Book*>::iterator iter = bookVec.begin();
	while(iter != bookVec.end())
	{
		if((*iter)->getISBN() == isbn)
		{
			return *iter;
		}
		iter++;
	}
	return NULL;
}

/*
search a book by title
*/
Book* DataHolder::searchBookTitle(string title)
{
	vector<Book*>::iterator iter = bookVec.begin();
	while(iter != bookVec.end())
	{
		if((*iter)->getTitle() == title)
		{
			return *iter;
		}
		iter++;
	}
	return NULL;
}

/*
insert a book copy into the list
*/
void DataHolder::insertBookCopy(BookCopy* bc)
{
	bookCopyVec.push_back(bc);
}

/*
print all book copy in the list
*/
void DataHolder::printBookCopyVec(vector<BookCopy*> bcVec)
{
	for_each(bcVec.begin(), bcVec.end(), displayBookCopy());
}

/*
sort book copy list by barcode
*/
void DataHolder::sortBookCopyVec()
{
	sort(bookCopyVec.begin(), bookCopyVec.end(), compareLessBookCopy());
}

/*
delete a book copy with barcode from the list
*/
bool DataHolder::deleteBookCopy(string barcode)
{
	vector<BookCopy*>::iterator iter = bookCopyVec.begin();
	
	int pos = 0;
	while(iter != bookCopyVec.end())
	{
		if((*iter++)->getBarcode() == barcode)
		{
			bookCopyVec.erase(bookCopyVec.begin() + pos);
			return true;
		}
		pos++;
	}
	return false;
}

/* 
search book copy by barcode 
*/
BookCopy* DataHolder::searchBookCopyBarcode(string barcode)
{
	vector<BookCopy*>::iterator iter = bookCopyVec.begin();
	while(iter != bookCopyVec.end())
	{
		if((*iter)->getBarcode() == barcode)
		{
			return *iter;
		}
		iter++;
	}
	return NULL;
}

/*
search book copy by isbn
*/
vector<BookCopy*> DataHolder::searchBookCopyISBN(string isbn)
{
	vector<BookCopy*> result;
	vector<BookCopy*>::iterator iter = bookCopyVec.begin();
	while(iter != bookCopyVec.end())
	{
		if((*iter)->getBookISBN() == isbn)
		{
			result.push_back(*iter);
		}
		iter++;
	}
	return result;
}

/* 
search book copies by borrowed 
*/
vector<BookCopy*> DataHolder::searchBookCopyBorrowed()
{
	vector<BookCopy*> result;
	int sta;
	
	vector<BookCopy*>::iterator iter = bookCopyVec.begin();
	while(iter != bookCopyVec.end())
	{
		sta = (*iter)->getStatus();
		if(sta == 2) /* ONLOAN */
		{
			result.push_back(*iter);
		}
		iter++;
	}
	return result;
}

/* 
search book copies by overdue 
*/
vector<BookCopy*> DataHolder::searchBookCopyOverdue()
{
	vector<BookCopy*> result;
	struct tm tmp;
	time_t now = time(NULL);
	time_t dueDate;
	BookCopy* bc;
	string barcode;
	
	set<Loan*, compareLessLoans>::iterator iter = loanSet.begin();
	while(iter != loanSet.end())
	{
		tmp = (*iter)->getDueDate();
		dueDate = mktime( &tmp);
		if(difftime(now, dueDate) > 0) /* overdue book copy */
		{
			barcode = (*iter)->getBookBarcode();
			bc = searchBookCopyBarcode(barcode);
			if(bc != NULL) /* shouldn't be */
			{
				result.push_back(bc);
			}
		}
		iter++;
	}	

	return result;
}

/*
insert a borrower into the list
*/
void DataHolder::insertBorrower(Borrower* br)
{
	borrowerVec.push_back(br);
}

/*
print all borrowers' detail from the list
*/
void DataHolder::printBorrowerVec(vector<Borrower*> brVec)
{
	for_each(brVec.begin(), brVec.end(), displayBorrower());
}

/*
sort borrower list by name of borrower or number of borrows
*/
void DataHolder::sortBorrowerVect(int type)
{
	if(type == 1)
	{
		sort(borrowerVec.begin(), borrowerVec.end(), compareLessBorrowerName());
		return;
	}
	sort(borrowerVec.begin(), borrowerVec.end(), compareLessBorrowerLoan());
}

/*
delete a borrower with an id from the list
*/
bool DataHolder::deleteBorrower(string id)
{
	vector<Borrower*>::iterator iter = borrowerVec.begin();
	
	int pos = 0;
	while(iter != borrowerVec.end())
	{
		if((*iter++)->getID() == id)
		{
			borrowerVec.erase(borrowerVec.begin() + pos);
			return true;
		}
		pos++;
	}
	return false;
}

/*
search borrower by his/her id
*/
Borrower* DataHolder::searchBorrower(string id)
{
	vector<Borrower*>::iterator iter = borrowerVec.begin();
	while(iter != borrowerVec.end())
	{
		if((*iter)->getID() == id)
		{
			return *iter; 
		}
		iter++;
	}
	return NULL;
}

/* 
search borrowers by overdue 
*/
vector<Borrower*> DataHolder::searchBorrowerOverdue()
{
	vector<Borrower*> result;
	string id;
	Borrower* br;
	struct tm tmp;
	time_t now = time(NULL);
	time_t dueDate;
	
	set<Loan*, compareLessLoans>::iterator iter = loanSet.begin();
	while(iter != loanSet.end())
	{
		tmp = (*iter)->getDueDate();
		dueDate = mktime(&tmp);
		if(difftime(now, dueDate) > 0) /* overdue */
		{
			id = (*iter)->getBorrowerID();
			br = searchBorrower(id);
			if(br != NULL) /* should be */
			{
				result.push_back(br);
			}
		}
		iter++;
	}

	return result;
}
