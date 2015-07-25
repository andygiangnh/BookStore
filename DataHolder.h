/*========================================================================================
	Object Oriented Programming COCS2131 - Assignment 2 - Library system
	@author       : Nguyen Hoang Giang
	student Number: s3090347
	instructor    : Barend Scholtus
	Date          : 20/09/2005

  ========================================================================================
*/
// DataHolder.h: interface for the DataHolder class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DATAHOLDER_H__A020B9AE_AF47_4627_A15E_A11745B6CE27__INCLUDED_)
#define AFX_DATAHOLDER_H__A020B9AE_AF47_4627_A15E_A11745B6CE27__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#pragma warning (disable:4786)
#endif // _MSC_VER > 1000
#include <iostream>
#include <string>
#include <set>
#include <algorithm>
#include <fstream>

#include "BookCopy.h"
#include "Loan.h"
#include "Borrower.h"
#include "Utilities.h"

using namespace std;     
/*
function object helps to insert loan in order regarding its book barcode
*/
class compareLessLoans
{
public:
	bool operator() (const Loan* loan1, const Loan* loan2) const
	{
		return *loan1 < *loan2;
	}
};

/*
function object helps to sort books list by title
*/
class compareLessBookTitle
{
public:
	bool operator() (const Book* b1, const Book* b2) const
	{
		return b1->getTitle() < b2->getTitle();
	}
};

/*
function object helps to sort books list by 1st author
*/
class compareLessBookAuthor
{
public:
	bool operator() (const Book* b1, const Book* b2) const
	{
		return b1->getAuthors()[0] < b2->getAuthors()[0];
	}
};

/*
function object helps to sort books list by number of copies
*/
class compareLessBookCopies
{
public:
	bool operator() (const Book* b1, const Book* b2) const
	{
		return b1->getNoOfCopies() < b2->getNoOfCopies();
	}
};

/*
function object helps to sort book copy by barcode
*/
class compareLessBookCopy
{
public:
	bool operator() (const BookCopy* bc1, const BookCopy* bc2) const
	{
		return *bc1 < *bc2;
	}
};

/*
function object helps to sort borrowers list by name
*/
class compareLessBorrowerName
{
public:
	bool operator() (const Borrower* br1, const Borrower* br2) const
	{
		return br1->getName() < br2->getName();
	}
};

/*
function object helps to sort borrowers list by number of book borrowed in the past
*/
class compareLessBorrowerLoan
{
public:
	bool operator() (const Borrower* br1, const Borrower* br2) const
	{
		return br1->getNoOfBorrow() < br2->getNoOfBorrow();
	}
};

/*
function object helps to display each loan
*/
class displayLoan
{
public:
	void operator() (const Loan* loan) const
	{
		Loan lo(*loan);
		cout << lo;
	}
};

/*
function object helps to display each book
*/
class displayBook
{
public:
	void operator() (const Book* book) const
	{
		Book bo(*book);
		cout << bo;
	}
};

/*
function object helps to display each book copy
*/
class displayBookCopy
{
public:
	void operator() (const BookCopy* bookCopy) const
	{
		BookCopy bc(*bookCopy);
		cout << bc;
	}
};

/*
function object helps to display each borrower
*/
class displayBorrower
{
public:
	void operator() (const Borrower* borrower) const
	{
		Borrower bo(*borrower);
		cout << bo;
	}
};

class DataHolder  
{
private:
	set<Loan*, compareLessLoans> loanSet;
	vector<Borrower*> borrowerVec;
	vector<Book*> bookVec;
	vector<BookCopy*> bookCopyVec;
	
	void saveBook(char*);
	void saveBookCopy(char*);
	void saveBorrower(char*);
	void saveLoan(char*);

	void loadBook(char*);
	void loadBookCopy(char*);
	void loadBorrower(char*);
	void loadLoan(char*);
public:
	DataHolder();
	virtual ~DataHolder();

	static int bookCount;
	static int bookCopyCount;
	static int borrowerCount;
	static int loanCount;

	/* Accessor methods */

	/*
	Access the loan set of the system
	*/
	set<Loan*, compareLessLoans> getLoanSet()
	{
		return loanSet;
	}

	/*
	Access the book vector of the system
	*/
	vector<Book*> getBookVec()
	{
		return bookVec;
	}
	
	/*
	Access the book copy vector of the system
	*/
	vector<BookCopy*> getBookCopyVec()
	{
		return bookCopyVec;
	}

	/*
	Access the borrower vector of the system
	*/
	vector<Borrower*> getBorrowerVec()
	{
		return borrowerVec;
	}

	void save(char*, char*, char*, char*); /* save system data to textfile */
	void load(char*, char*, char*, char*); /* load back textfile into memory */

	void writeCounts(char*); /* write number of books, bookcopies, borrowers and loans */
	void readCounts(char*); /* read number of books, bookcopies, borrowers and loans */

	void insertLoan(Loan*);
	void printLoanSet();
	bool deleteLoan(string);
	Loan* searchLoan(string); /* search by barcode */

	void insertBook(Book*);
	void printBookVec();
	void sortBookVec(int);
	bool deleteBook(string);
	Book* searchBook(string); /* search by isbn*/
	Book* searchBookTitle(string); /* search by title */

	void insertBookCopy(BookCopy*);
	void printBookCopyVec(vector<BookCopy*>);
	void sortBookCopyVec();
	bool deleteBookCopy(string);
	BookCopy* searchBookCopyBarcode(string); /* search book copy by barcode */
	vector<BookCopy*> searchBookCopyISBN(string); /* search book copies by isbn */
	vector<BookCopy*> searchBookCopyBorrowed(); /* search book copies by borrowed */
	vector<BookCopy*> searchBookCopyOverdue();/* search book copies by overdue */
	
	void insertBorrower(Borrower*);
	void printBorrowerVec(vector<Borrower*>);
	void sortBorrowerVect(int);
	bool deleteBorrower(string);
	Borrower* searchBorrower(string); /* search by id */
	vector<Borrower*> searchBorrowerOverdue(); /* search borrowers by overdue */
};

#endif // !defined(AFX_DATAHOLDER_H__A020B9AE_AF47_4627_A15E_A11745B6CE27__INCLUDED_)
