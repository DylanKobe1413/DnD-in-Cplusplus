#pragma once
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "Stats.h"
#include <string>
using namespace std;

class Dice
{
private:
	int dice_roll;
	int player_dice_roll;
	int enemy_dice_roll;
	int Stat;
	bool print = false;
	bool crit;
	bool crit_fail;
public:
	void set_dice_roll(int outcome);

	int get_dice_roll();
	// add these two functions below!
	void set_advantage(bool T_F);

	void set_disadvantage(bool T_F);

	void roll(int num_of_dice, int sides);

	void roll_Dice(int num_of_dice, int sides);
	

	void Stat_roll(Stats character, int stat, int num_of_dice, int sides);

	void Enemy_stat_roll(Enemy enemy, int stat, int num_of_dice, int sides);

	void Attack_roll(Stats character, Enemy enemy, string weapon);

	void Damage_roll(string weapon, Enemy enemy, Stats Character);

	void Enemy_Attack_roll(Enemy enemy, string Enemy_weapon, Stats Character);

	void Enemy_Damage_roll(string E_weapon, Stats Player);

	void get_Weapon_Properties(string weapon_name, Stats Character);

	void get_Enemy_Weapon_Properties(string Enemey_weapon_name);
		
	// for the player character
	void get_Weapon_Stat_Bonus(string weapon, Stats Character);

	void get_Weapon_Proficiency_And_Print_Dice(string weapon, Stats Character);

	void get_Armor_Properties(string armor, Stats Character);

	int set_Initiative(Stats Character);

	int set_Enemy_Initiative(Enemy enemy, int Dex, string enemy_name);



};