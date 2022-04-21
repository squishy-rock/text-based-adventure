#include "BranchRoom.h"
#include <fstream> //open files and reads it
#include <sstream>
#include <iostream>

void BranchRoom::LoadRoom(string fileName)
{
	string line;
	ifstream roomData(fileName);

	getline(roomData, line);
	_name = line;
	getline(roomData, line);
	_description = line;
	//reading each line and setting the variables

	getline(roomData, line);
	int numberOfChoices = stoi(line);

	for (int i = 0; i < numberOfChoices; i++) // we need a for loop cuz we know how many times we want it to run (i.e. 2 choices)
	{
		//each answer has 3 components -> descript, room, and type
		string description;
		getline(roomData, description);
		string room;
		getline(roomData, room);
		string roomType;
		getline(roomData, roomType);
		
		BranchChoice choice;
		choice._description = description;
		choice._room = room;
		choice._roomType = roomType;

		_branches.push_back(choice);
	}

	roomData.close();
}

void BranchRoom::OutputRoomInfo()
{
	Room::OutputRoomInfo();

	for (int i = 0; i < _branches.size(); i++)
	{
		cout << _branches[i]._description << "\n"; // we only output the description cuz the others are hidden knowledge 
	}
}

void BranchRoom::ProcessCommand(string command)
{
	vector<string> wordsInCommand = Room::SplitCommand(command);
	if (wordsInCommand.size() > 2)
	{
		// throw exception here
		// throw InvalidCommand("Your command has two many words");
		cout << "COMMAND TOO BIG" << "\n";
	}
	else if (wordsInCommand[0] == "ANSWER")
	{
		if (wordsInCommand[1].size() > 1)
		{
			// throw choice too big error
		}
		else
		{
			char choice = wordsInCommand[1][0];
			int choiceIndex = choice - 'A';
			cout << "CHOICE MADE: " << choiceIndex << "\n";
			if (choiceIndex >= _branches.size())
			{
				// throw not valid choice error
			}
			else
			{
				_nextRoom = _branches[choiceIndex]._room;
				_nextRoomType = _branches[choiceIndex]._roomType;
				_proceedToNextRoom = true;
			}
		}
	}
	else
	{
		// throw exception here
		cout << "ERROR PROCESSING COMMAND" << "\n";
	}
}