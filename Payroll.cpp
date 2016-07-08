#pragma once
#include <vector>
#include <iostream>
#include "Employee.h"
#include "SalariedEmployee.h"
#include "BasePlusCommissionEmployee2.h"
#include "BasePlusCommissionEmployee.h"
#include "CommissionEmployee.h"
#include "Date.h"

void testClass()	// Test BasePlusCommission2, the class using composition instead of inheritance.
{
	BasePlusCommissionEmployee2 empl("John", "Composition", Date(1, 5, 1980), "111-22-3333", 800.0, .08, 200.0);
	empl.print();
	std::cout << "Earnings: " << empl.earnings() << std::endl;
	std::cout << std::endl;
}

int main()
{
	testClass();

	// Make one of each kinds of employees
	SalariedEmployee a("Jacob", "Salary", Date(2, 10, 1975), "222-33-4444", 600.0);
	CommissionEmployee b("Julianne", "Commission", Date(4, 20, 1990), "555-66-7777", 800.0, .08);
	BasePlusCommissionEmployee c("Caitlin", "Basecomm", Date(10, 2, 2002), "888-99-1010", 800.0, .08, 200.0);

	// Make a vector for the employees
	std::vector<Employee*> staff(3);
	staff[0] = &a;
	staff[1] = &b;
	staff[2] = &c;

	// Print each employee and their earnings
	for (Employee* p : staff)
	{
		p->print();
		std::cout << "Earnings: " << p->earnings() << std::endl << std::endl;
	}

	// Start at a date and go through 366 days
	Date date(1, 1, 2010);
	for (int days = 0; days < 366; days++) {
		if (date.getDay() == 1) // Do payroll on the first of the month
		{
			for (Employee* p : staff)
			{
				p->print();
				if (p->getBday().getMonth() == date.getMonth()) // Test for employee birthday month
				{
					std::cout << "Earnings w/ Bonus: " << (p->earnings() + 100.0) << std::endl << std::endl;
				}
				else
				{
					std::cout << "Earnings: " << p->earnings() << std::endl << std::endl;
				}
			}
		}
		++date;
	}
}
