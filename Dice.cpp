#include "Dice.h"

void Dice::set_dice_roll(int outcome)
{
	dice_roll = outcome;
}

int Dice::get_dice_roll()
{
	return dice_roll;
}

// check for crit/fail for all dice rolls set crit/fail to true when condition is met
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
	if (character.get_stat_bonus(stat) == 0)
	{
		cout << "Rolling a " << num_of_dice << "d" << sides << "\n";
		cout << dice_roll << "...\n\n";
	}
	else
	{
		cout << "Rolling a " << num_of_dice << "d" << sides << " + " << character.get_stat_bonus(stat) << "\n";
		cout << "Roll result was " << dice_roll << "\n";
		cout << dice_roll << " + " << character.get_stat_bonus(stat) << " = " << dice_roll + character.get_stat_bonus(stat) << "...\n\n";
		dice_roll = dice_roll + character.get_stat_bonus(stat);
	}
}

void Dice::Enemy_stat_roll(Enemy enemy, int stat, int num_of_dice, int sides)
{
	enemy.get_stat_bonus(stat);

	if (enemy.get_stat_bonus(stat) == 0)
	{
		cout << "Rolling a " << num_of_dice << "d" << sides << "\n";
	}
	else
	{
		cout << "Rolling a " << num_of_dice << "d" << sides << "+ " << enemy.get_stat_bonus(stat)<< "\n";
	}

	roll(num_of_dice, sides);
	cout << dice_roll + enemy.get_stat_bonus(stat) << "...\n\n";

}

