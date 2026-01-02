#include "Dice.h"
#include "Stats.h"
#include "Enemies.h"
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
	Stats Player_Stats;
	Enemy Wolf;
	Combat PlayervsWolf;
	Stats("Wolf", Wolf);
	//Stat SETUP
	Player_Stats.set_Stats();
	Player_Stats.set_Class();
	Wolf.set_Stats("Wolf");

	//Combat
	PlayervsWolf.set_distance(60);
	PlayervsWolf.Initiative_compare(Dice.set_Initiative(Player_Stats), Dice.set_Enemy_Initiative(Wolf, Wolf_Dex, wolf));
	PlayervsWolf.Set_Player_Combat_Options(1, 1, 1, 1);
	PlayervsWolf.StartCombat(Player_Stats, Wolf, Dice);
	









	return 0;
}