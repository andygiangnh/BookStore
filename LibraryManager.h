/*========================================================================================
	Object Oriented Programming COCS2131 - Assignment 2 - Library system
	@author       : Nguyen Hoang Giang
	student Number: s3090347
	instructor    : Barend Scholtus
	Date          : 20/09/2005

  ========================================================================================
*/
// LibraryManager.h: interface for the LibraryManager class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LIBRARYMANAGER_H__2EA7D141_A6CA_4FB7_B551_50D38F9CA25A__INCLUDED_)
#define AFX_LIBRARYMANAGER_H__2EA7D141_A6CA_4FB7_B551_50D38F9CA25A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "DataHolder.h"

class LibraryManager  
{
private:
	DataHolder dataHolder;
		
public:
	LibraryManager();
	virtual ~LibraryManager();
	
	void createBook(); /* Create a new book */
	void createBookCopy(); /* Create a new book copy */
	void createBorrower(); /* Create a new borrower */
	void borrowBook(); /* borrow a book */
	void returnBook(); /* return a book */
	void changeBookStatus(int); /* Change status of a book */
	void printBookReport(); /* print all the book in the system */
	void printBookCopyReport(int); /* print book copies provided report type */
	void printBorrowerReport(int); /* print borrower report provide report type */
	void sortBook(int); /* sort the book list */
	void sortBorrower(int); /* sort the borrower list*/
	void save(char*, char*, char*, char*); /* save system data to text files */
	void load(char*, char*, char*, char*); /* load back text file into memory */
	
};

#endif // !defined(AFX_LIBRARYMANAGER_H__2EA7D141_A6CA_4FB7_B551_50D38F9CA25A__INCLUDED_)
