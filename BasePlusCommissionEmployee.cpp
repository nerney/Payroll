#pragma once

#include "BasePlusCommissionEmployee.h"
#include <stdexcept>
#include <iostream>
using namespace std;

BasePlusCommissionEmployee::BasePlusCommissionEmployee(const string& fn, const string& ln, const Date& d, const string& n, double s, double r, double b)
	: CommissionEmployee(fn, ln, d, n, s, r)
{
	setSalary(b);
}

BasePlusCommissionEmployee::~BasePlusCommissionEmployee()
{}

void BasePlusCommissionEmployee::setSalary(double b)
{
	if (b < 0.0)
	{
		throw invalid_argument("negative salary entered");
	}
	salary = b;
}

double BasePlusCommissionEmployee::getSalary() const
{
	return salary;
}

double BasePlusCommissionEmployee::earnings() const
{
	return CommissionEmployee::earnings() + salary;
}

void BasePlusCommissionEmployee::print() const
{
	cout << "Salaried ";
	CommissionEmployee::print();
	cout << "Base Salary: " << getSalary() << endl;
}
