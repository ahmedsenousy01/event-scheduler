#pragma once

class Time
{
protected:
    int hour, minute;

public:
    Time() {}
    Time(int hour, int minute)
    {
        setMinute(minute);
        setHour(hour);
    }

    // getters
    int getHour() { return hour; }
    int getMinute() { return minute; }

    // setters
    void setHour(int hour) { this->hour = hour; }
    void setMinute(int minute) { this->minute = minute; }
};