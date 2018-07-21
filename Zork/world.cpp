#include <iostream>
#include <iterator>
#include <sstream>
#include "exit.h"
#include "item.h"
#include "room.h"
#include "player.h"
#include "world.h" 

World::World()
{
	Room* cell = new Room("Cell", ", its dark and you can't barely see the walls.");
	Room* corridor = new Room("Corridor", ", its prety long..i heard some noises...");
	Room* hall = new Room("Hall", ", its wet and you smell something awful.");
	Item* key = new Item("Key", "A rusted one", cell);
	Exit* door = new Exit("North", "Rusty old door", cell, corridor, key, true);
	Exit* door1 = new Exit("South", "Rusty old door", corridor, cell, NULL, false);
	Exit* safeDoor = new Exit("North", "Metallic door", corridor, hall, NULL, false);
	Exit* safeDoor1 = new Exit("South", "Metallic door", hall, corridor, NULL, false);
	
	user = new Player("You!", "A big bad boy with a big bad luck", cell);

	//In case we need to search for something globaly or to delete it for memory alloc
	entities.push_back(cell);
	entities.push_back(corridor);
	entities.push_back(hall);
	entities.push_back(door);
	entities.push_back(door1);
	entities.push_back(safeDoor);
	entities.push_back(safeDoor1);
	entities.push_back(user);

}

World::~World()
{
}

bool World::DoAction(string args) //Later this will be changed to directly an array of args, so we dont need to use the ActionParser
{
	bool ret = true;

	vector<string> parsedArgs = ParseAction(args);

	switch (parsedArgs.size())
	{
	case 1:
		if (parsedArgs[0] == "look") {
			cout << "You are in a "; user->GetRoom()->Look();
		}
		else if (parsedArgs[0] == "inventory") {
			user->Inventory();
		}
		else
			ret = false;
		break;
	case 2:
		if (parsedArgs[0] == "go")
		{
			user->Go(parsedArgs);
		}
		else if (parsedArgs[0] == "pick") {
			user->Pick(parsedArgs);
		}
		else if (parsedArgs[0] == "drop") {
			user->Drop(parsedArgs);
		}
		else if (parsedArgs[0] == "open") {
			user->Open(parsedArgs);
		} 
		else if (parsedArgs[0] == "close") {
			user->Close(parsedArgs);
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

///Take the input and split them into parts so we can manage them clearly
vector<string> World::ParseAction(string args) //Filling new memory slots with ducplicate content is wasting memory, we should avoid this in next steps and make it directly
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