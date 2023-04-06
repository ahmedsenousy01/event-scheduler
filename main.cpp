#include <iostream>
#include "core/calendar/Calendar.h"
#include "core/event/Event.h"
#include <list>
using namespace std;

int main()
{
    Calendar c;

    Event e2("e2", "place", {{3, 31}, {0}}, {{12, 31}, {23}}, 19, 0, 20001);
    Event e1("e1", "place", DateTime(2, 28, 20), DateTime(7, 5, 23), 19, 0, 20001);
    Event e3("e3", "place", DateTime(7, 5, 23), DateTime(7, 10, 0), 19, 0, 20001);
    Event e31("e3.1", "place", DateTime(2, 1, 0), DateTime(2, 1, 2), 12);
    Event e4("e4", "place", DateTime(2, 1, 0), DateTime(2, 1, 2), 12);
    Event e5("e5", "place", DateTime(2, 1, 4), DateTime(2, 1, 6), 12);
    Event e6("e6", "place", DateTime(2, 1, 2), DateTime(2, 1, 4), 12);

    c.reserveEvent(e1);
    c.reserveEvent(e2);
    c.reserveEvent(e3);
    c.reserveEvent(e4);
    c.reserveEvent(e5);
    c.reserveEvent(e6);

    c.displaySchedule();
    system("pause");
}