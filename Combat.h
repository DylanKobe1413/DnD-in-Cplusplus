#pragma once
#include <iostream>
#include "Stats.h"
#include "Dice.h"
#include "Enemies.h"
#include <string>
using namespace std;
extern int Distance;
class Combat
{

private:
	int input;

	bool combat;
	bool compare;
	bool P_turn;
	int P_attack1;
	int P_attack2;
	int P_move1;
	int P_move2;

	bool E_turn;
	string E_attack1;
	
public :

	void Initiative_compare(int player, int enemy);
	void check_player_distance();
	void StartCombat(Stats player_character, Enemies enemy, Dice dice);
	void setEnemyBehavior(Enemies enemy, Dice dice);
	void Set_Player_Combat_Options(int attack1, int attack2, int move1, int move2);
	void PrintPlayerCombatOptions();
	void Player_Select(Stats player, Enemies enemy, Dice dice);
	void Enemy_turn();
	void Player_turn();
	void Check_Distance();








};