void Dice::Player_Attack_roll(Stats character, Enemy enemy, string weapon)
{
	get_Weapon_Properties(weapon, character);
	get_Weapon_Stat_Bonus(weapon, character);
	stat_roll(character, Stat, 1, 20);
	get_Weapon_Proficiency_And_Print_Dice(weapon, character);


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
			if (character.weapon_range >= 0 && character.weapon_range <= 10)
			{
				cout << "You Miss the wolf horribly!";
			}
			else if (character.weapon_range >= 60)
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

void Dice::Player_Damage_roll(string weapon, Enemy enemy, Stats player_character)
{
	get_Armor_Properties(player_character.armor1, player_character);
	get_Weapon_Properties(weapon, player_character);
	get_Weapon_Stat_Bonus(weapon, player_character);
	player_character.get_stat_bonus(Stat);
	if (player_character.weapon_dmg == "1d8")
	{
		if (crit == true)
		{
			cout << "Rolling your Critical Damage!!!\n";
			roll(2, 8);
			cout << dice_roll << " + " << player_character.get_stat_bonus(Stat) << " (Stat Bonus) = ";
			dice_roll = dice_roll + player_character.get_stat_bonus(Stat);
			cout << dice_roll << "\n";
			cout << "You deal " << dice_roll << " points of damage to the " << E_name << "\n\n";
			E_HP = E_HP - dice_roll;
		}
		else {
			cout << "Rolling your damage! \n\n";
			roll(1, 8);
			cout << dice_roll << " + " << player_character.get_stat_bonus(Stat) << " (Stat Bonus) = ";
			dice_roll = dice_roll + player_character.get_stat_bonus(Stat);
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

void Dice::Enemy_Attack_roll(Enemy enemy, string Enemy_weapon, Stats player_character)
{
	cout << "The " << E_name << " goes to attack you.\n";
	roll(1, 20);
	dice_roll = dice_roll + E_weapon_hit_bonus;
	if (dice_roll > player_character.AC)
	{
		Enemy_Damage_roll(Enemy_weapon, player_character);
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

	else if (dice_roll <= player_character.AC)
	{
		cout << "The " << E_name << " misses. \n\n";
	}
}


void Dice::Enemy_Damage_roll(string E_weapon, Stats player_character)
{
	get_Enemy_Weapon_Properties(E_weapon);
	if (E_weapon_dmg == "2d4")
	{
		roll(2, 4);
		dice_roll = dice_roll + E_weapon_dmg_bonus;
		cout << "The " << E_name << " hits you with a " << E_weapon << " for " << dice_roll << " damage\n\n";
		player_character.HP = player_character.HP - dice_roll;
		if (player_character.HP <= 0)
		{
			cout << "Your HP = 0\n\n";
		}
		else
			cout << "Your HP = " << player_character.HP << "\n\n";
	}
}



void Dice::get_Weapon_Properties(string weapon_name,Stats player)
{
	if (weapon_name == "Longbow")
	{
		player.weapon_dmg = "1d8";
		player.weapon_type = "piercing";
		player.weapon_stat_bonus = "Dexterity";
		player.weapon_catagory = "Martial";
		player.weapon_range = 60;
		player.weapon_function = "Ranged";
	}
	else if (weapon_name == "Rapier")
	{
		player.weapon_dmg = "1d8";
		player.weapon_type = "piercing";
		player.weapon_stat_bonus = "Finesse";
		player.weapon_catagory = "Martial";
		player.weapon_function = "Meele";
	}
	else if (weapon_name == "Longsword")
	{
		player.weapon_dmg = "1d8";
		player.weapon_type = "slashing";
		player.weapon_stat_bonus = "Strength";
		player.weapon_catagory = "Martial"; // verstile option? (two handed for 1d10 dmg)
		player.weapon_function = "Meele";
	}
	else if (weapon_name == "Flail")
	{
		player.weapon_dmg = "1d8";
		player.weapon_type = "blugeoning";
		player.weapon_stat_bonus = "Strength";
		player.weapon_catagory = "Martial";
		player.weapon_function = "Meele";
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
void Dice::get_Weapon_Stat_Bonus(string weapon, Stats player_character)
{
	if (player_character.weapon_stat_bonus == "Strength")
	{
		Stat = player_character.get_Srength();
	}
	else if (player_character.weapon_stat_bonus == "Dexterity")
	{
		Stat = player_character.get_Dexterity();
	}
	else if (player_character.weapon_stat_bonus == "Finesse")
	{
		if (player_character.get_Srength() > player_character.get_Dexterity())
		{
			Stat = player_character.get_Srength();
		}

		if (player_character.get_Srength() < player_character.get_Dexterity())
		{
			Stat = player_character.get_Dexterity();
		}

		if (player_character.get_Srength() == player_character.get_Dexterity())
		{
			Stat = player_character.get_Dexterity();
		}
	}
}

void Dice::get_Armor_Properties(string armor, Stats player_character)
{
	if (armor == "Leather Armor")
	{
		player_character.AC = 11 + player_character.get_stat_bonus(player_character.get_Dexterity());
	}

	else if (armor == "Chain Mail")
	{
		player_character.AC = 16;
	}
}

void Dice::get_Weapon_Proficiency_And_Print_Dice(string weapon, Stats player)
{
	if (player.weapon_catagory == "Simple")
	{
		if (player.Proficiency_Simple_Weapons == true)
		{
			if (player.prof_bonus > 0)
			{
				cout << dice_roll << " + " << player.prof_bonus << " (Simple Weapon Proficiency Bonus) = " << dice_roll + player.prof_bonus << "\n";

			}
		}
	}

	else if (player.weapon_catagory == "Martial")
		if (player.Proficiency_Martial_Weapons == true)
		{
			if (player.prof_bonus > 0)
			{
				cout << dice_roll << " + " << player.prof_bonus << " (Martial Weapon Proficiency Bonus) = " << dice_roll + player.prof_bonus << "\n";
			}


		}

		else if (player.Proficiency_Simple_Weapons == false && player.Proficiency_Martial_Weapons == false)
		{

		}
}

int Dice::set_Player_Initiative(Stats player)
{
	player.get_stat_bonus(player.get_Dexterity());
	roll(1, 20);
	player_dice_roll = dice_roll;
	cout << "Rolling Player's Initiative...\n" << player_dice_roll << " + " << player.get_stat_bonus(player.get_Dexterity()) << " = " << player_dice_roll + player.get_stat_bonus(player.get_Dexterity()) << "\n\n";
	player.P_initiative = player_dice_roll + player.get_stat_bonus(player.get_Dexterity());
	return player.P_initiative;
}

int Dice::set_Enemy_Initiative(Enemy enemy, int Dex, string enemy_name)
{
	enemy.get_stat_bonus(Dex);
	roll(1, 20);
	enemy_dice_roll = dice_roll;
	cout << "Rolling " << enemy_name << "'s Initiative...\n" << enemy_dice_roll << " + " << E_stat_bonus << " = " << enemy_dice_roll + E_stat_bonus << "\n\n";
	E_initiative = enemy_dice_roll + E_stat_bonus;
	return E_initiative;
}