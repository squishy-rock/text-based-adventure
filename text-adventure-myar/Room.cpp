#include "Room.h"
#include <string>
#include <fstream> //open files and reads it

#include <iostream>

using namespace std;

void Room::LoadRoom(string fileName) //reads the text files and loads in the variables
{
	string line;
	ifstream myfile(fileName);

	getline(myfile, line);
	_name = line;
	getline(myfile, line);
	_type = line;
	getline(myfile, line);
	_description = line;
	getline(myfile, line);
	_nextRoom = line;
	//reading each line and setting the variables

	myfile.close();
}