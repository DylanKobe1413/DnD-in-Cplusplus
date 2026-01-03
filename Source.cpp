#include "Dice.h"
#include "Stats.h"
#include "Combat.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

int main()
{   //Declerations
	srand((unsigned)time(NULL));
	Dice Dice;
	Stats Player;
	Stats Wolf("Wolf");
	Combat PlayervsWolf;

	//Stat SETUP
	Player.set_Stats();
	Player.set_Class();
	

	//Combat
	PlayervsWolf.set_distance(60);
	// complier read from right to left for this instance so i put the player on the far right so they can have their initiative roll printed out first.
	PlayervsWolf.Initiative_compare(Dice.set_Initiative(Wolf), Dice.set_Initiative(Player));
	PlayervsWolf.Set_Player_Combat_Options(1, 1, 1, 1);
	PlayervsWolf.StartCombat(Player, Wolf, Dice);
	









	return 0;
}