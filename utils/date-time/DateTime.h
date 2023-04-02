#pragma once
#include "Date.h"
#include "Time.h"

class DateTime
{
protected:
    Date date;
    Time time;

public:
    DateTime() {}
    DateTime(Date date, Time time)
    {
        setDate(date);
        setTime(time);
    }
    DateTime(int month, int day, int hour)
    {
        Date d(month, day);
        Time t(hour);
        setDate(d);
        setTime(t);
    }

    // getters
    Date getDate() { return this->date; }
    Time getTime() { return this->time; }

    // setters
    void setDate(Date date) { this->date = date; }
    void setTime(Time time) { this->time = time; }

    // extra
    int returnDateTimeInMinutes()
    {
        int m = 0;
        m += (this->getDate().getMonth() * 30 * 24 * 60);
        m += (this->getDate().getDay() * 24 * 60);
        m += (this->getTime().getHour() * 60);

        return m;
    }
};