#pragma once
#include<ctype.h>
#include<stdio.h>
#include <iostream>
#include <string>
using namespace std;

class Stats
{
 	
private:
	int total = 27;
	int input = 0;
	int Str = 10, Dex = 10, Con = 10, Int = 10, Wis = 10, Cha = 10;
	int stat_bonus;
	int saving_throw;
	string Class;
	string FightingStyle;
	string hitdice;

public:
	int Initiative = 0;
	string weapon_dmg;
	string weapon_type;
	string weapon_catagory;
	// to get dex strength or could be finesse
	string weapon_stat_bonus;
	string weapon1, weapon2, weapon3;
	int weapon_range;
	string weapon_function;
	string armor1;
	string armor_type;
	//backpack?
	string item1, item2, item3, item4;
	string shield;
	bool Proficiency_Simple_Weapons = false;
	bool Proficiency_Martial_Weapons = false;
	int prof_bonus = 0;
	int HP = 1;
	int speed = 20;
	int xp = 0;
	int level = 1;
	int AC = 10;
	int ammo = 0;
	string name = "";
	//setters
	void set_stat_bonus(int statbonus);

	//getters
	int get_Srength();
	int get_Dexterity();
	int get_Constitution();
	int get_Intelligence();
	int get_Wisdom();
	int get_Charisma();

	void set_Stats();

	void set_Class();

	void Starting_Fighter();


	int get_stat_bonus(int stat);

	void totalCheck();
	
	void check(int response);

	void print_Stats();

	void Limit(int stat);

	void print_out_stat(int stat);

	// Enemy Stat setup via constructor
	Stats();
	Stats(string enemy_name, Stats enemy);
};

/*  Wolf_Str = 13, Wolf_Dex = 15, Wolf_Con = 15, Wolf_Int = 2, Wolf_Wis = 12, Wolf_Cha = 6;
	 W`olf_stat_bonus = 0;
	 wolf_Ac = 14;
	 wolf_speed = 50;
	 wolf_HP = 13;
	 wolf_dmg = 2d4+dex

	 WOLF CUB scenario animal handling for companion or bonuses for preventing the fight
	 make a flee scenario in the case that the player is losing the fight.
 */
