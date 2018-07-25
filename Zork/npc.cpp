#include <iostream>
#include "exit.h"
#include "npc.h"

Npc::Npc(const char* name, const char* description, Entity* parent, bool moving, Exit* headedTo, int turnsToMove) 
	: Creature(name, description, parent), moving(moving), headedTo(headedTo), turnsToMove(turnsToMove), turns(turns)
{
	entityType = NPC;
}

Npc::~Npc()
{
}

void Npc::Look() const
{
	cout << "It's " << name << description << endl;
}

///Turn - This should be called every X number of clock cycles
void Npc::Turn() {
	if (turns >= turnsToMove) {
		turns = 0;
		Go(headedTo);
		//TODO: Handle the two exit programming issue, we should use the SAME exit between connected Rooms not to different
		headedTo->SwapSourceDestination();
	}

	turns++;
}