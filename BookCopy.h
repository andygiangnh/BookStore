/*========================================================================================
	Object Oriented Programming COCS2131 - Assignment 2 - Library system
	@author       : Nguyen Hoang Giang
	student Number: s3090347
	instructor    : Barend Scholtus
	Date          : 20/09/2005

  ========================================================================================
*/
// BookCopy.h: interface for the BookCopy class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_BOOKCOPY_H__008864B4_86FE_4C7A_8576_815914E18CC0__INCLUDED_)
#define AFX_BOOKCOPY_H__008864B4_86FE_4C7A_8576_815914E18CC0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include <iostream>
#include <string>
#include <ctime>
#include "Book.h"

using namespace std;

class BookCopy  
{
private:
	string barcode;
	enum Status {INSTOREROOM, INLIBRARY, ONLOAN, LOST} status;
	int noOfBorrowed; /* Number of times borrowed */
	struct tm borrowedDate; /* The date that it was borrowed */
	int borrowDuration; /* The number of days it is borrowed this time */
	string bookISBN;
public:
	BookCopy();
	BookCopy(string);
	virtual ~BookCopy();
	static vector<string> barcodeList;
	static string STATUS[];
	static int posCount;
	
	ostream& printDetailsList(ostream&);
	void printDetails(ostream&);
	istream& getDetails(istream&);
	friend ostream& operator <<(ostream&, BookCopy&);
	friend istream& operator >>(istream&, BookCopy&);
	bool operator<(const BookCopy&) const;
	bool operator==(const BookCopy&) const;
	void writeAttributes(char*);
	void readAttributes(char*);

	/*
	Set the status for this book copy
	*/
	void setStatus(int s)
	{
		status = static_cast<Status>(s);
	}
	
	/*
	Set number of times this book copy has been loaned
	*/
	void setNoOfBorrowed(int n)
	{
		noOfBorrowed = n;
	}
	
	/*
	Set the borrowed date for this book copy
	*/
	void setBorrowDate(struct tm date)
	{
		borrowedDate = date;
	}

	/*
	Access the barcode of this book copy
	*/	
	string getBarcode()
	{
		return barcode;
	}
	
	/*
	Access the status of this book copy
	*/
	int getStatus() const
	{
		return status;
	}
	
	/*
	Access the borrowed date of this book copy
	*/
	struct tm getBorrowDate() const
	{
		return borrowedDate;
	}
	
	/*
	Access borrow duration available to this book copy
	*/
	int getBorrowDuration() const
	{
		return borrowDuration;
	}
	
	/*
	Access the book ISBN of this book copy
	*/
	string getBookISBN() const
	{
		return bookISBN;
	}
	
	/*
	Access number of times this book copy has been loaned
	*/
	int getNoOfBorrowed()
	{
		return noOfBorrowed;
	}
	
};

#endif // !defined(AFX_BOOKCOPY_H__008864B4_86FE_4C7A_8576_815914E18CC0__INCLUDED_)
