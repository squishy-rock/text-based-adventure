#include "EndRoom.h"
#include <fstream>
#include <iostream>

void EndRoom::LoadRoom(string fileName)
{
	string line;
	ifstream roomData(fileName);

	// Read first four lines as empty, base class saves that data
	getline(roomData, line);
	_name = line;
	getline(roomData, line);
	_description = line;

	roomData.close();
}

void EndRoom::OutputRoomInfo()
{
	cout << _name << "\n";
	cout << _description << "\n";
}