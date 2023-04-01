#include <iostream>
#include "file-handling/FileHelper.h"
#include "core/event/Event.h"
using namespace std;

int main()
{
    Event event("name", "place", {{2, 15}, {5, 30}}, {{2, 17}, {5, 30}}, {4, 30}, false, 2001);
    event.displayDetails();
    FileHelper::saveEvent(event);

    return 0;
}