#pragma once

#include "Room.h"

class GameState
{
private:
	Room* _currentRoom; 
public:
	void StartGame();
};

