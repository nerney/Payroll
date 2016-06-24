#include "BasePlusCommissionEmployee2.h"
#include <stdexcept>
#include <iostream>
using namespace std;
BasePlusCommissionEmployee2::BasePlusCommissionEmployee2(const string& fn, const string& ln, const Date& bd, const string& ssn, double sales, double rate, double base)
{
    setSelf(CommissionEmployee(fn, ln, bd, ssn, sales, rate));
    setSalary(base);
}
BasePlusCommissionEmployee2::~BasePlusCommissionEmployee2()
{}
void BasePlusCommissionEmployee2::setSelf(const CommissionEmployee& e)
{
    self = e;
}
CommissionEmployee BasePlusCommissionEmployee2::getSelf() const
{
    return self;
}
void BasePlusCommissionEmployee2::setSalary(double b)
{
    if (b < 0.0)
    {
        throw invalid_argument("negative salary entered");
    }
    salary = b;
}
double BasePlusCommissionEmployee2::getSalary() const
{
    return salary;
}
double BasePlusCommissionEmployee2::earnings() const
{
    return salary + self.earnings();
}
void BasePlusCommissionEmployee2::print() const
{
    cout << "Salaried ";
    self.print();
    cout << "Base Salary: " << getSalary() << endl;
}
