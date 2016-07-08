#pragma once
#include "Date.h"
#include <stdexcept>
using namespace std;

const int Date::days[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

const string Date::months[] = { "","January","February","March","April","May","June","July","August","September","October","November","December" };

Date::Date(int m, int d, int y)
{
	setDate(m, d, y);
}

Date::Date() :
	Date(1, 1, 1900)
{}

Date::~Date()
{}

void Date::setDate(int m, int d, int y)
{
	if (m <= 12 && m >= 1)
	{
		month = m;
	}
	else
	{
		throw invalid_argument("month must be 1-12");
	}
	if (y >= 1900 && y <= 2099)
	{
		year = y;
	}
	else
	{
		throw invalid_argument("year must be after 1899 or before 2100");
	}
	if ((month == 2 && leapYear(year) && d >= 1 && d <= 29) || (d >= 1 && d <= days[month]))
	{
		day = d;
	}
	else
	{
		throw invalid_argument("day out of range for current month/year");
	}
}

Date& Date::operator++()
{
	helper();
	return *this;
}

Date Date::operator++(int)
{
	auto temp = *this;
	helper();
	return *this;
}

Date& Date::operator+=(int addDays)
{
	for (auto i = 0; i < addDays; i++)
	{
		helper();
	}
	return *this;
}

bool Date::leapYear(int yr)
{
	return (yr % 400 == 0 || (yr % 100 != 0 && yr % 4 == 0));
}

bool Date::endOfMonth(int dy) const
{
	if (month == 2 && leapYear(year))
	{
		return dy == 29;
	}
	return dy == days[month];
}

string Date::toString() const
{
	return months[month] + " " + to_string(day) + ", " + to_string(year);
}

int Date::getMonth() const
{
	return month;
}

int Date::getDay() const
{
	return day;
}

void Date::helper()
{
	if (!endOfMonth(day))
	{
		day++;
	}
	else if (month < 12)
	{
		month++;
		day = 1;
	}
	else
	{
		year++;
		month = 1;
		day = 1;
	}
}
