#pragma once
#include <string>

using namespace std;

class Room
{
public: //for all the subclasses to have access of variables and functions
	string _name;
	string _type;
	string _description;
	string _nextRoom;
	virtual void LoadRoom(string fileName); //virtual denotes that any subclass denotes this function -> needed for subclass fumctionality. subclasses can define dif behaviour for this function

};

