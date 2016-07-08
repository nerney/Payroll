#pragma once

#include "Employee.h"
#include <string>

class SalariedEmployee :
	public Employee
{
	double salary;

public:
	SalariedEmployee(const std::string&, const std::string&, const Date&, const std::string&, double);

	~SalariedEmployee();

	void setSalary(double);

	double getSalary() const;

	double earnings() const override;

	void print() const override;
};
