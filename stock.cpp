#include <iomanip>
#include "stock.h"
#include <cstring>

using namespace std;

const int Stock::columnWidths[4] = {8, 35, 10, 5};

Stock::Stock(char const * const symbol, char const * const name, int sharePrice, Date priceDate) :
		symbol{new char[strlen(symbol) + 1]},
		name{new char[strlen(name) + 1]},
		sharePrice{sharePrice},
		priceDate{priceDate}
{
	//Deep copy string data
	strcpy(this->symbol, symbol);
	strcpy(this->name, name);
}

Stock::Stock(void) :
			symbol{new char[1]},
			name{new char[1]},
			sharePrice{0},
			priceDate{}
{
	strcpy(this->symbol , ""); //Have to do deep copy of string literal otherwise destructor segfaults.
	strcpy(this->name , "");
} 


Stock::~Stock(void)
{
	delete [] name;
	delete [] symbol;
}

char const * const Stock::getSymbol(void) const
{
	return symbol;
}

/*
you can choose to implement any of the next 3 items if necessary --
if not, feel free not to implement them

Stock::Stock(const Stock& s)
{
}
*/
Stock& Stock::operator=(const Stock& s)
{
	//Clear any previous dynamically allocated stock values
	//Then deep copy the values from the stock being passed.
	delete [] symbol;
	delete [] name;
	symbol = new char[strlen(s.symbol)+1];
	name = new char[strlen(s.name)+1];
	strcpy(symbol , s.symbol);
	strcpy(name , s.name);
	sharePrice = s.sharePrice;
	priceDate = s.priceDate;
	return *this;
}
/*
Stock& Stock::operator=(Stock const * const s)
{
	return *this;
}
*/

// display column headers for printout of stocks
void Stock::displayHeaders(ostream& out)
{
	// print something like this:
	//
	//  symbol  name                                      price   date
	//  ------  ----                                      -----   ----
	out << left << setw(columnWidths[0]) << "Symbol"
		<< left << setw(columnWidths[1]) << "Name"
		<< right << setw(columnWidths[2] + 3) << "Price" << "   "
		<< left << setw(columnWidths[3]) << "Date" << endl
		<< left << setw(columnWidths[0]) << "------"
		<< left << setw(columnWidths[1]) << "----"
		<< right << setw(columnWidths[2] + 3) << "-----" << "   "
		<< left << setw(columnWidths[3]) << "----" << endl;
		
}

// print share price as DOLLARS
// (e.g. 2483 would print out as 24.83 and 200 would print out as 2.00)
ostream& operator<<(ostream& out, const Stock& s)
{
	if (!strcmp(s.symbol , "")) { //Don't print empty stocks
		return out;
	}
	//Otherwise print the stocks with the correct formatting
	out << left << setw(Stock::columnWidths[0]) << s.symbol
		<< left << setw(Stock::columnWidths[1]) << s.name
		<< right << setw(Stock::columnWidths[2])
		<< s.sharePrice/100 << '.' << setfill('0') << setw(2) << s.sharePrice%100 << setfill(' ')
		<< left <<  setw(3) << ' '
		<< left << setw(Stock::columnWidths[3]) << s.priceDate << endl;
	return out;
}
