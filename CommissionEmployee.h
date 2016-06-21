#pragma once
#include "Employee.h"
#include <string>

class CommissionEmployee :
	public Employee
{
	double sales;
	double rate;
public:
	CommissionEmployee(const std::string&, const std::string&, const Date&, const std::string&, double, double);
	CommissionEmployee();
	~CommissionEmployee();

	void setSales(double);
	double getSales() const;
	void setRate(double);
	double getRate() const;

	double earnings() const override;
	void print() const override;
};
