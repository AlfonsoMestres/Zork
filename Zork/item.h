#pragma once

#include "entity.h"

class Item : public Entity
{
public:
	Item(const char* name, const char* description, Entity* parent, bool canBePicked, bool canContain, Item* combineWith = NULL, Item* resultCombination = NULL, Item* generateItem = NULL);
	virtual ~Item();

	void Look() const;
	void LookContent() const;
	void UseWith(Item* itemUsingWith);
	void GenerateItemIfNeeded();

	bool canBePicked;
	bool canContain; //TODO: Also we need to handle if this can be contained
	Item* combineWith; //The only item that could be combined to obtain a new elemet
	Item* resultCombination; //The item to be replaced once combined
	Item* generateItem; //Picking up make an iteam appear, this should be an entity to generate monsters like rats or cockroaches
};

