#include "Dice.h"
#include "Stats.h"
#include "Enemies.h"
#include "Combat.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

// remove these and merge into stats all under one class
// Enemies variables for external usage.

//wolf stats.
string wolf = "Wolf";
int Wolf_Str = 12, Wolf_Dex = 15, Wolf_Con = 12, Wolf_Int = 3, Wolf_Wis = 12, Wolf_Cha = 6;
int Wolf_AC = 14;
int Wolf_speed = 40;
int Wolf_HP = 13;
int Wolf_initiative = 0;
string Wolf_weapon = "Bite";

// general enemy variables.
int E_stat_bonus = 0;
int E_weapon_hit_bonus = 0;
int E_weapon_dmg_bonus = 0;
int E_initiative = 0;
int E_AC = 0;
int E_HP = 0;
int E_speed = 0;
int E_Str, E_Dex, E_Con, E_Int, E_Wis, E_Cha;
string E_weapon;
string E_weapon_dmg;
string E_weapon_type;
string E_weapon_function;
int E_weapon_range;
string E_name;

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
	PlayervsWolf.Initiative_compare(Dice.set_Player_Initiative(Player_Stats), Dice.set_Enemy_Initiative(Wolf, Wolf_Dex, wolf));
	PlayervsWolf.Set_Player_Combat_Options(1, 1, 1, 1);
	PlayervsWolf.StartCombat(Player_Stats, Wolf, Dice);
	









	return 0;
}