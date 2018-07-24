#include <iostream>
#include <vector>
#include "exit.h"
#include "item.h"
#include "player.h"

Player::Player(const char* name, const char* description, Entity* parent) : Entity(name,description,parent)
{
	type = PLAYER;
}

Player::~Player()
{
}

void Player::Go(vector<string> args)
{

	Exit* exit = GetRoom()->FindExit(args);

	if (exit == NULL)
	{
		cout << "\nThere is no Exit to " << args[1] << ".\n";
	}
	else if (exit->locked) {
		cout << "The " << args[1] << "is locked" << endl;
	}
	else {
		cout << "You walked to " << exit->GetDestinationName() << endl;
		this->Adoption(exit->destination);
		parent->Look();
	}

}

void Player::LookAt(vector<string> args) {
	Item* item = GetRoom()->FindItem(args);

	if (item == NULL)
	{
		cout << "\nThere's no such item " << args[1] << ".\n";
	} else {
		item->Look();
	}
}

void Player::Pick(vector<string> args) 
{
	Item* item = GetRoom()->FindItem(args);

	if (item == NULL)
	{
		cout << "\nThere's no such item " << args[1] << ".\n";
	}
	else if (!item->canBePicked) {
		cout << "\nCan't be picked up" << ".\n";
	}
	else {
		cout << "You picked up a " << item->name << endl;
		item->GenerateItemIfNeeded();
		item->Adoption(this);
	}
}

void Player::Drop(vector<string> args)
{
	static bool itemExists;

	for (list<Entity*>::iterator it = content.begin(); it != content.end(); ++it) {
		if ((*it)->type == ITEM) {
			if ((*it)->name.compare(args[1]) == 0) {
				itemExists = true;
				cout << "You dropped the " << (*it)->name << endl;
				(*it)->Adoption(parent);
				break;
			}
		}
	}
	
	if (!itemExists)
		cout << "You don't have " << args[1] << " to drop." << endl;

}

void Player::Open(vector<string> args) {
	bool exitExists = false;

	for (list<Entity*>::iterator it = parent->content.begin(); it != parent->content.end(); ++it) {
		if ((*it)->type == EXIT) {
			if ((*it)->name.compare(args[1]) == 0) {
				exitExists = true;
				Exit* exit = (Exit*)*it; //This should be an entity, to be able to lock or unlock stuff like chests and lockers... etc
				if (!exit->locked) {
					cout << "Already open!" << endl;
					break;
				}
				exit->LockUnlock(this);
				break;
			}
		}
	}

	if (!exitExists)
		cout << "There's no such thing to open" << endl;

}

void Player::Close(vector<string> args) {
	bool exitExists = false;

	for (list<Entity*>::iterator it = parent->content.begin(); it != parent->content.end(); ++it) {
		if ((*it)->type == EXIT) {
			if ((*it)->name.compare(args[1]) == 0) {
				exitExists = true;
				Exit* exit = (Exit*)*it; //This should be an entity, to be able to lock or unlock stuff like chests and lockers... etc
				if (exit->locked) {
					cout << "Already closed!" << endl;
					break;
				}
				exit->LockUnlock(this);
				break;
			}
		}
	}

	if (!exitExists)
		cout << "There's no such thing to close" << endl;
}

void Player::Use(vector<string> args) {
	Item* itemInBag = NULL;
	Item* itemInRoom = NULL;

	//Recorre el inventario
	for (list<Entity*>::iterator it = content.begin(); it != content.end(); ++it) {
		if ((*it)->name.compare(args[1]) == 0) {
			itemInBag = ((Item*)*it);
			break;
		}
	}

	//recorre los elementos de la hab
	for (list<Entity*>::iterator it = parent->content.begin(); it != parent->content.end(); ++it) {
		if ((*it)->name.compare(args[2]) == 0) {
			itemInRoom = ((Item*)*it);
			break;
		}
	}

	if (itemInBag && itemInRoom)
		itemInBag->UseWith(itemInRoom);
	

	if (!itemInBag)
		cout << "You don't have " << args[1] << endl;

	if (!itemInRoom)
		cout << "There's no such " << args[2] << endl;

}


void Player::Inventory() {
	static bool emptyBag = true;

	for (list<Entity*>::iterator it = content.begin(); it != content.end(); ++it) {
		if ((*it)->type == ITEM) {
			if (emptyBag) {
				cout << "Your inventory contains: " << endl;
			}
			emptyBag = false;
			((Item*)*it)->Look();
		}
	}
	if (emptyBag) {
		cout << "Your inventory is empty" << endl;
	}
}

Room* Player::GetRoom() {
	return (Room*)parent;
}