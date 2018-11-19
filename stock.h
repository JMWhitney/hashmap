#ifndef _STOCK_H_
#define _STOCK_H_

// do not change this file except to add private members

#include "date.h"
#include "iomanip"
#include "cstring"

class Stock
{
public:
	Stock(char const * const symbol, char const * const name, int sharePrice, Date priceDate);
		// sharePrice is given as a number of CENTS
	Stock(void);								// default constructor
	~Stock(void);								// destructor
	char const * const getSymbol(void) const;	// returns a pointer to the symbol string

	// you can choose to implement any of the next 3 items if you need them --
	// if not, feel free not to implement them
	Stock(const Stock& s);						// copy constructor
	Stock& operator=(const Stock& s);			// operator= overload
	Stock& operator=(Stock const * const s);	// another operator= overload

	// display column headers for printout of stocks
	static void displayHeaders(std::ostream& out);
		// print something like this:
		//
		//  symbol  name                                      price   date
		//  ------  ----                                      -----   ----

	// print stock instance. Share price should be printed as DOLLARS
	// (e.g. 2483 would print out as 24.83 and 200 would print out as 2.00).
	friend std::ostream& operator<<(std::ostream& out, const Stock& s);

	friend class HashMap;

private:
	static const int  	columnWidths[4];

	char* 	symbol;
	char* 	name;
	int 	sharePrice;
	Date 	priceDate;
};

#endif
