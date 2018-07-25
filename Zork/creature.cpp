#include <iostream>
#include "item.h"
#include "exit.h"
#include "world.h"
#include "creature.h"

Creature::Creature(const char* name, const char* description, Entity* parent) : Entity(name, description, parent)
{
	entityType = CREATURE;
}

Creature::~Creature()
{
}

void Creature::Go(vector<string> args) {

	Exit* exit = (Exit*)GetRoom()->Find(args[1], EXIT);

	if (exit == NULL)
		return;
	
	if (exit->locked) {
		return;
	}
	
	if (PlayerNear()) {
		cout << name << " walked to " << exit->GetDestinationName() << endl;
		this->Adoption(exit->destination);
	}

}

void Creature::Go(Exit* toExit) {

	Exit* exit = (Exit*)GetRoom()->Find(toExit,EXIT);

	if (exit == NULL)
		return;

	if (exit->locked) {
		return;
	}

	if (PlayerNear()) {
		cout << name << " walked to " << exit->GetDestinationName() << endl;
		this->Adoption(exit->destination);
	}

}

void Creature::Unlock(vector<string> args) {

	Exit* exit = (Exit*)GetRoom()->Find(args[1], EXIT);

	if (exit != NULL) {
		if (exit->locked) {
			Entity* keyToOpen = Find(exit->itemToOpen, ITEM);
			if (keyToOpen != NULL) {
				exit->locked = false;
				if(PlayerNear())
					cout << name << " unlocked " << exit->description << endl;
			}
		}
	}
}

void Creature::Lock(vector<string> args) {

	Exit* exit = (Exit*)GetRoom()->Find(args[1], EXIT);

	if (exit != NULL) {
		if (exit->locked == false) { 
			Entity* keyToOpen = Find(exit->itemToOpen, ITEM);
			if (keyToOpen != NULL) {
				exit->locked = false;
				if (PlayerNear())
					cout << name << " locked the " << exit->description << endl; 
			}
		}
	}
}

Room* Creature::GetRoom() const 
{
	return (Room*)parent;
}

bool Creature::PlayerNear() const 
{
	return parent->Find(PLAYER) != NULL;
}
