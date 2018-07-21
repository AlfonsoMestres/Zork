#include <iostream>
#include "player.h"
#include "exit.h"

Exit::Exit(const char* name, const char* description, Room* source, Room* destination, Item* itemToOpen, bool locked) : Entity(name, description, source), source(source), destination(destination), itemToOpen(itemToOpen), locked(locked)
{
	type = EXIT;
}

Exit::~Exit()
{
}

void Exit::Look() const
{
	cout << "(" << name << ") " << "You can see a " << description << " leading to " << destination->name << endl;
}

void Exit::LockUnlock(Player* player) 
{
	bool haveKey = false;
	string doorStatus = "open";

	if (player->content.size() != 0) {
		for (list<Entity*>::iterator it = player->content.begin(); it != player->content.end(); ++it) {
			if ((*it)->type == ITEM) {
				if ((Item*)*it == itemToOpen) {
					haveKey = true;
					locked = !locked;

					if (locked)
						doorStatus = "closed";

					cout << "You " << doorStatus << " the " << (*it)->name << " in the " << name << endl;
					break;
				}
			}
		}
	}

	if (!haveKey)
		cout << "You need something to lock/unlock the " << description << endl;
}

string Exit::GetDestinationName() {
	return destination->name;
}