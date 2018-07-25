#include <iostream>
#include <vector>
#include "exit.h"
#include "item.h"
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
	{
		cout << name << " has no Exit to " << args[1] << ".\n"; //This will be erased, just for debugging NPCs
	}
	else if (exit->locked) {
		cout << name << " has the exit " << args[1] << " locked" << endl;  //This will be erased, just for debugging NPCs
	}
	else {
		cout << name << " walked to " << exit->GetDestinationName() << endl;  //This would be just if hero is in the same room (otherwise its cheating)
		this->Adoption(exit->destination);
	}

}

void Creature::Unlock(vector<string> args) {

	Exit* exit = (Exit*)GetRoom()->Find(args[1], EXIT);

	if (exit != NULL) {
		if (exit->locked) {
			Entity* keyToOpen = Find(exit->itemToOpen, ITEM);
			if (keyToOpen == NULL)
				cout << name << " needs something to unlock " << exit->description << endl;
			else {
				exit->locked = false;
				cout << name << " unlocked " << exit->description << endl; //Cheating!
			}
			exit->locked = true;
		}
		else {
			cout << "Creature, its already unlocked!" << endl;//Cheating!
		}
	}
	else {
		cout << "There's no such thing to unlock" << endl; //Cheating!
	}

}

void Creature::Lock(vector<string> args) {

	Exit* exit = (Exit*)GetRoom()->Find(args[1], EXIT);

	if (exit != NULL) {
		if (exit->locked == false) { 
			Entity* keyToOpen = Find(exit->itemToOpen, ITEM);
			if (keyToOpen == NULL)
				cout << name << " needs something to lock the " << exit->description << endl;
			else {
				exit->locked = false;
				cout << name << " locked the " << exit->description << endl; //Cheating!
			}
			exit->locked = true;
		}
		else {
			cout << "Creature, its already locked!" << endl;//Cheating!
		}
	}
	else {
		cout << "There's no such thing to lock" << endl; //Cheating!
	}

}

Room* Creature::GetRoom() {
	return (Room*)parent;
}