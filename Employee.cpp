#pragma once
#include "Employee.h"
#include <iostream>
using namespace std;

Employee::Employee(const string& fn, const string& ln, const Date& bd, const string& n)
	: first_name{ fn }, last_name{ ln }, birth_date{ bd }, ssn{ n }, total_earnings{ 0 }
{}

Employee::~Employee()
{}

string Employee::getFirstName() const
{
	return first_name;
}

void Employee::setFirstName(const string& fn)
{
	first_name = fn;
}

string Employee::getLastName() const
{
	return last_name;
}

void Employee::setLastName(const string& ln)
{
	last_name = ln;
}

Date Employee::getBday() const
{
	return birth_date;
}

void Employee::setBday(const Date& bd)
{
	birth_date = bd;
}

string Employee::getSsn() const
{
	return ssn;
}

void Employee::setSsn(const string& n)
{
	ssn = n;
}

void Employee::addToTotal(double x)
{
	total_earnings += x;
}

double Employee::getTotal() const
{
	return total_earnings;
}

void Employee::print() const
{
	cout << getFirstName() << " " << getLastName() << "\nBirthday: " << birth_date.toString() << "\nSocial Security Number : " << getSsn() << endl;
}
