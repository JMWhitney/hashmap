#include "hashmap.h"

using namespace std;

// change the value of this variable to be your own name instead of "I. Forgot"
const char	HashMap::YOUR_NAME[] = "Justin Whitney";

HashMap::HashMap(unsigned int capacity) :
				capacity{capacity},
				nStocks{0}
{
	slots = new Slot[capacity];

}

HashMap::~HashMap(void)
{
	delete [] slots;
}

void HashMap::incr(unsigned int& i) const {
	i++;
	if(i >= capacity) {
		i = 0;
	}
	return;
}
bool HashMap::get(char const * const symbol, Stock& s,
				  unsigned int& symbolHash, unsigned int& hashIndex,
				  unsigned int& usedIndex, unsigned int& seqLength)
	 const
{
	//Hash symbol and modulo it by capacity to get the hashindex
	// Go to the array position that corresponds to hashindex
	// Linear probe the array until the key is found, or all the non-null stocks have been searched.
	// If all the non-null stocks have been searched (count == nStocks) then
	// the key is not on the map. Return false.
	// If the symbol is not found, this function is required
	// to set usedIndex to -1 before it returns false.
	symbolHash = hashStr(symbol);
	hashIndex = symbolHash % capacity;
	unsigned int i{hashIndex};
	unsigned int count{0};

		seqLength = 1;
		while(strcmp(slots[i].slotStock.symbol , symbol) && count != nStocks) {
			if(strcmp(slots[i].slotStock.symbol , "")) {
				count++;
			}
			incr(i);
			seqLength++;
		}
		if(count == nStocks) {
			usedIndex = -1;
			return false;
		}
		usedIndex = i;
		return true;
}

bool HashMap::put(const Stock& s,
				  unsigned int& symbolHash, unsigned int& hashIndex,
				  unsigned int& usedIndex, unsigned int& seqLength)
{
	// Hash symbol and modulo it by capacity to find hashindex
	// If the array is full don't do anything else. Return false.
	// Else linear probe the hashmap and insert at the first empty spot,
	// Or return if the stock is already on the map.
	// keeping track of #spots traversed.
	symbolHash = hashStr(s.symbol);
	hashIndex = symbolHash % capacity;
	if(nStocks == capacity) {
		usedIndex = -1;
		seqLength = 0;
		return false;
	} else {
		unsigned int i{hashIndex};
		seqLength = 1;
		while(strcmp(slots[i].slotStock.symbol , "") && strcmp(slots[i].slotStock.symbol , s.symbol)) {
			incr(i);
			seqLength++;
		}
		if(!strcmp(slots[i].slotStock.symbol , s.symbol)) {
			usedIndex = i;
			return false;
		}
		slots[i].slotStock = s;
		nStocks++;
		usedIndex = i;
		return true;
	}
}

bool HashMap::remove(char const * const symbol, Stock& s,
					 unsigned int& symbolHash, unsigned int& hashIndex,
					 unsigned int& usedIndex, unsigned int& seqLength)
{
	//Use get function to determine if the item we want to remove is on the map.
	//If it isn't, don't do anything. If it is on the map, go to the index
	//given by get and set the stock there to default values. (null)
	if(this->get(symbol, s, symbolHash, hashIndex, usedIndex, seqLength)) {
		slots[usedIndex].slotStock = s;
		nStocks--;
		return true;
	} else {
		return false;
	}
}

unsigned int HashMap::hashStr(char const * const s)
{
	// Hash C string argument using the formula in java.lang.String.hashCode():
	//
	//   s[0]*(31^(n-1)) + s[1]*(31^(n-2)) + ... + s[n-1]
	//
	// s is the array of characters, n is the number of characters in the string,
	// and 31^n means 31 to the nth power.
	//
	// This function is declared static because its result depends
	// only on the characters in the string. You will need to apply
	// the modulo operator to the result of this function to generate
	// the required table index. The place to do this is in the functions
	// that call this function.
	//
	// You can and should do this computation entirely with integers. In other
	// words, there is no need to use floating point values. In particular, you
	// should not use the pow() function from <math.h> in this lab.

	//vars
	unsigned int 		total{0};
	unsigned int 		power{1};
	long unsigned int 	n{strlen(s)};

	for(unsigned int i = 0; i < n; i++) { 		 //Loop to compute the sum of each product
		power = 1;						 //Reset working product
		for(unsigned int j = 0; j < n-i-1; j++) { //Loop to compute the products
			power = (power<<5) - power;  //Left shifting is faster than multiplication
		}
		power *= s[i];					 //Multiply exponent by character at that position
		total += power;					 //Add to the working total
	}
	return total;
}

ostream& operator<<(ostream& out, const HashMap &h)
{
	//out << "<print the contents of the HashMap>" << endl;
		if(h.nStocks == 0) {
			out << "empty";
			return out;
		}
		h.slots[0].slotStock.displayHeaders(out);
	    for (unsigned int i = 0; i < h.capacity; i++) {
			out << h.slots[i].slotStock;
		}
	return out;
}
