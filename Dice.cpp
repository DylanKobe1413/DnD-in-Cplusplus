#include "Dice.h"

void Dice::roll(int num_of_dice, int sides)
{
	for (int i = 1; i <= num_of_dice; i++)
	{
		dice_roll = (rand() % sides + 1);
	}
}

void Dice::roll_Dice(int num_of_dice, int sides)
{
	for (int i = 1; i <= num_of_dice; i++)
	{
		dice_roll = (rand() % sides + 1);
		cout << dice_roll << "...\n";
	}
}


void Dice::stat_roll(Stats character, int stat, int num_of_dice, int sides)
{
	character.get_stat_bonus(stat);
	roll(num_of_dice, sides);
	if (stat_bonus == 0)
	{
		cout << "Rolling a " << num_of_dice << "d" << sides << "\n";
		cout << dice_roll << "...\n\n";
	}
	else
	{
		cout << "Rolling a " << num_of_dice << "d" << sides << " + " << stat_bonus << "\n";
		cout << "Roll result was " << dice_roll << "\n";
		cout << dice_roll << " + " << stat_bonus << " = " << dice_roll + stat_bonus << "...\n\n";
		dice_roll = dice_roll + stat_bonus;
	}
}

void Dice::Enemy_stat_roll(Enemy enemy, int stat, int num_of_dice, int sides)
{
	enemy.get_stat_bonus(stat);

	if (stat_bonus == 0)
	{
		cout << "Rolling a " << num_of_dice << "d" << sides << "\n";
	}
	else
	{
		cout << "Rolling a " << num_of_dice << "d" << sides << "+ " << stat_bonus << "\n";
	}

	roll(num_of_dice, sides);
	cout << dice_roll + stat_bonus << "...\n\n";

}

void Dice::Player_Attack_roll(Stats character, Enemy enemy, string weapon)
{
	get_Weapon_Properties(weapon);
	get_Weapon_Stat_Bonus(weapon);
	stat_roll(character, Stat, 1, 20);
	get_Weapon_Proficiency_And_Print_Dice(weapon);


	if (dice_roll >= E_AC)
	{
		Player_Damage_roll(weapon, enemy, character);

	}
	// crit success and fail
	else if (dice_roll == 20)
	{
		crit = true;
		cout << "Critical strike on the " << E_name << " !\n";
	}
	else if (dice_roll == 1)
	{
		crit_fail = true;
		cout << "Critical Failure!!!!\n";
		if (E_name == "Wolf")
		{
			if (weapon_range >= 0 && weapon_range <= 10)
			{
				cout << "You Miss the wolf horribly!";
			}
			else if (weapon_range >= 60)
			{
				cout << "You were so off from your target that it's not even worth explaining...";
			}
		}
	}

	else
	{
		cout << "You miss the " << E_name << "\n\n";
	}
}

void Dice::Player_Damage_roll(string weapon, Enemy enemy, Stats Player)
{
	get_Armor_Properties(armor1, Player);
	get_Weapon_Properties(weapon);
	get_Weapon_Stat_Bonus(weapon);
	Player.get_stat_bonus(Stat);
	if (weapon_dmg == "1d8")
	{
		if (crit == true)
		{
			cout << "Rolling your Critical Damage!!!\n";
			roll(2, 8);
			cout << dice_roll << " + " << stat_bonus << " (Stat Bonus) = ";
			dice_roll = dice_roll + stat_bonus;
			cout << dice_roll << "\n";
			cout << "You deal " << dice_roll << " points of damage to the " << E_name << "\n\n";
			E_HP = E_HP - dice_roll;
		}
		else {
			cout << "Rolling your damage! \n\n";
			roll(1, 8);
			cout << dice_roll << " + " << stat_bonus << " (Stat Bonus) = ";
			dice_roll = dice_roll + stat_bonus;
			cout << dice_roll << "\n";
			cout << "You deal " << dice_roll << " points of damage to the " << E_name << "\n\n";
			E_HP = E_HP - dice_roll;
		}
		if (E_HP <= 0)
		{
			cout << E_name << " HP  = 0 \n";
		}

		else
			cout << E_name << " HP  = " << E_HP << "\n\n";
	}

}

void Dice::Enemy_Attack_roll(Enemy enemy, string Enemy_weapon)
{
	cout << "The " << E_name << " goes to attack you.\n";
	roll(1, 20);
	dice_roll = dice_roll + E_weapon_hit_bonus;
	if (dice_roll > AC)
	{
		Enemy_Damage_roll(Enemy_weapon);
	}
	// crit success and fail
	else if (dice_roll == 20)
	{
		cout << "Critical Hit!\n";
	}
	else if (dice_roll == 1)
	{
		cout << "Critical Fail!\n";
	}

	else if (dice_roll <= AC)
	{
		cout << "The " << E_name << " misses. \n\n";
	}
}


