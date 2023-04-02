#pragma once

class Time
{
protected:
    int hour;

public:
    Time() {}
    Time(int hour)
    {
        setHour(hour);
    }

    // getters
    int getHour() { return hour; }

    // setters
    void setHour(int hour) { this->hour = hour; }
};