/*========================================================================================
	Object Oriented Programming COCS2131 - Assignment 2 - Library system
	@author       : Nguyen Hoang Giang
	student Number: s3090347
	instructor    : Barend Scholtus
	Date          : 20/09/2005

  ========================================================================================
*/
#include "LibraryManager.h"
#define WINDOW 0

/*
Prototypes of helper functions
*/
int printMenu(string[], int, int, int);
void newPage();

/*
main function, run the program
*/
int main(void)
{	
   int choice, subChoice1, subChoice2;
	LibraryManager lm;
	string mainMenu[] = {"New book", "New copy", "New borrower", "Borrow book","Return book",
								"Change book status", "Report", "Sort", "Save", "Quit"};
	string changeBookStatusMenu[] = {"Present", "Not present"};
	string reportMenu[] = {"All book", "Book copies", "borrowers"};
	string sortMenu[] = {"Book", "Borrower"};
	string sortBookMenu[] = {"Title", "Author", "Number of copies"};
	string sortBorrowerMenu[] = {"Name", "Number of borrows"};
	string reportBookCopyMenu[] = {"All", "Overdue", "Borrowed", "ISBN"};
	string reportBorrowerMenu[] = {"All", "Overdue"};

	lm.load("book.txt", "bookcopy.txt", "borrower.txt", "loan.txt");

	do
	{
		choice = printMenu(mainMenu, 0, 10, 18);
		switch(choice)
		{
			case 1:
				lm.createBook();
				newPage();
				break;
			case 2:
				lm.createBookCopy();
				newPage();
				break;
			case 3:
				lm.createBorrower();
				newPage();
				break;
			case 4:
				lm.borrowBook();
				newPage();
				break;
			case 5:
				lm.returnBook();
				newPage();
				break;
			case 6:
				subChoice1 = printMenu(changeBookStatusMenu, 1, 2, 11);
				
				if(subChoice1 < 1 || subChoice1 > 2)
				{
					cout << "Wrong choice\n";
				}
				else
				{
					lm.changeBookStatus(subChoice1);
				}

				newPage();
				break;
			case 7:
				subChoice1 = printMenu(reportMenu, 1, 3, 11);

				if(subChoice1 < 1 || subChoice1 > 3)
				{
					cout << "Wrong choice\n";
				}
				else
				{
					if(subChoice1 == 1)
					{
						lm.printBookReport();
					}
					else if(subChoice1 == 2)
					{
						subChoice2 = printMenu(reportBookCopyMenu, 2, 4, 8);
						if(subChoice2 <1 || subChoice2 > 4)
						{
							cout << "Wrong choice\n";
						}
						else
						{
							lm.printBookCopyReport(subChoice2);
						}
					}
					else if(subChoice1 == 3)
					{
						subChoice2 = printMenu(reportBorrowerMenu, 2, 2, 7);
						if(subChoice2 < 1 || subChoice2 > 3)
						{
							cout << "Wrong choice\n";
						}
						else
						{
							lm.printBorrowerReport(subChoice2);
						}
					}
				}
				
				newPage();
				break;
			case 8:
				subChoice1 = printMenu(sortMenu, 1, 2, 8);

				if(subChoice1 == 1)
				{
					subChoice2 = printMenu(sortBookMenu, 2, 3, 16);
					
					if(subChoice2 < 1 || subChoice2 > 3)
					{
						cout << "Wrong choice\n";
					}
					else
					{
						lm.sortBook(subChoice2);
					}
				}
				else if(subChoice1 == 2)
				{
					subChoice2 = printMenu(sortBorrowerMenu, 2, 2, 17);
					
					if(subChoice2 < 1 || subChoice2 > 2)
					{
						cout << "Wrong choice\n";
					}
					else
					{
						lm.sortBorrower(subChoice2);
					}
				}
				else
				{
					cout << "Wrong choice\n";
				}
				
				newPage();
				break;
			case 9:
				lm.save("book.txt", "bookcopy.txt", "borrower.txt", "loan.txt");
				cout << "System data has been saved" << endl;
				newPage();
				break;
			case 10:
				break;
			default:
				cout << "Wrong choice\n" << endl;
				newPage();
		}
	}
	while(choice != 10);

	return 0;
}

/*
Print a menu, providing the options, indent level, number of options and width of field
*/
int printMenu(string menuItems[],int indentLevel, int n, int width)
{
	int choice, i, j;
	
	cout.unsetf(ios::right);
	cout << setiosflags(ios::left);
	for(i = 0; i < n; ++i)
	{
		for(j = 0; j < indentLevel; ++j)
		{
			cout << '\t';
		}
		cout << "|" << i + 1 << ") ";
		if(i >= 9)
		{
			width--;
		}
		cout << setw(width) << setiosflags(ios::left) << menuItems[i] << "|" << endl;
	}

	for(j = 0; j < indentLevel; ++j)
	{
		cout << '\t';
	}

	for(i = 0; i < width+5; ++i)
	{
		cout << '-';
	}
	cout << endl;

	for(i = 0; i < indentLevel; ++i)
	{
		cout << '\t';
	}

	if(!Utilities::readInt(cin, choice, "Choice"))
	{
		return 0;
	}	
	cout.unsetf(ios::left);
	return choice;
}

/*
Append a new page for clearer look
*/
void newPage()
{
	system("read -p \"Press [Enter] key to continue...\"");
	if(WINDOW == 1)
	{
		system("cls");
		return;
	}
	system("clear");
}
