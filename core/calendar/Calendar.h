#pragma once
#include <iostream>
#include <unordered_map>
#include <string>
#include <list>
#include "../event/Event.h"
#include "../../utils/date-time/DateTime.h"
#include <cassert>
using namespace std;

class Calendar
{
    unordered_map<int, list<Event>> schedule;
public:
    bool reserveEvent(Event &e){
        int startMonth = e.getStartDateTime().getDate().getMonth();
        auto eventPosition = schedule[startMonth].begin();
        if (!findEventPositionIfAvailable(eventPosition, e)) {
            return false;
        }
        
        schedule[startMonth].insert(eventPosition, e);
        return true;
    }

    bool findEventPositionIfAvailable(list<Event>::iterator &insertionPosition,Event &e){
        //CHECK START
        int startMonth = e.getStartDateTime().getDate().getMonth();
        
        bool foundPosition = findEventPositionIfStartAvailable(insertionPosition, e);
        if (!foundPosition){
            return false;
        }
        
        //CHECK END
        int endMonth = e.getEndDateTime().getDate().getMonth();
        int endTime = e.getEndDateTime().returnDateTimeInMinutes();

        list<Event>::iterator afterEnd;
        if(endMonth == startMonth){
            afterEnd = insertionPosition;
        } else {
            for(int i = startMonth + 1; i < endMonth;i++){
                if(schedule[i].size()){
                    return false;
                }
            }
            afterEnd = schedule[endMonth].begin();
        }
        
        if (afterEnd == schedule[endMonth].end()) {
            return true;
        }
        else {
            return (*afterEnd).getStartDateTime().returnDateTimeInMinutes() >= endTime;
        }
    }

    bool findEventPositionIfStartAvailable(list<Event>::iterator &insertionPosition,Event &e){
        int startMonth = e.getStartDateTime().getDate().getMonth();
        int startTime = e.getStartDateTime().returnDateTimeInMinutes();
        int endTime = e.getEndDateTime().returnDateTimeInMinutes();

        for(;insertionPosition != schedule[startMonth].end(); insertionPosition++){
            int otherStart = (*insertionPosition).getStartDateTime().returnDateTimeInMinutes();
            if(eventsIntersect(e, (*insertionPosition))){
                return false;
            }
            if (endTime <= otherStart) {
                return true;
            }
        }

        if (insertionPosition == schedule[startMonth].begin()) {
            for (int i = startMonth - 1; i > 0; i--) {
                if (schedule[i].size()) {
                    Event lastEvent = schedule[i].back();
                    return !eventsIntersect(e, lastEvent);
                }
            }
            return true;
        }

        return true;
    }

    bool eventsIntersect(Event &e1, Event &e2){
        int start1 = e1.getStartDateTime().returnDateTimeInMinutes();
        int end1 = e1.getEndDateTime().returnDateTimeInMinutes();

        int start2 = e2.getStartDateTime().returnDateTimeInMinutes();
        int end2 = e2.getEndDateTime().returnDateTimeInMinutes();

        bool intersecting = (start1 >= start2 && start1 < end2) || (start2 >= start1 && start2 < end1);

        if (intersecting) {
            cout << "intersection between: ";
        }
        else {
            cout << "no intersection between: ";
        }

        cout << e1.summary() << " and " << e2.summary() << endl;

        return intersecting;
    }

    void displaySchedule(){
        for(const auto& [month, events] : this->schedule){
            if (events.empty())
                continue;
            cout << "-----------------" << endl 
            << DateTime::calendarMonths[month].name << endl
            << "-----------------" << endl;
            for(Event event : events){
                cout << event.summary() << endl;
            }
            cout << endl;
        }
    }
};

