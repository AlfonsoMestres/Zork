#include <iostream>
#include "player.h"
#include "exit.h"

Exit::Exit(const char* name, const char* description, Room* source, Room* destination, Item* itemToOpen, bool locked) : Entity(name, description, source), source(source), destination(destination), itemToOpen(itemToOpen), locked(locked)
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

string Exit::GetDestinationName() {
	return destination->name;
}