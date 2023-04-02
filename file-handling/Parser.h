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

		// eventName & eventPlace & eventStartMonth & eventStartDay & eventStartHour & eventEndMonth & eventEndDay & eventEndHour & eventReminderTimeHour & eventDone & creatorId

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

		DateTime startDateTime(stoi(info[2]), stoi(info[3]), stoi(info[4]));
		DateTime endDateTime(stoi(info[5]), stoi(info[6]), stoi(info[7]));
		Time reminderTime(stoi(info[8]));

		Event e(info[0], info[1], startDateTime, endDateTime, reminderTime, stoi(info[9]), stoi(info[10]));

		return e;
	}

	static User parseToUser(string line)
	{
		vector<string> info = split(line);
		User u(info[0], info[1], info[2]);

		return u;
	}
};
