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
	bool combat;
	bool compare;
	bool advantage;
	bool disadvantage;
	//player
	bool P_attack1;
	bool P_attack2;
	bool P_move1;
	bool P_move2;
	bool P_turn;
	//enemy
	bool E_turn;
	string E_attack1;
	
public :
	void set_distance(int Distance);
	int  get_distance();
	void Initiative_compare(int player, int enemy);
	void check_distance(Stats &Character);
	void StartCombat(Stats &Player, Stats &enemy, Dice dice);
	void setEnemyBehavior(Stats &Enemy, Dice dice, Stats &Player);
	void Set_Player_Combat_Options(bool attack1, bool attack2, bool move1, bool move2);
	void PrintPlayerCombatOptions(Stats &Player);
	void Player_Select(Stats &Player, Stats &Enemy, Dice dice);
	void Enemy_turn();
	void Player_turn();
	void Check_Distance();








};