#include "BranchRoom.h"
#include "DynamicLinkedList.h"
#include <fstream> //open files and reads it
#include <sstream>
#include <iostream>

void BranchRoom::LoadRoom(string fileName)
{
	_branches = DynamicLinkedList <BranchChoice>();
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

		_branches.add(choice);
	}

	roomData.close();
}

void BranchRoom::OutputRoomInfo()
{
	Room::OutputRoomInfo();

	for (int i = 0; i < _branches.size(); i++)
	{
		cout << _branches.get(i)._description << "\n"; // we only output the description cuz the others are hidden knowledge 
	}
}

void BranchRoom::ProcessCommand(string command)
{
	vector<string> wordsInCommand = Room::SplitCommand(command);
	if (wordsInCommand.size() > 2)
	{
		// throw exception here
		// throw InvalidCommand("Your command has too many words");
		throw InvalidCommand("ERROR YOUR COMMAND HAS TOO MANY WORDS.");
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
			if (choiceIndex >= _branches.size() || choiceIndex < 0)
			{
				// throw not valid choice error
				throw InvalidCommand("INVALID COMMAND PLEASE TYPE ANSWER THEN YOUR CHOICE.");
			}
		else
			{
				_nextRoom = _branches.get(choiceIndex)._room;
				_nextRoomType = _branches.get(choiceIndex)._roomType;
				_proceedToNextRoom = true;
			}
		}
	}
	else
	{
		// throw exception here
		throw InvalidCommand("ERROR PROCESSING COMMAND.");
	}
}