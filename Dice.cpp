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


void Dice::Stat_roll(Stats &Character, int stat, int num_of_dice, int sides)
{
	Character.get_stat_bonus(stat);
	roll(num_of_dice, sides);
	if (Character.get_stat_bonus(stat) == 0)
	{
		cout << "Rolling a " << num_of_dice << "d" << sides << "\n";
		cout << dice_roll << "...\n\n";
	}
	else
	{
		cout << "Rolling a " << num_of_dice << "d" << sides << " + " << Character.get_stat_bonus(stat) << "\n";
		cout << "Roll result was " << dice_roll << "\n";
		cout << dice_roll << " + " << Character.get_stat_bonus(stat) << " = " << dice_roll + Character.get_stat_bonus(stat) << "...\n\n";
		dice_roll = dice_roll + Character.get_stat_bonus(stat);
	}
}

void Dice::Attack_roll(Stats &Character, Stats &Target, string weapon)
{
	get_Weapon_Properties(weapon, Character);
	get_Weapon_Stat_Bonus(weapon, Character);
	Stat_roll(Character, Stat, 1, 20);
	get_Weapon_Proficiency_And_Print_Dice(weapon, Character);


	if (dice_roll >= Target.AC)
	{
		Damage_roll(weapon, Character, Target);

	}
	// crit success and fail
	else if (dice_roll == 20)
	{
		crit = true;
		cout << "Critical strike on the " << Target.name << " !\n";
	}
	else if (dice_roll == 1)
	{
		crit_fail = true;
		cout << "Critical Failure!!!!\n";
		// make a function that can output dialogue for each type.
		if (Target.name == "Wolf")
		{
			if (Character.weapon_range >= 0 && Character.weapon_range <= 10)
			{
				cout << "You Miss the wolf horribly!";
			}
			else if (Character.weapon_range >= 60)
			{
				cout << "You were so off from your target that it's not even worth explaining...";
			}
		}
	}

	else
	{
		cout << Character.name << " missed " << Target.name << "\n\n";
	}
}

void Dice::Damage_roll(string weapon, Stats &Character, Stats &Target)
{
	get_Armor_Properties(Character.armor1, Character);
	get_Weapon_Properties(weapon, Character);
	get_Weapon_Stat_Bonus(weapon, Character);
	Character.get_stat_bonus(Stat);
	if (Character.weapon_dmg == "1d8")
	{
		if (crit == true)
		{
			cout << "Rolling " <<Character.name << "'s Critical Damage!!!\n";
			roll(2, 8);
			cout << dice_roll << " + " << Character.get_stat_bonus(Stat) << " (Stat Bonus) = ";
			dice_roll = dice_roll + Character.get_stat_bonus(Stat);
			cout << dice_roll << "\n";
			cout << Character.name <<" deals " << dice_roll << " points of damage to the " << Target.name << "\n\n";
			Target.HP = Target.HP - dice_roll;
		}
		else {
			cout << "Rolling your damage! \n\n";
			roll(1, 8);
			cout << dice_roll << " + " << Character.get_stat_bonus(Stat) << " (Stat Bonus) = ";
			dice_roll = dice_roll + Character.get_stat_bonus(Stat);
			cout << dice_roll << "\n";
			cout << "You deal " << dice_roll << " points of damage to the " << Target.name << "\n\n";
			Target.HP = Target.HP - dice_roll;
		}
		if (Target.HP <= 0)
		{
			cout << Target.name << "'s HP  = 0 \n";
		}

		else
			cout << Target.name << "'s HP  = " << Target.HP << "\n\n";
	}

}
// Move function to Stats.   Make function for dice to retrieve info?
void Dice::get_Weapon_Properties(string weapon_name,Stats &Character)
{
	if (weapon_name == "Longbow")
	{
		Character.weapon_dmg = "1d8";
		Character.weapon_type = "piercing";
		Character.weapon_stat_bonus = "Dexterity";
		Character.weapon_catagory = "Martial";
		Character.weapon_range = 60;
		Character.weapon_function = "Ranged";
	}
	else if (weapon_name == "Rapier")
	{
		Character.weapon_dmg = "1d8";
		Character.weapon_type = "piercing";
		Character.weapon_stat_bonus = "Finesse";
		Character.weapon_range = 5;
		Character.weapon_catagory = "Martial";
		Character.weapon_function = "Meele";
	}
	else if (weapon_name == "Longsword")
	{
		Character.weapon_dmg = "1d8";
		Character.weapon_type = "slashing";
		Character.weapon_stat_bonus = "Strength";
		Character.weapon_range = 5;
		Character.weapon_catagory = "Martial"; // verstile option? (two handed for 1d10 dmg)
		Character.weapon_function = "Meele";
	}
	else if (weapon_name == "Flail")
	{
		Character.weapon_dmg = "1d8";
		Character.weapon_type = "blugeoning";
		Character.weapon_stat_bonus = "Strength";
		Character.weapon_range = 5;
		Character.weapon_catagory = "Martial";
		Character.weapon_function = "Meele";
	}
	else if (weapon_name == "Bite")
	{
		Character.weapon_dmg = "2d4";
		Character.weapon_type = "slashing";
		Character.weapon_stat_bonus = "Dexterity";
		Character.weapon_range = 5;
		Character.weapon_catagory = "Simple";
		Character.weapon_function = "Meele";

	}

}	
	//wolf
	//E_weapon_dmg = "2d4"; E_weapon_type = "slashing"; E_weapon_hit_bonus = 4; E_weapon_dmg_bonus = 2; E_weapon_range = 5; E_weapon_function = "Meele";

	


