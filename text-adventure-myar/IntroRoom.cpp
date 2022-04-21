#include "IntroRoom.h"
#include <iostream>

using namespace std;

void IntroRoom::ProcessCommand(string command)
{
	vector<string> wordsInCommand = Room::SplitCommand(command);
	if (wordsInCommand.size() > 2) // to check for the specific case of using more than 2 words so we know its incorrect
	{
		// throw exception here
		cout << "COMMAND TOO BIG" << "\n";
	}
	else if (wordsInCommand[0] != "NEXT")
	{
		// throw exception "Only next command accepted" (if the first word isnt next we know its wrong) 
	}
	else if (command == "NEXT ROOM")
	{
		_proceedToNextRoom = true;
	}
	else
	{
		// throw exception here
		cout << "ERROR PROCESSING COMMAND" << "\n";
	}
}