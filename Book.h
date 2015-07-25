/*========================================================================================
	Object Oriented Programming COCS2131 - Assignment 2 - Library system
	@author       : Nguyen Hoang Giang
	student Number: s3090347
	instructor    : Barend Scholtus
	Date          : 20/09/2005

  ========================================================================================
*/
// Book.h: interface for the Book class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_BOOK_H__5A7DACFD_82F2_4035_806D_62F8BAB803C9__INCLUDED_)
#define AFX_BOOK_H__5A7DACFD_82F2_4035_806D_62F8BAB803C9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#pragma warning (disable:4786)
#endif // _MSC_VER > 1000
#include <string>
#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
using namespace std;

class Book  
{
private:
	string title;
	int edition;
	vector<string> authors;
	string isbn;
	string publisher;
	int printYear;
	int noOfPages;
	int noOfCopies;
	int noOfBorrows;
	enum Category {BUSINESS=0, MARKETING, FINANCE, PROGRAMMING, DATABASE} category;
public:
	Book();
	Book(string);
	virtual ~Book();
	static vector<string> isbnList;
	static string CATEGORY[];
	static int posCount;

	istream& getDetails(istream&);
	ostream& printDetails(ostream&);
	friend ostream& operator <<(ostream&, Book&);
	friend istream& operator >>(istream&, Book&);
	bool operator<(const Book&) const;
	bool operator==(const Book&) const;
	void writeAttributes(char*);
	void readAttributes(char*);
	
	/*
	Set number of borrows made to this book
	*/
	void setNoOfBorrows(int n)
	{
		noOfBorrows = n;
	}
	
	/*
	Access the title of this book
	*/		
	string getTitle() const
	{
		return title;
	}
	
	/*
	Access the authors of this book
	*/
	vector<string> getAuthors() const
	{
		return authors;
	}
	
	/*
	Access the edition of this book
	*/
	int getEdition() const
	{
		return edition;
	}
	
	/*
	Access the ISBN of this book
	*/
	string getISBN() const
	{
		return isbn;
	}
	
	/*
	Access the publisher of this book
	*/
	string getPublisher() const
	{
		return publisher;
	}
	
	/*
	Access the print year of this book
	*/
	int getPrintYear() const
	{
		return printYear;
	}
	
	/*
	Access number of pages in this book
	*/
	int getNoOfPages() const
	{
		return noOfPages;
	}
	
	/*
	Access number of copies available of this book
	*/
	int getNoOfCopies() const
	{
		return noOfCopies;
	}
	
	/*
	Access number of borrows made to this book
	*/
	int getNoOfBorrows() const
	{
		return noOfBorrows;
	}
	
	/*
	Access category of this book
	*/
	int getCategory() const
	{
		return category;
	}

};

#endif // !defined(AFX_BOOK_H__5A7DACFD_82F2_4035_806D_62F8BAB803C9__INCLUDED_)
