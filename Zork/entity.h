#pragma once

#include <string>
#include <list>
#include <vector>

using namespace std;

enum Type 
{
	ITEM,
	ROOM,
	EXIT,
	CREATURE,
	PLAYER,
	NPC
};

class Entity
{
public:
	Entity(const char* name, const char* description, Entity* parent);
	virtual ~Entity();

	void Look() const;
	Entity* Find(Type entityType) const;
	Entity* Find(string args, Type entityType) const;
	Entity* Find(Entity* entity, Type entityType) const;
	Entity* FindInventoryAndRoom(string args, Type entityType) const;
	void Adoption(Entity* newParent);

	string name;
	string description;
	Type entityType;
	Entity* parent;
	list<Entity*> content; //this would be the childs of our entities, a room contains exits..and other kind of things like the player and stuff

};

