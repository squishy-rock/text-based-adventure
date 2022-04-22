#pragma once
#include "BranchChoice.h"
#include "Room.h"
#include "DynamicLinkedList.h"

class BranchRoom :
    public Room
{
private:


   DynamicLinkedList<BranchChoice> _branches; // list of all choices the uesr can make
public:
    void LoadRoom(string fileName);
    void OutputRoomInfo();
    void ProcessCommand(string command);
};

