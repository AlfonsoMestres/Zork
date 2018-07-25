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
	Exit(const char* name, const char* description, Room* source, Room* destination, Item* itemToOpen, bool locked, bool itemCondition); //itemCondition would be a state of an item (if Post elecrified then open)
	virtual ~Exit();

	void Look() const;
	string GetDestinationName() const;
	void SwapSourceDestination();

	Direction* direction;
	Room* source;
	Room* destination;
	Item* itemToOpen;
	bool itemCondition; //TODO: If this true, we should check if there's an item in our World that fits the itemToOpen
	bool locked;

};

