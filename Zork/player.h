#pragma once

#include "creature.h"

class Player : public Creature
{
public:
	Player(const char* name, const char* description, Entity* parent);
	virtual ~Player();

	void Go(vector<string> args);
	void Pick(vector<string> args);
	void Drop(vector<string> args);
	void Unlock(vector<string> args);
	void Lock(vector<string> args);
	void LookAt(vector<string> args);
	void Use(vector<string> args);
	void PickFrom(vector<string> args);
	void Put(vector<string> args);
	void Inventory();

};

