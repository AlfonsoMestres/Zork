#pragma once
#include "room.h"
#include "player.h"
#include "entity.h"

enum Direction
{
	North,
	South,
	East,
	West,
	Up,
	Down
};

class Exit : public Entity
{
public:
	Exit(const char* name, const char* description, Room* source, Room* destination, Item* itemToOpen, bool locked);
	virtual ~Exit();

	void Look() const;
	string GetDestinationName();

	Direction* direction;
	Room* source;
	Room* destination;
	Item* itemToOpen;
	bool locked;

};

