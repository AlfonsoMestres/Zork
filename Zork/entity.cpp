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
