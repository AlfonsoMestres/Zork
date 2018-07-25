#include <iostream>
#include <string>
#include "world.h"

using namespace std;

int main()
{
	cout << "Zork!" << endl << endl;
	cout << "Your name is Alan, you are having a test to join the most famous thieving company 'WYIO' (WhatsYoursItsOurs)." << endl;
	cout << "As an entrance exam, the company decided to test your thievery stealing something from one of your neighbours and obviously, you aced it ..." << endl;
	cout << "Except for one little mistake.. you lost your wallet in the house! YOU SHOULD RECOVER THE WALLET!" << endl << endl;
	cout << " --------------------------------- START ---------------------------------------" << endl;
	cout << "You walked away from your car, approaching to the front door.. you notice a sound inside the house." << endl << endl;

	string player_input = "";
	World new_world;

	new_world.DoAction("look");

	while (1)
	{
		cout << "---------------------------------ACTIONS----------------------------------" << endl;
		cout << "go *direction* | look *element* | pick *item* | drop *item* | intentory" << endl;
		cout << "pick *item1* *item2* | put *item1* *item2* | use *item1* *item2* " << endl;
		cout << "lock *direction* | unlock *direction* | exit " << endl;
		cout << "--------------------------------------------------------------------------" << endl << endl;
		getline(cin, player_input);
		system("cls");
		if (player_input == "exit")
			break;

		if (new_world.DoAction(player_input) == false)
			cout << "You can't do that." << endl;
	}
	
	cout << "Thanks for playing!!!" << endl;
	return 0;
}
