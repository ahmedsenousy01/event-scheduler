#include <iostream>
#include "core/calendar/Calendar.h"
#include "core/event/Event.h"
using namespace std;

int main()
{
    unordered_map<int, unordered_map<int, unordered_map<int, bool>>> schedule;
    Calendar::initSchedule(schedule);

    Event e("name", "place", {{12, 30}, {20}}, {{12, 30}, {23}}, 19, 0, 20001);
    Calendar::reserveEvent(e, schedule);

    Calendar::displaySchedule(schedule);

    return 0;
}