// for the player character
void Dice::get_Weapon_Stat_Bonus(string weapon, Stats &Character)
{
	if (Character.weapon_stat_bonus == "Strength")
	{
		Stat = Character.get_Srength();
	}
	else if (Character.weapon_stat_bonus == "Dexterity")
	{
		Stat = Character.get_Dexterity();
	}
	else if (Character.weapon_stat_bonus == "Finesse")
	{
		if (Character.get_Srength() > Character.get_Dexterity())
		{
			Stat = Character.get_Srength();
		}

		if (Character.get_Srength() < Character.get_Dexterity())
		{
			Stat = Character.get_Dexterity();
		}

		if (Character.get_Srength() == Character.get_Dexterity())
		{
			Stat = Character.get_Dexterity();
		}
	}
}

void Dice::get_Armor_Properties(string armor, Stats &Character)
{
	if (armor == "Leather Armor")
	{
		Character.AC = 11 + Character.get_stat_bonus(Character.get_Dexterity());
	}

	else if (armor == "Chain Mail")
	{
		Character.AC = 16;
	}
}

void Dice::get_Weapon_Proficiency_And_Print_Dice(string weapon, Stats &Character)
{
	if (Character.weapon_catagory == "Simple")
	{
		if (Character.Proficiency_Simple_Weapons == true)
		{
			if (Character.prof_bonus > 0)
			{
				cout << dice_roll << " + " << Character.prof_bonus << " (Simple Weapon Proficiency Bonus) = " << dice_roll + Character.prof_bonus << "\n";

			}
		}
	}

	else if (Character.weapon_catagory == "Martial")
		if (Character.Proficiency_Martial_Weapons == true)
		{
			if (Character.prof_bonus > 0)
			{
				cout << dice_roll << " + " << Character.prof_bonus << " (Martial Weapon Proficiency Bonus) = " << dice_roll + Character.prof_bonus << "\n";
			}


		}

		else if (Character.Proficiency_Simple_Weapons == false && Character.Proficiency_Martial_Weapons == false)
		{

		}
}

int Dice::set_Initiative(Stats &Character)
{
	Character.get_stat_bonus(Character.get_Dexterity());
	roll(1, 20);
	Character.Initiative = dice_roll;
	cout << "Rolling " << Character.name << "'s Initiative...\n" << Character.Initiative << " + " << Character.get_stat_bonus(Character.get_Dexterity()) << " = " << Character.Initiative + Character.get_stat_bonus(Character.get_Dexterity()) << "\n\n";
	Character.Initiative = Character.Initiative + Character.get_stat_bonus(Character.get_Dexterity());
	return Character.Initiative;
}
