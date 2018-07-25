#include <iostream>
#include "exit.h"
#include "item.h"
#include "npc.h"
#include "room.h"

Room::Room(const char* name, const char* description) : Entity(name, description, NULL)
{
	entityType = ROOM;
}

Room::~Room()
{
}

void Room::Look() const
{
	bool exitExists = false;
	bool itemExists = false;
	bool npcExists = false;
	cout << name << description << endl;
	 
	//Exits availables
	for (list<Entity*>::const_iterator it = content.begin(); it != content.end(); ++it) {
		if ((*it)->entityType == EXIT) {
			
			if (!exitExists) {
				exitExists = true;
				cout << "Available Exits:" << endl;
			}
			Exit* ex = (Exit*)*it;
			ex->Look();
		} 
	}

	//Items availables
	for (list<Entity*>::const_iterator it = content.begin(); it != content.end(); ++it) {
		if ((*it)->entityType == ITEM) {
			if (!itemExists) {
				itemExists = true;
				cout << "Items:" << endl;
			}
			Item* ex = (Item*)*it;
			ex->Look();
		}
	}

	//Npc availables
	for (list<Entity*>::const_iterator it = content.begin(); it != content.end(); ++it) {
		if ((*it)->entityType == NPC) {
			if (!npcExists) {
				npcExists = true;
				cout << "NPC:" << endl;
			}
			Npc* ex = (Npc*)*it;
			ex->Look();
		}
	}
}

void Room::LookElement(vector<string> args) const
{
	bool elementExists = false;

	//Elements available in the room
	for (list<Entity*>::const_iterator it = content.begin(); it != content.end(); ++it) {
		if ((*it)->name.compare(args[1]) == 0) {
			elementExists = true;
			cout << (*it)->description << endl;
			break;
		}
	}

	if(!elementExists)
		cout << "There's no " << args[1] << " to look at" << endl;

}
