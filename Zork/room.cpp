#include <iostream>
#include "exit.h"
#include "item.h"
#include "room.h"

Room::Room(const char* name, const char* description) : Entity(name, description, NULL)
{
	type = ROOM;
}

Room::~Room()
{
}

void Room::Look()
{
	static bool exitExists;
	static bool itemExists;
	cout << name << description << endl;

	//Exits availables
	for (list<Entity*>::iterator it = content.begin(); it != content.end(); ++it) {
		if ((*it)->type == EXIT) {
			
			if (!exitExists) {
				exitExists = true;
				cout << "Available Exits:" << endl;
			}
			Exit* ex = (Exit*)*it;
			ex->Look();
		} 
	}

	//Items availables
	for (list<Entity*>::iterator it = content.begin(); it != content.end(); ++it) {
		if ((*it)->type == ITEM) {
			if (!itemExists) {
				itemExists = true;
				cout << "Items:" << endl;
			}
			Item* ex = (Item*)*it;
			ex->Look();
		}
	}


}

void Room::LookElement(vector<string> args)
{
	bool elementExists = false;

	//Elements available in the room
	for (list<Entity*>::iterator it = content.begin(); it != content.end(); ++it) {
		if ((*it)->name.compare(args[1]) == 0) {
			elementExists = true;
			cout << (*it)->description << endl;
			break;
		}
	}

	if(!elementExists)
		cout << "There's no " << args[1] << " to look at" << endl;

}

Exit* Room::FindExit(vector<string> args)
{
	for (list<Entity*>::iterator it = content.begin(); it != content.end(); ++it) {
		if ((*it)->type == EXIT) {
			if ((*it)->name.compare(args[1]) == 0) {
				return (Exit*)*it;
			};
		}
	}

	return NULL;
}

Item* Room::FindItem(vector<string> args)
{
	for (list<Entity*>::iterator it = content.begin(); it != content.end(); ++it) {
		if ((*it)->type == ITEM) {
			if ((*it)->name.compare(args[1]) == 0) {
				return (Item*)*it;
			}
		}
	}

	return NULL;
}