// Payroll.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include <vector>
#include "Employee.h"
#include "SalariedEmployee.h"
#include "Date.h"
#include "CommissionEmployee.h"
#include "BasePlusCommissionEmployee.h"
#include "BasePlusCommissionEmployee2.h"
using namespace std;

void testClass()
{
    BasePlusCommissionEmployee2 empl("John", "Composition", Date(6, 4, 1980), "123-12-1234", 1000.0, .1, 200.0);
    empl.print();
    cout << "Earnings: " << empl.earnings() << endl;
}

vector<Employee*> make_staff()
{
    SalariedEmployee a("Julie", "Salary", Date(2, 14, 1976), "222-33-4444", 600.0);
    CommissionEmployee b("Julianne", "Plimpton", Date(8, 3, 1988), "666-46-6969", 790.0, .08);
    BasePlusCommissionEmployee c("Caitlin", "Ainsley", Date(8, 9, 2002), "874-97-6669", 533.00, .02, 250.0);
    vector<Employee*> staff(3);
    staff[0] = &a;
    staff[1] = &b;
    staff[2] = &c;
    return staff;
}

void doPayroll(const Date& date, const vector<Employee*>& staff)
{
    cout << date.toString();
    for (Employee* e : staff)
    {
        e->print();
        cout << "This Month's Earnings: " << e->earnings() << endl;
        cout << "Total Earnings " << e->getTotal() << endl;
    }
}

int main()
{
    testClass();
    cout << endl;

    vector<Employee*> staff = make_staff();
    for (Employee* p : staff)
    {
        p->print();
        cout << "Earnings: " << p->earnings() << endl << endl;
    }

    Date date(1, 1, 1990);
    int m = date.getMonth();
    for (int d = 0; d < 1500; d++)
    {
        if (date.getMonth() != m)
        {
            m = date.getMonth();
            doPayroll(date, staff);
        }
    }
}
