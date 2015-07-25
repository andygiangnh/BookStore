/*========================================================================================
	Object Oriented Programming COCS2131 - Assignment 2 - Library system
	@author       : Nguyen Hoang Giang
	student Number: s3090347
	instructor    : Barend Scholtus
	Date          : 20/09/2005

  ========================================================================================
*/
// LibraryManager.cpp: implementation of the LibraryManager class.
//
//////////////////////////////////////////////////////////////////////

#include "LibraryManager.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

LibraryManager::LibraryManager()
{

}

LibraryManager::~LibraryManager()
{

}

/*
Create new book
*/
void LibraryManager::createBook()
{
	cout << "Enter detail for book\n";
	Book* book = new Book();
	cin >> *book;
	dataHolder.insertBook(book);
	cout << "Book has successfully added to system" << endl;
}

/*
Create new book copy
*/
void LibraryManager::createBookCopy()
{
	cout << "Enter detail for book copy\n";

	string isbn = Utilities::readString(cin, 21, "ISBN");
	Book* book = dataHolder.searchBook(isbn);
	if(book == NULL)
	{
		cout << "This book ISBN does not exist\nPlease check again!" << endl;
		return;
	}
	
	BookCopy* bc = new BookCopy(isbn);
	cin >> *bc;
	dataHolder.insertBookCopy(bc);
	
	cout << "Book copy has successfully added to system" << endl;
}

/*
Create new borrower
*/
void LibraryManager::createBorrower()
{
	cout << "Enter detail for borrower\n";
	Borrower* br = new Borrower();
	cin >> *br;
	dataHolder.insertBorrower(br);
	cout << "Borrower has successfully added to system" << endl;
}

/*
borrow a book from the library
*/
void LibraryManager::borrowBook()
{
	string id;
	id = Utilities::readString(cin, 21, "Borrower ID");
	Borrower* br = dataHolder.searchBorrower(id);
	if(br == NULL)
	{
		cout << "This id does not exist" << endl;
		return;
	}
	cout << "Borrower detail\n";
	br->printDetails(cout);
	string barcode = Utilities::readString(cin, 21, "Enter barcode of book");
	BookCopy* bc = dataHolder.searchBookCopyBarcode(barcode);
	if(bc == NULL)
	{
		cout << "This book barcode does not exist\nPlease check again!" << endl;
		return;
	}
	cout << "Detail of this book copy\n";
	bc->printDetails(cout);
	cout << endl;
	bool borrow = Utilities::readBool(cin, "Do you wish to borrow this book(y/n)", 'y', 'n');
	if(borrow)
	{
		br->setNoOfBorrow(br->getNoOfBorrow() + 1); /* Increase borrows by 1 */
		bc->setStatus(2);/* ONLOAN */
		bc->setNoOfBorrowed(bc->getNoOfBorrowed() + 1);
		bc->setBorrowDate(Utilities::getCurrentDate());
		Loan* loan = new Loan(barcode, bc->getBookISBN(), id, bc->getBorrowDuration());
		Book* book = dataHolder.searchBook(bc->getBookISBN()); /* should present, ie not NULL */
		book->setNoOfBorrows(book->getNoOfBorrows() + 1);
		dataHolder.insertLoan(loan);
		cout << "The book copy is borrowed" << endl;
	}
}

/*
Return a book to the library
*/
void LibraryManager::returnBook()
{
	string barcode = Utilities::readString(cin, 21, "Barcode");
	BookCopy *bc = dataHolder.searchBookCopyBarcode(barcode);
	if(bc == NULL)
	{
		cout << "This book barcode does not exist\nPlease check again!" << endl;
		return;
	}
	bc->setStatus(0); /* INSTOREROOM */
	Loan* loan = dataHolder.searchLoan(barcode); /* should exist since book copy exist */
	struct tm tmp = loan->getDueDate();
	dataHolder.deleteLoan(barcode); /* Remove this loan */
	time_t now = time(NULL);
	time_t dueDate = mktime(&tmp);
	double diff = difftime(now, dueDate);
	if(diff > 0)
	{
		Borrower* borrower = dataHolder.searchBorrower(loan->getBorrowerID());
		borrower->setNoOfReturnLate(borrower->getnoOfReturnLate() + 1); /* increse late return by 1 */
		cout << "The book is returned late" << endl;
		return;
	}
	cout << "The book is returned\nThe system is updated" << endl;
}

/*
Change status of a book
*/
void LibraryManager::changeBookStatus(int type)
{
	if(type == 1)
	{
		string barcode = Utilities::readString(cin, 21, "Barcode");
		BookCopy *bc = dataHolder.searchBookCopyBarcode(barcode);
		if(bc == NULL)
		{
			cout << "This book barcode does not exist\nPlease check again!" << endl;
			return;
		}
		cout << "Enter new status for book copy\n";
		string options[] = {"In storeroom", "In library", "On loan", "Lost"};
		int newStatus = Utilities::readStringOptions(cin, 4, options);
		bc->setStatus(newStatus);
		cout << "Book copy status updated" << endl;
		return;
	}
	/* change book status for lost book */
	string title = Utilities::readString(cin, 31, "Title of lost book");
	Book* lostBook = dataHolder.searchBookTitle(title);
	if(lostBook == NULL)
	{
		cout << "There is no such book with this title" << endl;
		return;
	}
	string isbn = lostBook->getISBN();
	vector<BookCopy*> result = dataHolder.searchBookCopyISBN(isbn);
	if(result.size() == 0)
	{
		cout << "There no copy of this book in the system" << endl;
		return;
	}
	cout.unsetf(ios::right);
	cout << setw(16) << setiosflags(ios::left) << "Barcode ";
	cout << setw(12) << "Status ";	
	cout << setw(13) << "ISBN ";
	cout.unsetf(ios::left);
	cout << setw(9) << setiosflags(ios::right) << "Duration ";
	cout.unsetf(ios::right);
	cout << setiosflags(ios::left) << "Borrow date" << endl;
	cout.unsetf(ios::left);
	for(int i = 0; i < result.size(); i++)
	{
		cout << *result[i];
	}
	changeBookStatus(1);
}

