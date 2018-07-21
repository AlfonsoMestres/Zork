#include <iostream>
#include <iterator>
#include <sstream>
#include "exit.h"
#include "room.h"
#include "player.h"
#include "world.h" 

World::World()
{
	Room* cell = new Room("Cell", ", its dark and you can't barely see the walls.");
	Room* hall = new Room("Hall", ", its wet and you smell something awful.");
	Exit* door = new Exit("North", "Rusty old door", cell, hall);
	Exit* door1 = new Exit("South", "Rusty old door", hall, cell);
	user = new Player("You!", "A big bad boy with a big bad luck", cell);

	entities.push_back(cell);
	entities.push_back(hall);
	entities.push_back(door);
	entities.push_back(user);

}

World::~World()
{
}

bool World::DoAction(string args) //esto seria algo asi como vector<string*> args
{
	bool ret = true;

	vector<string> parsedArgs = ParseAction(args);

	switch (parsedArgs.size())
	{
	case 1:
		if (parsedArgs[0] == "look") {
			cout << "You are in a "; user->GetRoom()->Look();
		}
		else
			ret = false;
		break;
	case 2:
		if (parsedArgs[0] == "go")
		{
			user->Go(parsedArgs);
		}
		else
			ret = false;
		break;
	case 3:
		break;
	default:
		ret = false;
		break;
	}

	return ret;
}

vector<string> World::ParseAction(string args) //copiar contenido a otro es rellenar memoria porque si, esto debera ser directo en vez de parsearlo 
{
	int len = args.length();
	vector<string> subArray;

	for (int j = 0, k = 0; j < len; j++) {
		if (args[j] == ' ') {
			string ch = args.substr(k, j - k);
			k = j + 1;
			subArray.push_back(ch);
		}
		if (j == len - 1) {
			string ch = args.substr(k, j - k + 1);
			subArray.push_back(ch);
		}
	}

	return subArray;
}