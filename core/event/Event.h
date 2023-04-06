#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>
#include "../../utils/date-time/DateTime.h"
#include "../../utils/date-time/Date.h"
#include "../../utils/date-time/Time.h"
using namespace std;

class Event
{
protected:
    static inline int idCounter = 10000;
    int id, creatorId;
    string name, place;
    DateTime startDateTime, endDateTime;
    Time reminderTime;
    bool done;

public:
    Event() {}
    Event(string name, string place, DateTime startDateTime, DateTime endDateTime, Time reminderTime, bool done = false, int creatorId = 0)
    {
        idCounter++;
        this->id = idCounter;
        setName(name);
        setPlace(place);
        setStartDateTime(startDateTime);
        setEndDateTime(endDateTime);
        setReminderTime(reminderTime);
        setDone(done);
        setCreatorId(creatorId);
    }

    // getters
    int getId() { return this->id; }
    string getName() { return this->name; }
    string getPlace() { return this->place; }
    DateTime getStartDateTime() { return this->startDateTime; }
    DateTime getEndDateTime() { return this->endDateTime; }
    Time getReminderTime() { return this->reminderTime; }
    bool getDone() { return this->done; }
    int getCreatorId() { return this->creatorId; }
    // int getEventLength() { }

    // setters
    void setName(string name)
    {
        this->name = name;
    }
    void setPlace(string place)
    {
        this->place = place;
    }
    void setStartDateTime(DateTime startDateTime)
    {
        this->startDateTime = startDateTime;
    }
    void setEndDateTime(DateTime endDateTime)
    {
        this->endDateTime = endDateTime;
    }
    void setReminderTime(Time reminderTime)
    {
        this->reminderTime = reminderTime;
    }
    void setDone(bool done)
    {
        this->done = done;
    }
    void setCreatorId(int creatorId)
    {
        this->creatorId = creatorId;
    }

    // extra
    void displayDetails()
    {
        cout << "ID: " << this->getId() << endl;
        cout << "Name: " << this->getName() << endl;
        cout << "Place: " << this->getPlace() << endl;
        cout << "Start Date: " << this->getStartDateTime().getDate().getMonth() << "/" << this->getStartDateTime().getDate().getDay() << endl;
        cout << "Start Time: " << this->getStartDateTime().getTime().getHour() << endl;
        cout << "End Date: " << this->getEndDateTime().getDate().getMonth() << "/" << this->getEndDateTime().getDate().getDay() << endl;
        cout << "End Time: " << this->getEndDateTime().getTime().getHour() << endl;
        cout << "Reminder Time: " << this->getReminderTime().getHour() << endl;
        cout << "Done: " << this->getDone() << endl;
        cout << "Creator ID: " << this->getCreatorId() << endl;
    }

    string summary() {
        stringstream ss;
        ss << name << ": "
          << getStartDateTime().to_ddmmyyyy_hhmm() << " -> "
          << getEndDateTime().to_ddmmyyyy_hhmm();
        string res;
        getline(ss, res);
        return res;
    }

    static unordered_map<string, Event> events;
    static unordered_map<string, Event> finishedEvents;
};

