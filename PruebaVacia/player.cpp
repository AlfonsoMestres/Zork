#include <iostream>
#include <vector>
#include "room.h"
#include "exit.h"
#include "player.h"

Player::Player(const char* name, const char* description, Entity* parent) : Entity(name,description,parent)
{
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
	else {
		cout << "You walked to " << exit->GetDestinationName() << endl;
		this->Adoption(exit->destination);
		parent->Look();
	}

}

Room* Player::GetRoom() {
	return (Room*)parent;
}