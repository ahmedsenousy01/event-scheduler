#pragma once
#include <unordered_map>
#include "../event/Event.h"
using namespace std;

class Calendar
{
protected:
    unordered_map<int, unordered_map<int, unordered_map<int, bool>>> schedule;

public:
    Calendar()
    {
        for (int i = 1; i <= 12; i++)
        {
            unordered_map<int, unordered_map<int, bool>> days;
            for (int j = 1; j <= 30; j++)
            {
                unordered_map<int, bool> hours;
                for (int k = 1; k <= 24; k++)
                {
                    hours[k] = false;
                }
                days[j] = hours;
            }
            schedule[i] = days;
        }
    }

    unordered_map<int, unordered_map<int, unordered_map<int, bool>>> getSchedule() { return this->schedule; }

    bool reserveEvent(Event &e)
    {

    }

    bool checkForEventDateTimeAvailability(Event &e)
    {

    }
};