/*
print all the books in the system
*/
void LibraryManager::printBookReport()
{
	cout.unsetf(ios::right);
	cout << setw(26) << setiosflags(ios::left) << "Title ";
	cout << setw(16) << "Author ";
	cout.unsetf(ios::left);
	cout << setw(8) << setiosflags(ios::right) << "Edition ";
	cout.unsetf(ios::right);
	cout << setw(12) << setiosflags(ios::left) << "Category ";
	cout.unsetf(ios::left);
	cout << setw(7) << "Copies" << " " << setw(7) << "Borrows" << endl; 
	cout.unsetf(ios::left);

	dataHolder.printBookVec();	
}

/*
print report of book copy with option 
*/
void LibraryManager::printBookCopyReport(int type)
{
	if(type != 4)
	{
		cout.unsetf(ios::right);
		cout << setw(16) << setiosflags(ios::left) << "Barcode ";
		cout << setw(12) << "Status ";	
		cout << setw(13) << "ISBN ";
		cout.unsetf(ios::left);
		cout << setw(9) << setiosflags(ios::right) << "Duration ";
		cout.unsetf(ios::right);
		cout << setiosflags(ios::left) << "Borrow date" << endl;
		cout.unsetf(ios::left);
	}
	if(type == 1)
	{
		dataHolder.printBookCopyVec(dataHolder.getBookCopyVec());
	}
	else if(type == 2)
	{
		dataHolder.printBookCopyVec(dataHolder.searchBookCopyOverdue());		
	}
	else if(type == 3)
	{
		dataHolder.printBookCopyVec(dataHolder.searchBookCopyBorrowed());
	}
	else /* type should be 4 */
	{
		string isbn = Utilities::readString(cin, 16, "ISBN"); /* this statement shouldn't be here */
		
		cout.unsetf(ios::right);
		cout << setw(16) << setiosflags(ios::left) << "Barcode ";
		cout << setw(12) << "Status ";	
		cout << setw(13) << "ISBN ";
		cout.unsetf(ios::left);
		cout << setw(9) << setiosflags(ios::right) << "Duration ";
		cout.unsetf(ios::right);
		cout << setiosflags(ios::left) << "Borrow date" << endl;
		cout.unsetf(ios::left);

		dataHolder.printBookCopyVec(dataHolder.searchBookCopyISBN(isbn));
	}
}
/*
print borrower report with option 
*/
void LibraryManager::printBorrowerReport(int type)
{
	cout.unsetf(ios::right);
	cout << setiosflags(ios::left) << setw(13) << "ID ";
	cout << setiosflags(ios::left) << setw(23) << "Name ";
	cout << setiosflags(ios::left) << setw(6) << "Department ";
	cout.unsetf(ios::left);
	cout << setiosflags(ios::right) << setw(8) << "Borrows ";
	cout << setiosflags(ios::right) << "ReturnLate" << endl;
	if(type == 1)
	{
		dataHolder.printBorrowerVec(dataHolder.getBorrowerVec());
	}
	else if(type == 2)
	{
		dataHolder.printBorrowerVec(dataHolder.searchBorrowerOverdue());
	}	
}

/*
Sort book list of system provided type of sort
*/
void LibraryManager::sortBook(int type)
{
	dataHolder.sortBookVec(type);
	cout << "The book list has been sorted by ";
	cout << ( (type == 1) ? "title":(type == 2) ? "author": "number of copies") << endl;	
}

/*
Sort borrower list of system provided type of sort
*/
void LibraryManager::sortBorrower(int type)
{
	dataHolder.sortBorrowerVect(type);
	cout << "The borrower list has been sorted by ";
	cout << ( (type == 1) ? "name":"number of borrows") << endl;
}

/*
Save system data to textfiles
*/
void LibraryManager::save(char* bookFile, char* bookCopyFile, char* borrowerFile, char* loanFile)
{
	ofstream ofs;
	/* clear what already in the file */
	ofs.open(bookFile);
	ofs.close();
	ofs.open(bookCopyFile);
	ofs.close();
	ofs.open(borrowerFile);
	ofs.close();
	ofs.open(loanFile);
	ofs.close();

	dataHolder.save(bookFile, bookCopyFile, borrowerFile, loanFile);
}

/*
Load back data from textfiles into memory
*/
void LibraryManager::load(char* bookFile, char* bookCopyFile, char* borrowerFile, char* loanFile)
{
	dataHolder.load(bookFile, bookCopyFile, borrowerFile, loanFile);
}
