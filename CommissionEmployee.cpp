#pragma once
#include "CommissionEmployee.h"
#include <stdexcept>
#include <iostream>

CommissionEmployee::CommissionEmployee(const std::string& fn, const std::string& ln, const Date& d, const std::string& n, double s, double r)
	: Employee(fn, ln, d, n)
{
	setSales(s);
	setRate(r);
}

CommissionEmployee::CommissionEmployee() : Employee("", "", Date(1, 1, 1900), ""), sales{ 0 }, rate{ 0 }
{}

CommissionEmployee::~CommissionEmployee()
{}

void CommissionEmployee::setSales(double s)
{
	if (s < 0.0)
	{
		throw std::invalid_argument("negative sales entered");
	}
	sales = s;
}

double CommissionEmployee::getSales() const
{
	return sales;
}

void CommissionEmployee::setRate(double r)
{
	if (r < 0.0)
	{
		throw std::invalid_argument("negative rate entered");
	}
	if (r > 1.0)
	{
		throw std::invalid_argument("excessive rate entered");
	}
	rate = r;
}

double CommissionEmployee::getRate() const
{
	return rate;
}

double CommissionEmployee::earnings() const
{
	return sales * rate;
}

void CommissionEmployee::print() const
{
	std::cout << "Commission Employee: ";
	Employee::print();
	std::cout << "Gross Sales : " << getSales() << "\nCommission Rate: " << getRate() << std::endl;
}
