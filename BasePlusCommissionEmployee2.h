#pragma once
#include "CommissionEmployee.h"
class BasePlusCommissionEmployee2
{
    double salary;
    CommissionEmployee self;
public:
    BasePlusCommissionEmployee2(const std::string&, const std::string&, const Date&, const std::string&, double, double, double);
    ~BasePlusCommissionEmployee2();
    void setSelf(const CommissionEmployee&);
    CommissionEmployee getSelf() const;
    void setSalary(double);
    double getSalary() const;
    double earnings() const;
    void print() const;
};
