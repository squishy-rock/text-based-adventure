#include "Room.h"
#include <string>
#include <fstream> //open files and reads it
#include <sstream>
#include <iostream>

using namespace std;

Room::Room()
{
	_name = "";
	_description = "";
	_nextRoom = "";
	_nextRoomType = "";
	_proceedToNextRoom = false; //This always should be false so we dont automatically proceed through the game 
}

void Room::LoadRoom(string fileName) //reads the text files and loads in the variables
{
	string line;
	ifstream roomData(fileName);

	getline(roomData, line);
	_name = line;
	getline(roomData, line);
	_description = line;
	getline(roomData, line);
	_nextRoom = line;
	getline(roomData, line);
	_nextRoomType = line;
	//reading each line and setting the variables

	roomData.close();
}

void Room::OutputRoomInfo()
{
	cout << _name << "\n";
	cout << _description << "\n";
}

void Room::ProcessCommand(string command) // implmentation of process command class
{
	// Does nothing, implement in subclasses
}

vector<string> Room::SplitCommand(string command)
{
	vector<string> wordsInCommand;

	string wordInCommand;
	stringstream stream(command);
	while (stream >> wordInCommand)
	{
		wordsInCommand.push_back(wordInCommand);
	}

	return wordsInCommand;
}