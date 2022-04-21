#pragma once

#include "Room.h"

class BranchRoom :
    public Room
{
private:
    struct BranchChoice //need to create list, this struct is a small collection of data to help deal with the branching
    {
        string _description;
        string _room;
        string _roomType;
        // represents a choice and all the data required to make that choice
    };

    vector<BranchChoice> _branches; // list of all choices the uesr can make
public:
    void LoadRoom(string fileName);
    void OutputRoomInfo();
    void ProcessCommand(string command);
};

