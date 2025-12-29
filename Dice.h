#pragma once
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "Stats.h"
#include <string>
using namespace std;

extern int dice_roll;
extern int player_dice_roll;
extern int enemy_dice_roll;
extern bool crit;
extern bool crit_fail;
extern bool advantage;
extern bool disadvantage;

class Dice
{
private:
	// fix stat_roll to print when specified!
	int Stat;
	bool print = false;

public:

	void roll(int num_of_dice, int sides);

	void roll_Dice(int num_of_dice, int sides);

	void disadvantage_roll();

	void stat_roll(Stats character, int stat, int num_of_dice, int sides);

	void Enemy_stat_roll(Enemy enemy, int stat, int num_of_dice, int sides);

	void Player_Attack_roll(Stats character, Enemies enemy, string weapon);

	void Player_Damage_roll(string weapon, Enemy enemy, Stats Player);

	void Enemy_Attack_roll(Enemy enemy, string Enemy_weapon);

	void Enemy_Damage_roll(string E_weapon);

	void get_Weapon_Properties(string weapon_name);

	void get_Enemy_Weapon_Properties(string Enemey_weapon_name);
		
	// for the player character
	void get_Weapon_Stat_Bonus(string weapon);

	void get_Weapon_Proficiency_And_Print_Dice(string weapon);

	void get_Armor_Properties(string armor, Stats player);

	void set_Player_Initiative(Stats player, int dext);

	void set_Enemy_Initiative(Enemy enemy, int Dex, string enemy_name);



};