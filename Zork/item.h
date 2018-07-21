#pragma once

#include "entity.h"

class Item : public Entity
{
public:
	Item(const char* name, const char* description, Entity* parent);
	virtual ~Item();

	void Look() const;

};

