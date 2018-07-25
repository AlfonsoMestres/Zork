#include <iostream>
#include "entity.h"

Entity::Entity(const char* name, const char* description, Entity* parent) : name(name), description(description), parent(parent) 
{
	//this means that the father should change it content to have this instance
	if (parent != NULL) {
		parent->content.push_back(this);
	}
}

Entity::~Entity()
{
}

void Entity::Look() const
{
	cout << name << " " << description << endl;
}

///Find - Search its inners with name
Entity* Entity::Find(string args, Type entityType)
{
	for (list<Entity*>::const_iterator it = content.begin(); it != content.cend(); ++it)
	{
		if (entityType != NULL) { //We can restrict search with an Entity Type
			if ((*it)->entityType == entityType)
			{
				if ((*it)->name.compare(args) == 0)
					return *it;
			}
		} else { //If not, we will search all the entities in the content
			if ((*it)->name.compare(args) == 0)
				return *it;
		}
		
	}

	return NULL;
}

///Find - Search its inners a match for the element
Entity* Entity::Find(Entity* entity, Type entityType) 
{
	for (list<Entity*>::const_iterator it = content.begin(); it != content.cend(); ++it) 
	{
		if ((*it)->entityType == entityType)
		{
			if ((*it) == entity)
			{
				return *it;
			}
		}
	}

	return NULL;
}

///FindInventoryAndRoom - Search the inners of the inventory and the inners of its room
Entity* Entity::FindInventoryAndRoom(string args, Type entityType)
{
	Entity* itemFound = Find(args, entityType);
	if (itemFound != NULL)
		return itemFound; //If found it in the inventory, no more searching
	
	//Search it in the room
	itemFound = parent->Find(args, entityType);
	return itemFound;
	
}

///Adoption - Chaning parents or giving parents to orphans
void Entity::Adoption(Entity* newParent)
{
	//Kill his father
	if (parent != NULL){
		parent->content.remove(this); 
	} 

	//Set an impostor
	parent = newParent;

	//Sign adoptions papers
	if (parent != NULL) {
		parent->content.push_back(this);
	}

}
