#pragma once

#include <string>
#include <list>
#include <vector>

using namespace std;

class Entity
{
public:
	Entity(const char* name, const char* description, Entity* parent);
	virtual ~Entity();

	void Look() const;
	void Adoption(Entity* newParent);

	string name;
	string description;
	Entity* parent;
	list<Entity*> content; //this would be the childs of our entities, a room contains exits..and other kind of things like the player and stuff

};

