#pragma once

#include "creature.h"

class Npc : public Creature
{
public:
	Npc(const char* name, const char* description, Entity* parent, bool moving, Exit* headedTo, int turnsToMove);
	virtual ~Npc();

	void Look() const;
	void Turn();

	bool moving;
	Exit* headedTo;
	int turns;
	int turnsToMove;
};

