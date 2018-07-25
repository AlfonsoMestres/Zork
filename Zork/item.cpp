#include <iostream>
#include "item.h"


Item::Item(const char* name, const char* description, Entity* parent, bool canBePicked, bool canContain, Item* combineWith, Item* resultCombination, Item* generateItem)
	: Entity(name, description, parent), canBePicked(canBePicked), canContain(canContain), combineWith(combineWith), resultCombination(resultCombination), generateItem(generateItem)
{
	entityType = ITEM;
}

Item::~Item()
{
}

void Item::Look() const {
	cout << "A " << name << ", " << description << endl;
	if (content.size() > 0)
		LookContent();
}

void Item::LookContent() const {
	if (content.size() > 0) {
		cout << "Contains: " << endl;
		for (list<Entity*>::const_iterator it = content.begin(); it != content.cend(); ++it)
			cout << (*it)->name << endl;
	}
}

void Item::UseWith(Item* itemUsingWith) {
	if (combineWith == itemUsingWith || itemUsingWith->combineWith == this) { //this would get the generated element from one of the used elements (just 1 contains the element to generate)
		if (itemUsingWith->resultCombination != NULL) {
			itemUsingWith->resultCombination->Adoption(itemUsingWith->parent);
			cout << "Used " << name << " with " << itemUsingWith->name << ", now its " << itemUsingWith->resultCombination->description << endl;
			itemUsingWith->parent->content.remove(itemUsingWith);
		} else {
			resultCombination->Adoption(parent);
			cout << "Used " << name << " with " << combineWith->name << ", now its " << resultCombination->description << endl;
			parent->content.remove(this);
		}
	} else {
		cout << "Can't use " << name << " with that." << endl;
	}
}

void Item::GenerateItemIfNeeded() {
	if (generateItem != NULL) {
		generateItem->Adoption(parent);
		cout << "There was a " << generateItem->name << " under it" << endl;
		generateItem = NULL; //We empty the element so we avoid getting duplicate items
	}
}