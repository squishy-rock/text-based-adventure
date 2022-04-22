#pragma once

#include "Room.h"

class IntroRoom :
    public Room
{
public:
    bool ProcessCommand(string command);
};

