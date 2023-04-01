#pragma once
#include <fstream>
#include "Parser.h"

using namespace std;

class FileHelper
{

public:
  static void saveUser(User &u)
  {
    fstream file("data/users.txt", ios::app);
    file << u.getName() << '&' << u.getEmail() << '&' << u.getPassword() << endl;
    file.close();
  }

  static void saveEvent(Event &e)
  {
    fstream file("data/events.txt", ios::app);
    file << e.getName() << '&' << e.getPlace() << '&' << e.getStartDateTime().getDate().getMonth() << '&' << e.getStartDateTime().getDate().getDay() << '&' << e.getStartDateTime().getTime().getHour() << '&' << e.getStartDateTime().getTime().getMinute() << '&' << e.getEndDateTime().getDate().getMonth() << '&' << e.getEndDateTime().getDate().getDay() << '&' << e.getEndDateTime().getTime().getHour() << '&' << e.getEndDateTime().getTime().getMinute() << '&' << e.getReminderTime().getHour() << '&' << e.getReminderTime().getMinute() << '&' << (int)e.getDone() << '&' << e.getCreatorId() << endl;
    file.close();
  }

  static void getUsers()
  {
    fstream file("data/users.txt", ios::in);
    string line;
    while (getline(file, line))
    {
      User u = Parser::parseToUser(line);
      users[u.getName()] = u;
    }
    file.close();
  }

  static void getEvents()
  {
    fstream file("data/events.txt", ios::in);
    string line;
    while (getline(file, line))
    {
      Event e = Parser::parseToEvent(line);
      events[e.getName()] = e;
    }
    file.close();
  }

  static void saveAllUsers() {
    for( auto user : users ) {
      saveUser(user.second);
    }
  }

  static void saveAllEvents() {
    for( auto event : events ) {
      saveEvent(event.second);
    }
  }
};