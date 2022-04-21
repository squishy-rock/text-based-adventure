#include "GameState.h"
#include "IntroRoom.h"
#include "RiddleRoom.h"
#include "EnemyRoom.h"
#include "BranchRoom.h"
#include "EndRoom.h"
#include <iostream>

using namespace std;

void GameState::StartGame()
{
	// Game state variables
	bool gameRunning = true;
	string command;
	_currentRoom = new IntroRoom();
	_currentRoom->LoadRoom("Rooms/Intro.txt");

	while (true) // as long as its true it will run 
	{
		_currentRoom->OutputRoomInfo();

		if (!gameRunning)
		{
			break; // end the loop to end the game
		}

		while (!_currentRoom->_proceedToNextRoom) // while we are not ready to go to the next room we are simply processing commands
		{
			try
			{
				getline(cin, command);
				_currentRoom->ProcessCommand(command); //getting command from user, during this process if u get an invalid command it gives an exception and then repeats
			}
			catch (exception& e)
			{
				cout << "Exception happened\n";
			}
		}

		string nextRoom = _currentRoom->_nextRoom;
		string nextRoomType = _currentRoom->_nextRoomType;

		// Possible rooms are "Riddle", "Enemy", "Branch", "Ending"
		if (nextRoomType == "Riddle")
		{
			_currentRoom = new RiddleRoom();
		}
		else if (nextRoomType == "Enemy")
		{
			_currentRoom = new EnemyRoom();
		}
		else if (nextRoomType == "Branch")
		{
			_currentRoom = new BranchRoom();
		}
		else if (nextRoomType == "Ending")
		{
			_currentRoom = new EndRoom();
			gameRunning = false;
		}
		_currentRoom->LoadRoom(nextRoom);

		system("cls");
	}
}