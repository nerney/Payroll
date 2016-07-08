#pragma once

#include "Date.h"

class Employee
{
	std::string first_name;

	std::string last_name;

	Date birth_date;

	std::string ssn;

	double total_earnings;

public:
	Employee(const std::string&, const std::string&, const Date&, const std::string&);

	virtual ~Employee();

	std::string getFirstName() const;

	void setFirstName(const std::string&);

	std::string getLastName() const;

	void setLastName(const std::string&);

	Date getBday() const;

	void setBday(const Date&);

	std::string getSsn() const;

	void setSsn(const std::string& ssn);

	void addToTotal(double);

	double getTotal() const;

	virtual double earnings() const = 0;

	virtual void print() const;
};
