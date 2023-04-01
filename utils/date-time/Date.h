#pragma once

class Date
{
protected:
    int day, month;

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

    // setters
    void setDay(int day) { this->day = day; }
    void setMonth(int month) { this->month = month; }
};