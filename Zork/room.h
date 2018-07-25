#pragma once

#include "entity.h"

class Exit;
class Item;

class Room : public Entity
{
public:
	Room(const char* name, const char* description);
	virtual ~Room();

	void Look();

	void LookElement(vector<string> args);

};
