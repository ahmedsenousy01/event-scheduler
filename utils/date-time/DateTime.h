#pragma once
#include <iostream>
#include "Date.h"
#include "Time.h"
#include <sstream>
#include <string>
#include <unordered_map>
using namespace std;

struct Month{
    int number;
    string name;
    int length;
};

class DateTime
{
protected:
    Date date;
    Time time;
public:
    static unordered_map<int, Month> calendarMonths;

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
        m += (date.getMonth() * calendarMonths[date.getMonth()].length * 24 * 60);
        m += (date.getDay() * 24 * 60);
        m += (time.getHour() * 60);

        return m;
    }

    string to_ddmmyyyy_hhmm()
    {
        stringstream s;
        s << date.getDay() << "/" << date.getMonth() << "/" << date.getYear() 
            << " [" << time.getHour() << ":00]";
        string res;
        getline(s, res);
        return res;
    }
};

unordered_map<int, Month> DateTime::calendarMonths = {
    {1, {1, "January", 31}},
    {2, {2,"February", 28}},
    {3, {3, "March", 31}},
    {4, {4, "April",30}},
    {5, {5, "May", 31}},
    {6, {6, "June", 30}},
    {7, {7, "July", 31}},
    {8, {8, "August", 31}},
    {9, {9, "September",30}},
    {10, {10, "October", 31}},
    {11, {11, "November", 30}},
    {12, {12, "December", 31}}
};