#pragma once
#include <iostream>
#include "Stats.h"
#include "Dice.h"
#include <string>
using namespace std;

class Combat
{

private:
	int input;
	int distance;
	int P_attack1;
	int P_attack2;
	int P_move1;
	int P_move2;
	bool combat;
	bool compare;
	bool advantage;
	bool disadvantage;
	bool P_turn;
	

	bool E_turn;
	string E_attack1;
	
public :
	void set_distance(int Distance);
	int  get_distance();
	void Initiative_compare(int player, int enemy);
	void check_distance(Stats Character);
	void StartCombat(Stats Player, Enemy enemy, Dice dice);
	void setEnemyBehavior(Enemy enemy, Dice dice, Stats Player);
	void Set_Player_Combat_Options(int attack1, int attack2, int move1, int move2);
	void PrintPlayerCombatOptions(Stats Player);
	void Player_Select(Stats Player, Enemy enemy, Dice dice);
	void Enemy_turn();
	void Player_turn();
	void Check_Distance();








};