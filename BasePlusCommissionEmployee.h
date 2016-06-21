#pragma once
#include "CommissionEmployee.h"
#include <string>

class BasePlusCommissionEmployee :
	public CommissionEmployee
{
	double salary;
public:
	BasePlusCommissionEmployee(const std::string&, const std::string&, const Date&, const std::string&, double, double, double);
	~BasePlusCommissionEmployee();

	void setSalary(double);
	double getSalary() const;

	double earnings() const override;
	void print() const override;
};
