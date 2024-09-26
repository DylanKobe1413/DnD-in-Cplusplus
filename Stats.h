#pragma once
#include<ctype.h>
#include<stdio.h>
#include <iostream>
#include <string>
using namespace std;

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