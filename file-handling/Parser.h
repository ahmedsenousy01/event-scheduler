#pragma once
#include <string>
#include <vector>
#include <sstream>
#include "../core/user/User.h"
#include "../core/event/Event.h"

using namespace std;

class Parser
{
public:
	static vector<string> split(string line)
	{
		// name&email&password

		// eventName&eventPlace&eventStartMonth&eventStartDay&eventStartHour&eventStartMinute&eventEndMonth&eventEndDay&eventEndHour&eventEndMinute&eventReminderTimeHour&evenReminderTimeMinute&eventDone&creatorId

		stringstream s(line);
		vector<string> info;
		string data;
		while (getline(s, data, '&'))
		{
			info.push_back(data);
		}
		return info;
	}

	static Event parseToEvent(string line)
	{
		vector<string> info = split(line);

		DateTime startDateTime(stoi(info[2]), stoi(info[3]), stoi(info[4]), stoi(info[5]));
		DateTime endDateTime(stoi(info[6]), stoi(info[7]), stoi(info[8]), stoi(info[9]));
		Time reminderTime(stoi(info[10]), stoi(info[11]));

		Event e(info[0], info[1], startDateTime, endDateTime, reminderTime, stoi(info[12]), stoi(info[13]));

		return e;
	}

	static User parseToUser(string line)
	{
		vector<string> info = split(line);
		User u(info[0], info[1], info[2]);
		
		return u;
	}
};
