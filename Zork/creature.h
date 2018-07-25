#pragma once

#include "exit.h"
#include "entity.h"

class Room;

class Creature : public Entity
{
public:
	Creature(const char* name, const char* description, Entity* parent);
	virtual ~Creature();

	void Go(Exit* toExit);
	void Go(vector<string> args);
	void Unlock(vector<string> args);
	void Lock(vector<string> args);

	Room* GetRoom() const;
	bool PlayerNear() const;
};

