/*========================================================================================
	Object Oriented Programming COCS2131 - Assignment 2 - Library system
	@author       : Nguyen Hoang Giang
	student Number: s3090347
	instructor    : Barend Scholtus
	Date          : 20/09/2005

  ========================================================================================
*/
// Borrower.cpp: implementation of the Borrower class.
//
//////////////////////////////////////////////////////////////////////

#include "Borrower.h"
#include "Utilities.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
vector<string> Borrower::idList;
string Borrower::TYPE[] = {"Student", "Staff"};
string Borrower::DEPARTMENT[] = {"IS", "BCOMM", "UPP"};
int Borrower::posCount = 0;

Borrower::Borrower()
{
	id = "";
	name = "";
	type = STUDENT;
	department = IS;
	phoneNum = "";
	noOfBorrow = 0;
	noOfReturnLate = 0;
}

Borrower::~Borrower()
{

}

/*
Write all attributes of this borrower to textfile
*/
void Borrower::writeAttributes(char* fileName)
{
	ofstream of;
	of.open(fileName, ios::app);
	ostringstream ost;
	
	ost << id << ":";
	ost << name << ":";
	ost << getType() << ":";
	ost << getDepartment() << ":";
	ost << getPhoneNum() << ":";
	ost << noOfBorrow << ":";
	ost << noOfReturnLate << "\n";

	string data = ost.str();
	Utilities::writeString(data, of);
}

/*
read attributes for this borrower from textfile
*/
void Borrower::readAttributes(char* fileName)
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

	id = strtok(s, ":");
	name = strtok(NULL, ":");
	type = static_cast<Type> (atoi(strtok(NULL, ":")));
	department = static_cast<Department> (atoi(strtok(NULL, ":")));
	phoneNum = strtok(NULL, ":");
	noOfBorrow = atoi(strtok(NULL, ":"));
	noOfReturnLate = atoi(strtok(NULL, ":"));
}

/*
Overload extraction operator
*/
ostream& operator<<(ostream& os, Borrower& b)
{
	return b.printDetailsList(os);
}

/*
Overload insertion operator
*/
istream& operator>>(istream& is, Borrower& b)
{
	return b.getDetails(is);
}

/*
Quick Listing of attributes on 1 line
*/
ostream& Borrower::printDetailsList(ostream& os)
{
	os.unsetf(ios::right);
	os << setiosflags(ios::left) << setw(12) << id << " ";
	os << setw(22) << name << " ";
	os << setw(10) << Borrower::DEPARTMENT[getDepartment()] << " ";
	os.unsetf(ios::left);
	os << setiosflags(ios::right) << setw(7) << noOfBorrow << " ";
	os << setw(10) << noOfReturnLate << endl;
	
	return os;
}

/*
print Detail of this borrower
*/
void Borrower::printDetails(ostream& os)
{
	os << "ID: " << id << "\n";
	os << "Name: " << name << "\n";
	os << "Type: " << Borrower::TYPE[getType()] << "\n";
	os << "Department: " << Borrower::DEPARTMENT[getDepartment()] << "\n";
	os << "Phone number: " << phoneNum << "\n";
	os << "Number of borrows: " << noOfBorrow << "\n";
	os << "Number of return late: " << noOfReturnLate << endl;
}

/*
input details for this borrower
*/
istream& Borrower::getDetails(istream& is)
{
	string tmpID = Utilities::readString(is, 21, "ID");
	vector<string>::iterator iter = Borrower::idList.begin();

	while(iter != Borrower::idList.end())
	{
		if(*iter++ == tmpID)
		{
			cout << "This ID already exists" << endl;
			return is;
		}
	}

	Borrower::idList.push_back(tmpID);
	id = tmpID;
	name = Utilities::readString(is, 41, "Name");
	type = static_cast<Type> (Utilities::readStringOptions(is, 2, TYPE));
	department = static_cast<Department> (Utilities::readStringOptions(is, 3, DEPARTMENT));
	phoneNum = Utilities::readString(is, 16, "Phone number");
	Utilities::readInt(is, noOfBorrow, "Number of borrows");
	Utilities::readInt(is, noOfReturnLate, "Number of borrows return late");

	return is;
}
/*
Overload less operator comparision
*/
bool Borrower::operator<(const Borrower& b1) const
{
	return id < b1.id;
}

/*
Overload equal operator comparision
*/
bool Borrower::operator==(const Borrower& b1) const
{
	return id == b1.id;
}
