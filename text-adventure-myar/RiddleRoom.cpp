#include "RiddleRoom.h"
#include <fstream>
#include <iostream>

RiddleRoom::RiddleRoom()
{
	_question = "";
	_answer1 = "";
	_answer2 = "";
	_answer3 = "";
	_answer4 = "";
	_correctAnswer = "";
	_incorrectMessage = "";
	_correctMessage = "";
	_answeredCorrectly = false;
}

void RiddleRoom::LoadRoom(string fileName)
{
	string line;
	ifstream roomData(fileName);

	// Read first four lines as empty, base class saves that data
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
	getline(roomData, line);
	_question = line;
	getline(roomData, line);
	_answer1 = line;
	getline(roomData, line);
	_answer2 = line;
	getline(roomData, line);
	_answer3 = line;
	getline(roomData, line);
	_answer4 = line;
	getline(roomData, line);
	_correctAnswer = line;
	getline(roomData, line);
	_incorrectMessage = line;
	getline(roomData, line);
	_correctMessage = line;

	roomData.close();
}

void RiddleRoom::OutputRoomInfo()
{
	Room::OutputRoomInfo();

	cout << _question << "\n";
	cout << _answer1 << "\n";
	cout << _answer2 << "\n";
	cout << _answer3 << "\n";
	cout << _answer4 << "\n";
}

bool RiddleRoom::ProcessCommand(string command)
{
	bool processedCommand = Room::ProcessCommand(command);
	if (!processedCommand)
	{
		vector<string> wordsInCommand = Room::SplitCommand(command);
		if (wordsInCommand.size() > 2)
		{
			// throw exception here
			// throw InvalidCommand("Your command has too many words");
			throw InvalidCommand("COMMAND HAS TOO MANY WORDS.");
		}
		else if (wordsInCommand[0] == "ANSWER")
		{
			if (wordsInCommand[1] == _correctAnswer)
			{
				cout << _correctMessage << "\n";
				_answeredCorrectly = true;

			}
			else
			{
				cout << _incorrectMessage << "\n";
			}
			return true;
		}
		else if (_answeredCorrectly && command == "NEXT ROOM")
		{
			_proceedToNextRoom = true;
			return true;
		}
		else
		{
			// throw exception here
			throw InvalidCommand("INVALID COMMAND PLEASE TYPE 'NEXT ROOM'.");
		}
	}
}