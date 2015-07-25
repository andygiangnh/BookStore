/*========================================================================================
	Object Oriented Programming COCS2131 - Assignment 2 - Library system
	@author       : Nguyen Hoang Giang
	student Number: s3090347
	instructor    : Barend Scholtus
	Date          : 20/09/2005

  ========================================================================================
*/
// Borrower.h: interface for the Borrower class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_BORROWER_H__5C2EDEEF_1B8C_46EF_9456_614974F8E63F__INCLUDED_)
#define AFX_BORROWER_H__5C2EDEEF_1B8C_46EF_9456_614974F8E63F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#pragma warning (disable:4786) 
#endif // _MSC_VER > 1000
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
using namespace std;

class Borrower  
{
private:
	string id;
	string name;
	enum Type {STUDENT, STAFF} type;
	enum Department {IS, BCOMM, UPP} department;
	string phoneNum;
	int noOfBorrow;     /* Number of books borrowed in the past */
	int noOfReturnLate; /* Number of books returned late in the past*/
public:
	Borrower();
	virtual ~Borrower();

	static vector<string> idList;
	static string TYPE[];
	static string DEPARTMENT[];
	static int posCount;

	istream& getDetails(istream&);
	ostream& printDetailsList(ostream&);
	void printDetails(ostream&);
	friend ostream& operator<<(ostream&, Borrower&);
	friend istream& operator>>(istream&, Borrower&);
	bool operator<(const Borrower&) const;
	bool operator==(const Borrower&) const;
	void writeAttributes(char*);
	void readAttributes(char*);

	/* Mutator methods */
	void setNoOfBorrow(int n)
	{
		noOfBorrow = n;
	}

	void setNoOfReturnLate(int n)
	{
		noOfReturnLate = n;
	}
	
	/* 
	Access the ID of this borrower
	*/	
	string getID() const
	{
		return id;
	}
	
	/*
	Access the name of this borrower
	*/
	string getName() const
	{
		return name;
	}
	
	/*
	Access the type of this borrower
	*/
	int getType() const
	{
		return type;
	}
	
	/*
	Access the department of this borrower
	*/
	int getDepartment() const
	{
		return department;
	}
	
	/*
	Access the phone number of this borrower
	*/
	string getPhoneNum() const
	{
		return phoneNum;
	}
	
	/*
	Access number of borrows made by this borrower
	*/
	int getNoOfBorrow() const
	{
		return noOfBorrow;
	}

	/*
	Access number of late returns made by this borrower
	*/
	int getnoOfReturnLate() const
	{
		return noOfReturnLate;
	}

};

#endif // !defined(AFX_BORROWER_H__5C2EDEEF_1B8C_46EF_9456_614974F8E63F__INCLUDED_)
