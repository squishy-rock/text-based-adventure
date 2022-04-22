#pragma once
#include "Room.h"
class RiddleRoom :
    public Room
{
private:
    string _question;
    string _answer1;
    string _answer2;
    string _answer3;
    string _answer4;
    string _correctAnswer;
    string _incorrectMessage;
    string _correctMessage;
    bool _answeredCorrectly;
public:
    RiddleRoom();
    void LoadRoom(string fileName);
    void OutputRoomInfo();
    bool ProcessCommand(string command);
};

