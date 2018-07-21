#pragma once

#include "entity.h"

class Exit;

class Room : public Entity
{
public:
	Room(const char* name, const char* description);
	virtual ~Room();

	void Look();

	Exit* FindExit(vector<string> args);

};
