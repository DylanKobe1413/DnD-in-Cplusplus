#include "Dice.h"
#include "Stats.h"
#include "Enemies.h"
#include "Combat.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

//stats variables for external usage.
int Str = 10, Dex = 10, Con = 10, Int = 10, Wis = 10, Cha = 10;
int stat_bonus = 0;
int ammo = 0;
string Class;
string FightingStyle;
string weapon_dmg;
string weapon_type;
string weapon_catagory;
string weapon_stat_bonus;
string weapon1, weapon2, weapon3;
int weapon_range;
string weapon_function;
string armor1, armor2;
string armor_type;
string pack;
string item1, item2, item3, item4;
string shield;
int HP;
string hitdice;
int speed = 30;
int xp = 0;
int level = 1;
int Str_Save;
bool Proficiency_Simple_Weapons = false;
bool Proficiency_Martial_Weapons = false;
int prof_bonus = 0;
int AC;
int P_initiative = 0;

//Dice variables for external usage.
int dice_roll;
int player_dice_roll;
int enemy_dice_roll;
bool crit = false;
bool crit_fail = false;
bool advantage = false;
bool disadvantage = false;

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

// Combat variables for external usage.
int Distance;

int main()
{
	srand((unsigned)time(NULL));
	Dice Dice;
	Stats Player_Stats;
	Enemy Wolf;
	Combat PlayervsWolf;

	Player_Stats.set_Stats();
	Player_Stats.set_Class();
	Wolf.set_Stats("Wolf");

	
	Distance = 60;
	Dice.set_Player_Initiative(Player_Stats, Dex);
	Dice.set_Enemy_Initiative(Wolf, Wolf_Dex, wolf);
	PlayervsWolf.Initiative_compare(P_initiative, E_initiative);
	PlayervsWolf.Set_Player_Combat_Options(1, 1, 1, 1);
	PlayervsWolf.StartCombat(Player_Stats, Wolf, Dice);
	









	return 0;
}