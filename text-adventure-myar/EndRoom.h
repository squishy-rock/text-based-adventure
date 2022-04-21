#pragma once
#include "Room.h"
class EndRoom :
    public Room
{
public:
    void LoadRoom(string fileName);
    void OutputRoomInfo();
};

