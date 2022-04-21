#pragma once

#include "Room.h"

class BranchRoom :
    public Room
{
private:


    vector<BranchChoice> _branches; // list of all choices the uesr can make
public:
    void LoadRoom(string fileName);
    void OutputRoomInfo();
    void ProcessCommand(string command);
};

