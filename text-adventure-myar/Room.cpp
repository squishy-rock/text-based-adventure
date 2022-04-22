#include "Room.h"
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
	_help = "";
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
	_help = line;
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

void Room::OutputHelp()
{
	cout << _help << "\n";

}

bool Room::ProcessCommand(string command) // implmentation of process command class
{
	vector<string> wordsInCommand = Room::SplitCommand(command);

	if (wordsInCommand[0] == "HELP")
	{
		OutputHelp();
		return true;
	}
	return false;
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