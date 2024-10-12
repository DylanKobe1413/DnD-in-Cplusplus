#pragma once
#include<ctype.h>
#include<stdio.h>
#include <iostream>
#include <string>
using namespace std;
//variables for Stats class
extern int Str, Dex, Con, Int, Wis, Cha;
extern int stat_bonus;
extern string Class;
extern string FightingStyle;
extern string weapon_dmg;
extern string weapon_type;
extern string weapon_catagory;
extern string weapon_stat_bonus;
extern string weapon1, weapon2, weapon3;
extern int weapon_range;
extern string weapon_function;
extern string armor1, armor2;
extern string armor_type;
extern string pack;
extern string item1, item2, item3, item4;
extern string shield;
extern int HP;
extern string hitdice;
extern int speed;
extern int xp;
extern int level;
extern int Str_Save;
extern bool Proficiency_Simple_Weapons;
extern bool Proficiency_Martial_Weapons;
extern int prof_bonus;
extern int AC;
extern int ammo;
extern int P_initiative;

class Stats
{
 	
private:
	int total = 27;
	int input = 0;
   
	
public:

	void set_Stats();
	
	void set_Class();

	void Starting_Fighter();

	int get_Stat(int stat);

	int get_stat_bonus(int stat);

	void totalCheck();
	
	void check(int response);

	void print_Stats();

	void Limit(int stat);

	void print_out_stat(int stat);

	
};

/*  Wolf_Str = 13, Wolf_Dex = 15, Wolf_Con = 15, Wolf_Int = 2, Wolf_Wis = 12, Wolf_Cha = 6;
	 Wolf_stat_bonus = 0;
	 wolf_Ac = 14;
	 wolf_speed = 50;
	 wolf_HP = 13;
	 wolf_dmg = 2d4+dex

	 WOLF CUB scenario animal handling for companion or bonuses for preventing the fight
	 make a flee scenario in the case that the player is losing the fight.
 */
 // Enemies
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

class Enemy : public Stats
{

public:

	void set_Stats(string Enemy_Name);

	int get_Stat(int stat);

	int get_stat_bonus(int stat);
};