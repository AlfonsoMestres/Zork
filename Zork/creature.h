#pragma once

#include "entity.h"

class Room;

class Creature : public Entity
{
public:
	Creature(const char* name, const char* description, Entity* parent);
	virtual ~Creature();

	void Go(vector<string> args);
	//void Pick(vector<string> args);
	//void Drop(vector<string> args);
	void Unlock(vector<string> args);
	void Lock(vector<string> args);

	Room* GetRoom();
};

