//Includes
#include <cstdlib>
#include <time.h>
#include <iostream>
#include <fstream>
#include <istream>
#include <string>
#include <vector>
#include <cmath>
#include "GameState.h"


using namespace std;

int main()
{

	//GameState comtrols the game making main nice and clean, this is what initializes it
	GameState* game = new GameState();

	game->StartGame();


}