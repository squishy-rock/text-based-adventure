#include "GameState.h"
#include <iostream>

using namespace std;

void GameState::StartGame()
{
	_currentRoom = new Room();
	_currentRoom->LoadRoom("Intro.txt");

	cout << _currentRoom->_name << "\n";
	cout << _currentRoom->_type << "\n";
	cout << _currentRoom->_description << "\n";
	cout << _currentRoom->_nextRoom << "\n";


}