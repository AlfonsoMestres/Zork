#pragma once

#include <vector>

using namespace std;

class Player;
class Entity;

class World
{
public:
	World();
	~World();

	bool DoAction(string args);
	vector<string> ParseAction(string args);

private:
	vector<Entity*> entities;
	Player* user;

};

