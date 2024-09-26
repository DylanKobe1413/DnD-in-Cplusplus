#pragma once
#include<ctype.h>
#include<stdio.h>
#include <iostream>
#include <string>
using namespace std;
/*  Wolf_Str = 13, Wolf_Dex = 15, Wolf_Con = 15, Wolf_Int = 2, Wolf_Wis = 12, Wolf_Cha = 6;
	 Wolf_stat_bonus = 0;
	 wolf_Ac = 14;
	 wolf_speed = 50;
	 wolf_HP = 13;
	 wolf_dmg = 2d4+dex

	 WOLF CUB scenario animal handling for companion or bonuses for preventing the fight 
	 make a flee scenario in the case that the player is losing the fight.
 */
extern string wolf;
extern int Wolf_Str, Wolf_Dex, Wolf_Con, Wolf_Int, Wolf_Wis, Wolf_Cha;
extern int Wolf_AC;
extern int Wolf_speed;
extern int Wolf_HP;
extern int Wolf_initiative;
extern string Wolf_weapon;
extern int E_stat_bonus;
extern int E_weapon_hit_bonus;
extern int E_weapon_dmg_bonus;
extern int E_initiative;
extern int E_AC;
extern int E_HP;
extern int E_speed;
extern int E_Str, E_Dex, E_Con, E_Int, E_Wis, E_Cha;
extern string E_weapon;
extern string E_weapon_dmg;
extern string E_weapon_type;
extern string E_weapon_function;
extern int E_weapon_range;
extern string E_name;

class Enemies
{

private:


public:
	
	void set_Stats(string Enemy_Name);
	
	int get_Stat(int stat);

	int get_stat_bonus(int stat);
};

