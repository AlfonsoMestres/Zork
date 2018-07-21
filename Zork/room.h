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

	Exit* FindExit(vector<string> args);
	Item* FindItem(vector<string> args);

};
