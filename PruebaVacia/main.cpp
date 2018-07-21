#include <iostream>
#include <string>
#include "world.h"

using namespace std;

int main()
{
	cout << "Let's play a game...\n";
	cout << "----------------\n\n";
	string player_input = "";

	World new_world;

	new_world.DoAction("look");

	while (1)
	{
		getline(cin, player_input);
		if (player_input == "exit")
			break;

		if (new_world.DoAction(player_input) == false)
			cout << "You can't do that.\n";
	}
	
	cout << "\nThanks for playing, Bye!\n";
	return 0;
}