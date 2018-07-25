#include <iostream>
#include "exit.h"

Exit::Exit(const char* name, const char* description, Room* source, Room* destination, Item* itemToOpen, bool locked, bool itemCondition = false) 
	: Entity(name, description, source), source(source), destination(destination), itemToOpen(itemToOpen), locked(locked), itemCondition(itemCondition)
{
	entityType = EXIT;
}

Exit::~Exit()
{
}

void Exit::Look() const
{
	cout << "(" << name << ") " << " You can see a " << description << " leading to " << destination->name << endl;
}

string Exit::GetDestinationName() const 
{
	return destination->name;
}

///SwapSourceDestiantion - This is a patch handling the two way exits, needs to be removed 
void Exit::SwapSourceDestination() {
	Room* sourceHelper = source;
	source = destination;
	destination = sourceHelper;
}