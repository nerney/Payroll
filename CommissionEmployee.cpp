#include "CommissionEmployee.h"
#include <stdexcept>
#include <iostream>
using namespace std;
CommissionEmployee::CommissionEmployee(const string& fn, const string& ln, const Date& d, const string& n, double s, double r)
    : Employee(fn, ln, d, n)
{
    setSales(s);
    setRate(r);
}
CommissionEmployee::CommissionEmployee() : CommissionEmployee(" ", " ", Date(1, 1, 1900), "000-00-000", 0.0, 0.0)
{}
CommissionEmployee::~CommissionEmployee()
{}
void CommissionEmployee::setSales(double s)
{
    if (s < 0.0)
    {
        throw invalid_argument("negative sales entered");
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
        throw invalid_argument("negative rate entered");
    }
    if (r > 1.0)
    {
        throw invalid_argument("excessive rate entered");
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
    cout << "Commission Employee: ";
    Employee::print();
    cout << "Gross Sales : " << getSales() << "\nCommission Rate: " << getRate() << endl;
}
