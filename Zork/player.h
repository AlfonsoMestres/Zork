#pragma once

#include "entity.h"

class Room;

class Player : public Entity
{
public:
	Player(const char* name, const char* description, Entity* parent);
	virtual ~Player();

	void Go(vector<string> args);
	void Pick(vector<string> args);
	void Drop(vector<string> args);
	void Open(vector<string> args);
	void Close(vector<string> args);
	void Inventory();
	Room* GetRoom();

};

