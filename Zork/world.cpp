#include <iostream>
#include "exit.h"
#include "item.h"
#include "room.h"
#include "player.h"
#include "npc.h"
#include "world.h" 

World::World()
{
	Room* front = new Room("Front door", ", a big wooden door with the number 13 on the top.");
	Room* garden = new Room("Garden", ", pretty green..with an empty dog house and fancy garden stuff.");
	Room* street = new Room("Street", ", everyone is sleeping..too quiet for you.");
	Room* hall = new Room("Hall", ", fancy forniture.. fancy drawings.. too much for Fred.");
	Room* tv = new Room("Living room", ", a old room with a weird smell..also a giant TV in the middle (75 inches...!).");
	Room* basement = new Room("Basement", ", even the basement smells like your best cologne...");
	Room* freedom = new Room("Car", "You fixed your mistake!! Time to scape!!!");

	Item* key = new Item("Key", "A little metallic key with a label, it says '2nd Key: Front door'.", NULL, true, false);
	Item* doorMat = new Item("Doormat", "it has a drawing of two birds kissing, there's something under it.", front, true, false, NULL, NULL, key); 
	Item* fountain = new Item("Fountain", "This little guy peeing in the bowl makes you feel uncomfortable.", garden, false, false);
	Item* bucket2 = new Item("Bucket", "full of water.", NULL, true, false);
	Item* bucket = new Item("Bucket", "standard blue, cannot be recycled.", garden, true, false, fountain, bucket2); 
	Item* electric2 = new Item("Post", "no more buzzing sound.", NULL, false, false);
	Item* electric = new Item("Post", "You can hear buzzing sounds inside.", street, false, false, bucket2, electric2);
	Item* closet = new Item("Closet", "It's half-open", tv, false, true);
	Item* wallet = new Item("Wallet", "Its full of fake Ids.. except one.", closet, true, false);

	//This needs to be implemented as return exits too
	Exit* toStreet = new Exit("South", "A little stone road", front, street, NULL, false, false);
	Exit* toGarden = new Exit("West", "A wall of flowers", front, garden, NULL, false, false);
	Exit* toHall = new Exit("North", "Big wooden door", front, hall, key, true, false);
	Exit* toTv = new Exit("North", "Two cristal doors", hall, tv, NULL, false, false);
	Exit* toTv2 = new Exit("West", "An window", garden, tv, electric2, true, true);
	Exit* toBasement = new Exit("East", "A wooden door", tv, basement, NULL, false, false);
	Exit* toFreedom = new Exit("South", "car, the engine is on..but you need your wallet", street, freedom, wallet, true, false);

	//Return exits
	Exit* toFront = new Exit("North", "A little stone road", street, front, NULL, false, false);
	Exit* toFront1 = new Exit("East", "A wall of flowers leading to the front door", garden, front, NULL, false, false);
	Exit* toFront2 = new Exit("South", "Big wooden door", hall, front, key, false, false);
	Exit* toHall1 = new Exit("South", "Two cristal doors", tv, hall, NULL, false, false);
	Exit* toGarden1 = new Exit("West", "A electric window", tv, garden, electric2, true, true);
	Exit* toTv1 = new Exit("West", "A wooden door", basement, tv, NULL, false, false);

	//TODO: Clock ticks into turns
	Npc* fred = new Npc("Fred", "It's the house owner.", basement, true, toTv1, 4);
	user = new Player("You", "A thief with 0 experience at thieving", front);

	//In case we need to search for something globaly or to delete it for memory alloc
	entities.push_back(front);
	entities.push_back(garden);
	entities.push_back(street);
	entities.push_back(hall);
	entities.push_back(tv);
	entities.push_back(basement);
	entities.push_back(freedom);

	entities.push_back(key);
	entities.push_back(doorMat);
	entities.push_back(bucket2);
	entities.push_back(bucket);
	entities.push_back(electric);
	entities.push_back(electric2);
	entities.push_back(closet);
	entities.push_back(wallet);
	entities.push_back(fountain);

	entities.push_back(toStreet);
	entities.push_back(toGarden);
	entities.push_back(toHall);
	entities.push_back(toTv);
	entities.push_back(toTv2);
	entities.push_back(toBasement);
	entities.push_back(toFreedom);

	entities.push_back(toFront);
	entities.push_back(toFront1);
	entities.push_back(toFront2);
	entities.push_back(toHall1);
	entities.push_back(toGarden1);
	entities.push_back(toTv1);

	entities.push_back(fred);
	entities.push_back(user);

}

World::~World()
{
	for (std::vector<Entity*>::iterator it = entities.begin(); it != entities.end(); ++it) 
		delete *it;

	entities.clear();
}

bool World::DoAction(string args) //Later this will be changed to directly an array of args, so we dont need to use the ActionParser
{
	bool ret = true;

	vector<string> parsedArgs = ParseAction(args);

	switch (parsedArgs.size())
	{
	case 1:
		if (parsedArgs[0] == "look") {
			user->LookRoom();
		}
		else if (parsedArgs[0] == "inventory") {
			user->Inventory();
		}
		else
			ret = false;
		break;
	case 2:
		if (parsedArgs[0] == "go") {
			user->Go(parsedArgs);
		}
		else if (parsedArgs[0] == "look") {
			user->LookAt(parsedArgs);
		}
		else if (parsedArgs[0] == "pick") {
			user->Pick(parsedArgs);
		}
		else if (parsedArgs[0] == "drop") {
			user->Drop(parsedArgs);
		}
		else if (parsedArgs[0] == "unlock") {
			user->Unlock(parsedArgs);
		} 
		else if (parsedArgs[0] == "lock") {
			user->Lock(parsedArgs);
		}
		else
			ret = false;
		break;
	case 3:
		if (parsedArgs[0] == "use") {
			user->Use(parsedArgs);
		}
		else if (parsedArgs[0] == "pick") {
			user->PickFrom(parsedArgs);
		}
		else if (parsedArgs[0] == "put") {
			user->Put(parsedArgs);
		}
		
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