#pragma once
#include <iostream>
#include <unordered_map>
#include "../event/Event.h"
using namespace std;

class Calendar
{
public:
    static void initSchedule(unordered_map<int, unordered_map<int, unordered_map<int, bool>>> &schedule)
    {
        for (int i = 1; i <= 12; i++)
        {
            unordered_map<int, unordered_map<int, bool>> days;
            for (int j = 1; j <= 30; j++)
            {
                unordered_map<int, bool> hours;
                for (int k = 0; k <= 23; k++)
                {
                    hours[k] = false;
                }
                days[j] = hours;
            }
            schedule[i] = days;
        }
    }

    static bool reserveEvent(Event &e, unordered_map<int, unordered_map<int, unordered_map<int, bool>>> &schedule)
    {
        bool timeAvailable = checkForEventDateTimeAvailability(e, schedule);
        if(timeAvailable)
        {
            int startMonth = e.getStartDateTime().getDate().getMonth();
            int startDay = e.getStartDateTime().getDate().getDay();
            int startHour = e.getStartDateTime().getTime().getHour();

            int endMonth = e.getEndDateTime().getDate().getMonth();
            int endDay = e.getEndDateTime().getDate().getDay();
            int endHour = e.getEndDateTime().getTime().getHour();

            for(int i = startMonth; i <= endMonth; i++)
            {
                for(int j = startDay; j <= endDay; j++)
                {
                    for(int k = startHour; k <= endHour; k++)
                    {
                        schedule[i][j][k] = true;
                    }
                }
            }
        }
        return timeAvailable;
    }

    static bool checkForEventDateTimeAvailability(Event &e, unordered_map<int, unordered_map<int, unordered_map<int, bool>>> &schedule)
    {
        int months = (e.getStartDateTime().getDate().getMonth() - e.getEndDateTime().getDate().getMonth()) || 1;
        int days = e.getStartDateTime().getDate().getDay() - e.getEndDateTime().getDate().getDay();
        int hours = e.getStartDateTime().getTime().getHour() - e.getEndDateTime().getTime().getHour();
        for(int i = 0; i < months; i++)
        {
            for(int j = 0; j < days; j++)
            {
                for(int k = 0; k < hours; k++)
                {
                    if(schedule[i][j][k]) return false;
                }
            }
        }
        return true;
    }
    static void displaySchedule(unordered_map<int, unordered_map<int, unordered_map<int, bool>>> &schedule)
    {
        for (int i = 1; i <= 12; i++)
        {
            for (int j = 1; j <= 30; j++)
            {
                for (int k = 0; k <= 23; k++)
                {
                    printf("%d:00 %d/%d => %d\n", k, i, j, schedule[i][j][k]);
                }
            }
        }
    }
};