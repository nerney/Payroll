#pragma once
#include <string>
class Date
{
    int month;
    int day;
    int year;
    static const int days[];
    static const std::string months[];
public:
    Date(int, int, int);
    Date();
    ~Date();
    void setDate(int, int, int);
    Date& operator++();
    Date operator++(int);
    Date& operator+=(int);
    static bool leapYear(int);
    bool endOfMonth(int) const;
    std::string toString() const;
    int getMonth() const;
private:
    void helper();
};
