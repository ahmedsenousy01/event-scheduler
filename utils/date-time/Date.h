#pragma once

class Date
{
protected:
    int day, month;
    static int year;

public:
    Date() {}
    Date(int month, int day)
    {
        setMonth(month);
        setDay(day);
    }

    // getters
    int getDay() { return day; }
    int getMonth() { return month; }
    int getYear() { return year; }

    // setters
    void setDay(int day) { this->day = day; }
    void setMonth(int month) { this->month = month; }
    void setYear(int year) { Date::year = year; }
};

int Date::year = 2023;