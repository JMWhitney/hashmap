#include "date.h"

using namespace std;

Date::Date(Month month, int day, int year) :
		month{month},
		day{day},
		year{year}
{
}

Date::Date() :
		month{INVALID},
		day{0},
		year{0}
{
}

Date::~Date(void)
{
}

ostream& operator<<(ostream& out, const Date& d)
{
	//Switch statements for enums
	switch(d.month) 
	{
	case Date::INVALID :
		out << "Invalid ";
		return out;
	case Date::JANUARY :
		out << "January " << d.day << ", " << d.year;
		break;
	case Date::FEBRUARY :
		out << "February " << d.day << ", " << d.year;
		break;
	case Date::MARCH :
		out << "March " << d.day << ", " << d.year;
		break;
	case Date::APRIL :
		out << "April " << d.day << ", " << d.year;
		break;
	case Date::MAY :
		out << "May " << d.day << ", " << d.year;
		break;
	case Date::JUNE :
		out << "June " << d.day << ", " << d.year;
		break;
	case Date::JULY :
		out << "July " << d.day << ", " << d.year;
		break;
	case Date::AUGUST :
		out << "August" << d.day << ", " << d.year;
		break;
	case Date::SEPTEMBER :
		out << "September " << d.day << ", " << d.year;
		break;
	case Date::OCTOBER :
		out << "October " << d.day << ", " << d.year;
		break;
	case Date::NOVEMBER :
		out << "November " << d.day << ", " << d.year;
		break;
	case Date::DECEMBER :
		out << "December " << d.day << ", " << d.year;
		break;
	}
	return out;
}
