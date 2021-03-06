#pragma once

#include <list>
#include "entity.h"

class Exit;
class Item;

using namespace std;

class Room : public Entity
{
public:
	Room(const char* name, const char* description);
	~Room();

	void Look() const;
	void LookElement(vector<string> args) const;

};
