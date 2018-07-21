#pragma once

#include <vector>
#include "entity.h"

using namespace std;

class Player;
class Entity;

class World
{
public:
	World();
	virtual ~World();

	bool DoAction(string args);
	vector<string> ParseAction(string args);

private:
	vector<Entity*> entities;
	Player* user;

};

