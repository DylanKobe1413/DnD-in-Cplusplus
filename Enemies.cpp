#include "Enemies.h"


void Enemies::set_Stats(string Enemy_Name)
{
	if (Enemy_Name == "Wolf")
	{
		E_initiative = Wolf_initiative;
		E_HP = Wolf_HP;
		E_speed = Wolf_speed;
		E_AC = Wolf_AC;
		E_Str = Wolf_Str, E_Dex = Wolf_Dex, E_Con = Wolf_Con, E_Int = Wolf_Int, E_Wis = Wolf_Wis, E_Cha = Wolf_Cha;
		E_weapon = Wolf_weapon;
		E_name = Enemy_Name;
		E_weapon_range = 5;
	}


}

int Enemies::get_Stat(int stat)
{
	return stat;
}

int Enemies::get_stat_bonus(int stat)
{
	if (stat == 12 || stat == 13)
		E_stat_bonus = 1;
	else if (stat == 14 || stat == 15)
	{
		E_stat_bonus = 2;
	}
	else if (stat == 8 || stat == 9)
	{
		E_stat_bonus = 1;
	}
	else if (stat == 16 || stat == 17)
	{
		E_stat_bonus = 3;
	}
	return E_stat_bonus;
}