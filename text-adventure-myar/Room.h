#pragma once

#include <string>
#include <vector>

using namespace std;

class Room
{
protected:
	vector<string> SplitCommand(string command);
public: //for all the subclasses to have access of variables and functions
	string _name;
	string _description;
	string _nextRoom;
	string _nextRoomType;
	bool _proceedToNextRoom;

	Room();

	virtual void LoadRoom(string fileName); //virtual denotes that any subclass denotes this function -> needed for subclass fumctionality. subclasses can define dif behaviour for this function
	virtual void OutputRoomInfo();
	virtual void ProcessCommand(string command);
};

