#include <iostream>
#include "exit.h"
#include "room.h"

Room::Room(const char* name, const char* description) : Entity(name, description, NULL)
{
}

Room::~Room()
{
}

void Room::Look()
{
	cout << name << description << endl;
	cout << "You can see inside:" << endl;
	//list elements inside room, EXITS, ITEMS and CREATURES (not implemented yet)
	for (list<Entity*>::iterator it = content.begin(); it != content.end(); ++it) {
		(*it)->Look();
	}
}

Exit* Room::FindExit(vector<string> args)
{
	//NEXT STEP
	//Recorrer un array con todos los elementos, encontrar el tipo EXIT y mirar si alguno tiene nombre 'args[1]', en caso positivo devolverlo, en caso contrario NULL
	//en un principio mirare TODOS los items, luego ya veremos con el enum
	for (list<Entity*>::iterator it = content.begin(); it != content.end(); ++it) {
		if ((*it)->name.compare(args[1]) == 0) {
			return (Exit*)*it;
		};
	}

	return NULL;
}
