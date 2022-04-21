#pragma once

#include "Room.h"

class IntroRoom :
    public Room
{
public:
    void ProcessCommand(string command);
};

