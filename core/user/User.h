#pragma once
#include <string>
#include <vector>
#include <unordered_map>
#include "../event/Event.h"
using namespace std;

class User
{
protected:
    static inline int idCounter = 20000;
    int id;
    string name, email, password;
    vector<Event> events;

public:
    User() {}
    User(string name, string email, string password, vector<Event> events = {}) {
        idCounter++;
        this->id = idCounter;
        setName(name);
        setEmail(email);
        setPassword(password);
        setEvents(events);
    }

    // getters
    int getId() { return this->id; }
    string getName() { return this->name; }
    string getEmail() { return this->email; }
    string getPassword() { return this->password; }
    vector<Event> getEvents() { return this->events; }

    // setters
    void setName(string name) { this->name = name; }
    void setEmail(string email) { this->email = email; }
    void setPassword(string password) { this->password = password; }
    void setEvents(vector<Event> events) { this->events = events; }

    // extra
    void getUserEvents() {
        for(auto event : events) {
            if(this->getId() == event.getCreatorId()) {
                this->events.push_back(event);
            }
        }
    }
    void displayDetails() {
        cout << "ID: " << this->getId() << endl;
        cout << "Name: " << this->getName() << endl;
        cout << "Email: " << this->getEmail() << endl;
    }
    void createEvent() {

    }
    void listUserEvents() {

    }
    Event* searchForEventById() {

    }
    Event* searchForEventByName() {

    }
    void updateEvent() {

    }
    void deleteEvent() {

    }
};

static unordered_map<string, User> users;