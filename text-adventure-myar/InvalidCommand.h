#pragma once
#include <iostream>
#include <exception>
using namespace std;

struct InvalidCommand : public exception 
{
    InvalidCommand(string message);
    const char* what() const throw ();
    string _message;
    
};