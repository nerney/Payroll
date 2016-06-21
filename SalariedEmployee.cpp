#include "SalariedEmployee.h"
#include <iostream>
#include <stdexcept>
using namespace std;

SalariedEmployee::SalariedEmployee(const string& fn, const string& ln, const Date& d, const string& n, double s)
	: Employee(fn, ln, d, n)
{
	setSalary(s);
}
SalariedEmployee::~SalariedEmployee()
{
}
void SalariedEmployee::setSalary(double s)
{
	if (s < 0.0)
	{
		throw invalid_argument("negative salary entered");
	}
	salary = s;
}
double SalariedEmployee::getSalary() const
{
	return salary;
}
double SalariedEmployee::earnings() const
{
	return salary;
}
void SalariedEmployee::print() const
{
	cout << "Salaried Employee: ";
	Employee::print();
	cout << "Weekly Salary: " << getSalary() << endl;
}
