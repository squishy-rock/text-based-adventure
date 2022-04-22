#include "IntroRoom.h"
#include <iostream>

using namespace std;

bool IntroRoom::ProcessCommand(string command)
{
	bool processedCommand = Room::ProcessCommand(command);
	if (!processedCommand)
	{
		vector<string> wordsInCommand = Room::SplitCommand(command);
		if (wordsInCommand.size() > 2) // to check for the specific case of using more than 2 words so we know its incorrect
		{
			// throw exception here
			throw InvalidCommand("COMMAND IS TOO LARGE, TYPE 'NEXT ROOM'");
		}
		else if (wordsInCommand[0] != "NEXT")
		{
			// throw exception "Only next command accepted" (if the first word isnt next we know its wrong) 
			throw InvalidCommand("INVALID COMMAND: " + wordsInCommand[0] + ", THIS ROOM ONLY ACCEPTS 'NEXT ROOM'"); //combine strings, now our system takes whatever command they typed in to tell the user what they did wrong
		}
		else if (command == "NEXT ROOM")
		{
			_proceedToNextRoom = true;
			return true;
		}
		else
		{
			// throw exception here
			throw InvalidCommand("ERROR PROCESSING COMMAND.");
		}
	}
}
