#include <iostream>
#include "exit.h"

//we should analize if the direction could be treated like the name (before: const char* name -> Entity(name,...)
Exit::Exit(const char* name, const char* description, Room* source, Room* destination) : Entity(name, description, source), source(source), destination(destination)
{
	
}

Exit::~Exit()
{
}

string Exit::GetDestinationName() {
	return destination->name;
}