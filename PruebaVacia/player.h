#pragma once

#include "entity.h"

class Room;

class Player : public Entity
{
public:
	Player(const char* name, const char* description, Entity* parent);
	virtual ~Player();

	void Go(vector<string> args);
	Room* GetRoom();

};

