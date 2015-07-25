#
# This is an example Makefile for a countwords program.  This
# program uses both the scanner module and a counter module.
# Typing 'make' or 'make count' will create the executable file.
#

# define some Makefile variables for the compiler and compiler flags
# to use Makefile variables later in the Makefile: $()
#
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
#
# for C++ define  CC = g++
CC = g++
CFLAGS  = -g -O0 -Wall

# typing 'make' will invoke the first target entry in the file 
# (in this case the default target entry)
# you can name this target entry anything, but "default" or "all"
# are the most commonly used names by convention
#
default: BookStore

# To create the executable file count we need the object files
# countwords.o, counter.o, and scanner.o:
#
BookStore:  main.o Utilities.o Loan.o LibraryManager.o DataHolder.o Borrower.o BookCopy.o Book.o 
	$(CC) $(CFLAGS) -o BookStore main.o Utilities.o Loan.o LibraryManager.o DataHolder.o Borrower.o BookCopy.o Book.o

# To create the object file countwords.o, we need the source
# files countwords.c, scanner.h, and counter.h:
#
	
main.o: main.cpp LibraryManager.h
	$(CC) $(CFLAGS) -c main.cpp

LibraryManager.o: LibraryManager.cpp LibraryManager.h
	$(CC) $(CFLAGS) -c LibraryManager.cpp

DataHolder.o: DataHolder.cpp DataHolder.h Book.h BookCopy.h Borrower.h Utilities.h
	$(CC) $(CFLAGS) -c DataHolder.cpp
	
Borrower.o: Borrower.cpp Borrower.h Utilities.h
	$(CC) $(CFLAGS) -c Borrower.cpp

BookCopy.o: BookCopy.cpp BookCopy.h Utilities.h
	$(CC) $(CFLAGS) -c BookCopy.cpp

Book.o: Book.cpp Book.h Utilities.h
	$(CC) $(CFLAGS) -c Book.cpp

# To start over from scratch, type 'make clean'.  This
# removes the executable file, as well as old .o object
# files and *~ backup files:
#
clean: 
	$(RM) BookStore *.o *~