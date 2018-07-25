#include <iostream>
#include <vector>
#include "exit.h"
#include "item.h"
#include "player.h"

Player::Player(const char* name, const char* description, Entity* parent) : Creature(name,description,parent)
{
	entityType = PLAYER;
}

Player::~Player()
{
}

void Player::LookAt(vector<string> args) const
{

	if (args[1].compare("me") == 0) {
		Look();
		return;
	}

	Item* item = (Item*)FindInventoryAndRoom(args[1], ITEM);

	if (item == NULL) {
		cout << "There's no such item " << args[1] << ".\n";
	} else {
		item->Look();
	}
}

void Player::LookRoom() const 
{
	cout << "You are in ";
	Room* room = (Room*)parent;
	room->Look();
}

void Player::Go(vector<string> args) {

	Exit* exit = (Exit*)GetRoom()->Find(args[1], EXIT);

	if (exit == NULL)
	{
		cout << "There is no Exit to " << args[1] << ".\n";
	} else if (exit->locked) {
		cout << "The " << args[1] << " is locked" << endl;
	} else {
		cout << "You walked to " << exit->GetDestinationName() << endl;
		this->Adoption(exit->destination);
		parent->Look();
	}

}

void Player::Pick(vector<string> args) 
{
	Item* item = (Item*)GetRoom()->Find(args[1], ITEM);

	if (item == NULL) {
		cout << "\nThere's no such item " << args[1] << ".\n";
	} else if (!item->canBePicked) {
		cout << "\nCan't be picked up" << ".\n";
	} else {
		cout << "You picked up a " << item->name << endl;
		item->GenerateItemIfNeeded();
		item->Adoption(this);
	}
}

void Player::Drop(vector<string> args)
{
	Item* item = (Item*)Find(args[1], ITEM);

	if (item == NULL) {
		cout << "You don't have " << args[1] << " to drop." << endl;
	}
	else {
		cout << "You dropped the " << item->name << endl;
		item->Adoption(parent);
	}

}

void Player::Unlock(vector<string> args) {

	Exit* exit = (Exit*)GetRoom()->Find(args[1], EXIT);

	if (exit != NULL) {
		if (exit->locked == false)
			cout << "It's already open" << endl;
		else {
			Entity* keyToOpen = Find(exit->itemToOpen, ITEM); //If we need something like an Eye-scanner, we need this to be an Entity not an item
			if (keyToOpen == NULL)
				cout << "You need something to unlock the " << exit->description << endl;
			else {
				exit->locked = false;
				cout << "You unlocked the " << exit->description << endl;
			}
		}
			
	}
	else {
		cout << "There's no such thing to open" << endl;
	}

}

void Player::Lock(vector<string> args)
{
	Exit* exit = (Exit*)GetRoom()->Find(args[1], EXIT);

	if (exit != NULL) {
		if (exit->locked)
			cout << "It's already closed" << endl;
		else {
			Entity* keyToOpen = Find(exit->itemToOpen, ITEM); //If we need something like an Eye-scanner, we need this to be an Entity not an item
			if (keyToOpen == NULL)
				cout << "You need something to lock the " << exit->description << endl;
			else {
				exit->locked = true;
				cout << "You locked the " << exit->description << endl;
			}
		}

	}
	else {
		cout << "There's no such thing to close" << endl;
	}
}

void Player::Use(vector<string> args) {

	Item* item1 = (Item*)FindInventoryAndRoom(args[1], ITEM); //You can use your environment with the environment (items not pickeables)
	if (item1 == NULL) {
		cout << "There's no " << args[1] << endl;
		return;
	}

	Item* item2 = (Item*)FindInventoryAndRoom(args[2], ITEM);
	if (item2 == NULL) {
		cout << "There's no " << args[2] << endl;
		return;
	}

	item1->UseWith(item2);
	
}

void Player::PickFrom(vector<string> args)
{
	Item* item1 = (Item*)FindInventoryAndRoom(args[1], ITEM);
	if (item1 == NULL){
		cout << "There's no " << args[1] << endl;
		return;
	}
	
	Item* item2 = (Item*)item1->Find(args[2], ITEM);
	if (item2 == NULL) {
		cout << "There's no " << args[2] << " inside " << item1->name << endl;
		return;
	}

	if (item2->canBePicked) {
		cout << "You picked up " << item2->name << " from inside of " << item1->name << endl;
		item2->GenerateItemIfNeeded();
		item2->Adoption(this);
	}
	else
		cout << "Can't be picked up" << endl;

}

void Player::Put(vector<string> args) {
	Item* item1 = (Item*)FindInventoryAndRoom(args[1], ITEM);
	if (item1 == NULL) {
		cout << "There's no " << args[1] << ".\n";
		return;
	}

	Item* item2 = (Item*)FindInventoryAndRoom(args[2], ITEM);
	if (item2 == NULL) {
		cout << "There's no " << args[2] << ".\n";
		return;
	}

	if (item1->canContain){
		item2->Adoption(item1);
		cout << "You put " << item2->name << " inside of " << item1->name << endl;
	} else 
		cout << "You cant put " << item2->name << " inside of " << item1->name << endl;

}

void Player::Inventory() const {
	if (content.size() > 0) {
		cout << "Your inventory contains: " << endl;
		for (list<Entity*>::const_iterator it = content.begin(); it != content.end(); ++it) {
			if ((*it)->entityType == ITEM) {
				((Item*)*it)->Look();
			}
		}
	} else {
		cout << "Your inventory is empty" << endl;
	}
}

