/*========================================================================================
	Object Oriented Programming COCS2131 - Assignment 2 - Library system
	@author       : Nguyen Hoang Giang
	student Number: s3090347
	instructor    : Barend Scholtus
	Date          : 20/09/2005

  ========================================================================================
*/
// Loan.h: interface for the Loan class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LOAN_H__29DF8015_1263_4BE8_B047_EAD06797B441__INCLUDED_)
#define AFX_LOAN_H__29DF8015_1263_4BE8_B047_EAD06797B441__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include <iostream>
#include <string>
#include <ctime>
using namespace std;

class Loan  
{
private:
	string borrowerID;
	string bookISBN;
	string bookBarcode;
	int borrowDuration;
	struct tm dueDate;	
public:
	Loan();
	Loan(string);
	Loan(string, string, string, int);
	virtual ~Loan();

	static int posCount; /* Store information to read file */

	ostream& printDetails(ostream&);
	friend ostream& operator<<(ostream&, Loan&);
	bool operator <(const Loan&) const;
	bool operator ==(const Loan&) const;
	void writeAttributes(char*);
	void readAttributes(char*);

	/* Accessor methods*/
	
	/*
	Get borrower ID associated with this loan
	*/
	string getBorrowerID() const
	{
		return borrowerID;
	}
	
	/*
	Get book ISBN associated with this loan
	*/
	string getBookISBN() const
	{
		return bookISBN;
	}

	
	/*
	Get book barcode associated with this loan
	*/
	string getBookBarcode() const
	{
		return bookBarcode;
	}

	/*
	Get borrow duration for this book copy that associated with this loan
	*/
	int getBorrowDuration() const
	{
		return borrowDuration;
	}

	/*
	Get the duedate associated with this loan
	*/
	struct tm getDueDate() const
	{
		return dueDate;
	}


};

#endif // !defined(AFX_LOAN_H__29DF8015_1263_4BE8_B047_EAD06797B441__INCLUDED_)
