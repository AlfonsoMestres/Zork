#include <iostream>
#include "item.h"


Item::Item(const char* name, const char* description, Entity* parent, bool canBePicked, Item* combineWith, Item* resultCombination, Item* generateItem)
	: Entity(name, description, parent), canBePicked(canBePicked), combineWith(combineWith), resultCombination(resultCombination), generateItem(generateItem)
{
	type = ITEM;
}


Item::~Item()
{
}

void Item::Look() const {
	cout << "Its a " << name << ", " << description << endl;
}

//Using inventory items with environment items
void Item::UseWith(Item* itemUsingWith) {
	if (combineWith == itemUsingWith || itemUsingWith->combineWith == this) {
		if (itemUsingWith->resultCombination != NULL) {
			itemUsingWith->resultCombination->Adoption(itemUsingWith->parent);
			cout << "You used " << name << " with " << itemUsingWith->name << ", you now have a " << itemUsingWith->resultCombination->description << endl;
			itemUsingWith->parent->content.remove(itemUsingWith);
		} else {
			resultCombination->Adoption(parent);
			cout << "You used " << name << " with " << combineWith->name << ", you now have a " << resultCombination->description << endl;
			parent->content.remove(this);
		}
	} else {
		cout << "You can't use " << name << " with that." << endl;
	}
}

void Item::GenerateItemIfNeeded() {
	if (generateItem != NULL) {
		generateItem->Adoption(parent);
		cout << "There was a " << generateItem->name << " under it" << endl;
	}
}