void Dice::Enemy_Damage_roll(string E_weapon)
{
	get_Enemy_Weapon_Properties(E_weapon);
	if (E_weapon_dmg == "2d4")
	{
		roll(2, 4);
		dice_roll = dice_roll + E_weapon_dmg_bonus;
		cout << "The " << E_name << " hits you with a " << E_weapon << " for " << dice_roll << " damage\n\n";
		HP = HP - dice_roll;
		if (HP <= 0)
		{
			cout << "Your HP = 0\n\n";
		}
		else
			cout << "Your HP = " << HP << "\n\n";
	}
}



void Dice::get_Weapon_Properties(string weapon_name)
{
	if (weapon_name == "Longbow")
	{
		weapon_dmg = "1d8";
		weapon_type = "piercing";
		weapon_stat_bonus = "Dexterity";
		weapon_catagory = "Martial";
		weapon_range = 60;
		weapon_function = "Ranged";
	}
	else if (weapon_name == "Rapier")
	{
		weapon_dmg = "1d8";
		weapon_type = "piercing";
		weapon_stat_bonus = "Finesse";
		weapon_catagory = "Martial";
		weapon_function = "Meele";
	}
	else if (weapon_name == "Longsword")
	{
		weapon_dmg = "1d8";
		weapon_type = "slashing";
		weapon_stat_bonus = "Strength";
		weapon_catagory = "Martial"; // verstile option? (two handed for 1d10 dmg)
		weapon_function = "Meele";
	}
	else if (weapon_name == "Flail")
	{
		weapon_dmg = "1d8";
		weapon_type = "blugeoning";
		weapon_stat_bonus = "Strength";
		weapon_catagory = "Martial";
		weapon_function = "Meele";
	}

}

void Dice::get_Enemy_Weapon_Properties(string Enemey_weapon_name)
{

	//wolf
	if (Enemey_weapon_name == "Bite")
	{
		E_weapon_dmg = "2d4";
		E_weapon_type = "slashing";
		E_weapon_hit_bonus = 4;
		E_weapon_dmg_bonus = 2;
		E_weapon_range = 5;
		E_weapon_function = "Meele";

	}
}

// for the player character
void Dice::get_Weapon_Stat_Bonus(string weapon)
{
	if (weapon_stat_bonus == "Strength")
	{
		Stat = Str;
	}
	else if (weapon_stat_bonus == "Dexterity")
	{
		Stat = Dex;
	}
	else if (weapon_stat_bonus == "Finesse")
	{
		if (Str > Dex)
		{
			Stat = Str;
		}

		if (Str < Dex)
		{
			Stat = Dex;
		}

		if (Str == Dex)
		{
			Stat = Dex;
		}
	}
}

void Dice::get_Armor_Properties(string armor, Stats player)
{
	if (armor == "Leather Armor")
	{
		AC = 11 + player.get_stat_bonus(Dex);
	}

	else if (armor == "Chain Mail")
	{
		AC = 16;
	}
}

void Dice::get_Weapon_Proficiency_And_Print_Dice(string weapon)
{
	if (weapon_catagory == "Simple")
	{
		if (Proficiency_Simple_Weapons == true)
		{
			if (prof_bonus > 0)
			{
				cout << dice_roll << " + " << prof_bonus << " (Simple Weapon Proficiency Bonus) = " << dice_roll + prof_bonus << "\n";

			}
		}
	}

	else if (weapon_catagory == "Martial")
		if (Proficiency_Martial_Weapons == true)
		{
			if (prof_bonus > 0)
			{
				cout << dice_roll << " + " << prof_bonus << " (Martial Weapon Proficiency Bonus) = " << dice_roll + prof_bonus << "\n";
			}


		}

		else if (Proficiency_Simple_Weapons == false && Proficiency_Martial_Weapons == false)
		{

		}
}

void Dice::set_Player_Initiative(Stats player, int dext)
{
	player.get_stat_bonus(dext);
	roll(1, 20);
	player_dice_roll = dice_roll;
	cout << "Rolling Player's Initiative...\n" << player_dice_roll << " + " << stat_bonus << " = " << player_dice_roll + stat_bonus << "\n\n";
	P_initiative = player_dice_roll + stat_bonus;
}

void Dice::set_Enemy_Initiative(Enemy enemy, int Dex, string enemy_name)
{
	enemy.get_stat_bonus(Dex);
	roll(1, 20);
	enemy_dice_roll = dice_roll;
	cout << "Rolling " << enemy_name << "'s Initiative...\n" << enemy_dice_roll << " + " << E_stat_bonus << " = " << enemy_dice_roll + E_stat_bonus << "\n\n";
	E_initiative = enemy_dice_roll + E_stat_bonus;
}