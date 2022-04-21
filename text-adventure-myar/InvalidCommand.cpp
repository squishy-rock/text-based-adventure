#include "InvalidCommand.h"

InvalidCommand::InvalidCommand(string message) 
{
	_message = message;
}
const char* InvalidCommand::what() const throw () 
{

	return _message.c_str();
}
