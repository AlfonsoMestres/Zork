#include <iostream>
#include "item.h"


Item::Item(const char* name, const char* description, Entity* parent) : Entity(name, description, parent)
{
	type = ITEM;
}


Item::~Item()
{
}

void Item::Look() const {
	cout << "Its a " << name << ", " << description << endl;
}