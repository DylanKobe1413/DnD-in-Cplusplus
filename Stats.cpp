#include "Stats.h"
// add a weight system?
// setters
void Stats::set_stat_bonus(int statbonus)
{
	stat_bonus = statbonus;
}
//getters
int Stats::get_Srength()
{
	return Str;
}

int Stats::get_Dexterity()
{
	return Dex;
}

int Stats::get_Constitution()
{
	return Con;
}

int Stats::get_Intelligence()
{
	return Int;
}

int Stats::get_Wisdom()
{
	return Wis;
}

int Stats::get_Charisma()
{
	return Cha;
}

// set up the stats!
void Stats::set_Stats()

{
	cout << "Allocate your stats! 27 points to spend. 15 is the max for each stat \n (to reach 14 would require an extra point. \n to go above to 15 it'll cost 1 extra point) \n\n";
	cout << "Strength \n ";
	cin >> input;
	check(input);
	Str = input + Str;

	total = total - input;
	Limit(Str);
	print_out_stat(Str);
	cout << total << " points left to spend!\n\n";

	cout << "Dexterity \n";
	cin >> input;
	Dex = input + Dex;
	check(Dex);
	total = total - input;
	Limit(Dex);
	print_out_stat(Dex);
	cout << total << " points left to spend!\n\n";


	cout << "Constitution \n ";
	cin >> input;
	Con = input + Con;
	check(Con);
	total = total - input;
	Limit(Con);
	print_out_stat(Con);
	cout << total << " points left to spend!\n\n";


	cout << "Intelligence \n ";
	cin >> input;
	Int = input + Int;
	check(Int);
	total = total - input;
	Limit(Int);
	print_out_stat(Int);
	cout << total << " points left to spend!\n\n";

	cout << "Wisdom \n ";
	cin >> input;
	Wis = input + Wis;
	check(Wis);
	total = total - input;
	Limit(Wis);
	print_out_stat(Wis);
	cout << total << " points left to spend!\n\n";

	cout << "Charisma \n";
	cin >> input;
	Cha = input + Cha;
	check(Cha);
	total = total - input;
	Limit(Cha);
	print_out_stat(Cha);
	cout << total << " points left to spend!\n\n";

	totalCheck();

	AC = 10 + get_stat_bonus(Dex);
	if (stat_bonus == 1)
	{
		speed = speed + 5;
	}
	else if (stat_bonus == 2)
	{
		speed = speed + 10;
	}

	name = "Player";
}
// set up the class!
void Stats::set_Class()
{
	cout << "Select Your Class:\n";
	cout << "1. Fighter		\n";
	cout << "2. Ranger		\n";
	cout << "3. Wizard		\n\n";

	cin >> input;
	cout << "\n";
	switch (input)
	{
	case 1:
		Class = "Fighter \n";
		cout << "Jack of all trades, could choose to be a master in one of them though. One thing is for sure, they are good at fighting!\n\n";
		hitdice = "1d10";
		HP = 10 + get_stat_bonus(Con);
		Proficiency_Martial_Weapons = true;
		Proficiency_Simple_Weapons = true;
		prof_bonus = 2;
		// explain second wind
		cout << "You gain: a Fighting Style and Second wind!\n\n";
		Starting_Fighter();

	}
}

