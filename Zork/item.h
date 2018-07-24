#pragma once

#include "entity.h"

class Item : public Entity
{
public:
	Item(const char* name, const char* description, Entity* parent, bool canBePicked, Item* combineWith, Item* resultCombination, Item* generateItem = NULL);
	virtual ~Item();

	void Look() const;
	void UseWith(Item* itemUsingWith);
	void GenerateItemIfNeeded();

	bool canBePicked;
	Item* combineWith;
	Item* resultCombination;
	Item* generateItem; //Picking up make an iteam appear, this should be an entity to generate monsters like rats or cockroaches
};