void Stats:: Starting_Fighter()
{
	cout << "Choose your Fighting Style:\n";
	cout << "1. Archery (+2 bonus to attack rolls made with range weapons.)\n";
	cout << "2. Defense (While wearing armor, you gain +1 bonus to AC.)\n";
	cout << "3. Dueling (+2 bonus to damage rolls while wielding a melee weapon in one hand)\n";
	cout << "4. Great Weapon Fighting (Reroll a 1,or 2 on damage dice for attacks with two handed or versatile weapons. Can only reroll once!)\n";
	cout << "5. Two Weapon Fighting (Add your ability modifier to the damage of the second attack.\n\n";
	cin >> input;
	cout << "\n";
	switch (input)
	{
	case 1:
		FightingStyle = "Archery";
		cout << FightingStyle << " is your fighting style!\n\n";
		weapon1 = "Longbow";/*(1d8 piercing*/ item1 = "20 Arrows";  ammo = 20; armor1 = "Leather Armor";
		weapon2 = "Rapier";/*(1d8 piercing*/
		armor1 = "Leather Armor";
		ammo = 20;
		cout << "You gain: a " << weapon1 << " " << item1 << " " << armor1 << " and a " << weapon2 << "\n\n";
		break;
	case 2:
		FightingStyle = "Defense";
		cout << FightingStyle << " is your fighting style!\n\n";
		weapon1 = "Longsword"; /* 1d8 slashing*/ shield = "Shield";
		weapon2 = "Flail"; /* 1d8 bludegoning*/ armor1 = "Chain Mail"; //16 AC needs 13 strength to wear
		cout << "You gain: a " << weapon1 << " " << armor1 << " and a " << weapon2 << "\n\n";
		break;
	case 3:
		FightingStyle = "Dueling";
		cout << FightingStyle << " is your fighting style!\n";
		break;

	case 4: FightingStyle = "Great Weapon Fighting";
		cout << FightingStyle << " is your fighting style!\n";
		break;

	case 5: FightingStyle = "Two Weapon Fighting";
		cout << FightingStyle << " is your fighting style!\n";
	}
}

int Stats::get_stat_bonus(int stat)
{
	if (stat == 12 || stat == 13)
		stat_bonus = 1;
	else if (stat == 14 || stat == 15)
	{
		stat_bonus = 2;
	}
	else if (stat == 8 || stat == 9)
	{
		stat_bonus = 1;
	}
	else
	{
		stat_bonus = 0;
	}
	return stat_bonus;
}

// Checks to see if allocated points = 0.
void Stats::totalCheck()
{
	if (total != 0)
	{
		cout << " Invalid Stat Configuration...Start Over \n";
		cin.clear();
		total = 27;
		Str = 10, Dex = 10, Con = 10, Int = 10, Wis = 10, Cha = 10;
		set_Stats();
	}
}

// Check's User Input when creating stats. Need to add a check for Chars and Strings.
void Stats::check(int response)
{
	while (response < -2)

	{
		cout << "Invalid Input \n";
		cin.clear();
		cin >> response;
	}
}

// print out the list of stats
void Stats::print_Stats()
{
	cout << "Your Stats: \n";
	cout << "Strength: " << Str << "\nAgility: " << Dex << "\nConstitution: " << Con << "\nIntelligence: " << Int << "\nWisdom: " << Wis << "\nCharisma: " << Cha << "\n\n";
}

// Limits stats to 15 and increases point allocation by 2 points past 14 and returns a point for every negative and the lowest is 8. 
void Stats::Limit(int stat)
{
	switch (stat)
	{
	case 14:
		total = total - 1;
		break;
	case 15:
		total = total - 2;
		break;
	case 8:
		total = total + 1;
	}
}

// print out a specific stat
void Stats:: print_out_stat(int stat)
{
	cout << stat << "\n";
}


//constructor for enemy
//string wolf = "Wolf";
	//int Wolf_Str = 12, Wolf_Dex = 15, Wolf_Con = 12, Wolf_Int = 3, Wolf_Wis = 12, Wolf_Cha = 6;
	//int Wolf_AC = 14;
	//int Wolf_speed = 40;
	//int Wolf_HP = 13;
	//int Wolf_initiative = 0;

//default constructor (i believe it's requiring one but i'll see if i can remove this without getting an error for some reason.
Stats::Stats()
{

}

Stats::Stats (string Enemy_name)
{
	if (Enemy_name == "Wolf")
	{
		name = "Wolf";
		HP = 13;
		AC = 14;
		Str = 12, Dex = 15, Con = 12, Int = 3, Wis = 12, Cha = 6;
		speed = 40;
		weapon1 = "Bite";
		weapon_range = 5;
		Proficiency_Simple_Weapons = true;
		prof_bonus = 2;
	}
}
