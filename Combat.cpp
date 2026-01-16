#include "Combat.h"

void Combat::set_distance(int Distance)
{
	distance = Distance;
}

int Combat::get_distance()
{
	return distance;
}
// compiler is reading this from right to left so i put player to the right in the parameter so it can be read and outputted first.
void Combat::Initiative_compare(int enemy, int player)
{
	if (player > enemy)
	{
		cout << player << " > " << enemy << "\n\n";
		compare = true;
		Player_turn();
	}

	else if (player == enemy)
	{
		cout << player << " = " << enemy << " Lets go in the player's favor!\n\n";
		compare = true;
		Player_turn();
	}
	else if (player < enemy)
	{
		cout << enemy << " > " << player << "\n\n";
		compare = false;
		Enemy_turn();
	}


}

void Combat::check_distance(Stats &Character)
{
	if (Character.weapon_function == "Ranged" && get_distance() > Character.weapon_range)
	{
		P_attack1 = 0;
	}
	 if (Character.weapon_function == "Ranged" && get_distance() <= 5)
	{
		// make sure this works in combat AND stat rolls
		 disadvantage = true;
	}
}



void Combat::StartCombat(Stats &player_character, Stats &Enemy, Dice dice)
{
	combat = true;
	
	if (compare == true)
	{
		cout << "You go first! \n\n";

		while (player_character.HP > 0 && Enemy.HP > 0)
		{
			check_distance(player_character);
			Player_Select(player_character, Enemy, dice);
			if (Enemy.HP <= 0)
			{
				cout << "You deafeat the " << Enemy.name << "\n\n";
				break;
			}
			Enemy_turn();
			setEnemyBehavior(Enemy, dice, player_character);
			if (player_character.HP <= 0)
			{
				cout << "You Die... :( \n\n";
				break;
			}

			
		}
	}
	else if (compare == false)
	{
		cout << "You go second...\n\n";

		while (player_character.HP > 0 && Enemy.HP > 0)
		{
			setEnemyBehavior(Enemy, dice, player_character);
			if (player_character.HP <= 0)
			{
				cout << "You Die... :( \n\n";
				break;
			}

			Player_turn();
			check_distance(player_character);
			Player_Select(player_character, Enemy, dice);

			if (Enemy.HP <= 0)
			{
				cout << "You deafeat the " << Enemy.name << "\n\n";
				break;
			}
		}

	}

}

void Combat::setEnemyBehavior(Stats &Enemy, Dice dice, Stats &Player)
{
	if (Enemy.name == "Wolf")
	{
		
		if (Player.HP > 0 && Enemy.HP > 0)
		{
			if (compare == false || E_turn == true)
			{
				if (get_distance() > Enemy.weapon_range)
				{
					dice.roll(1, 1);
					if (dice.get_dice_roll() == 1)
					{
						cout << "The Wolf rushes towards you...\n";
						set_distance(get_distance() - Enemy.speed);
						Check_Distance();
						cout << "Distance between you and the wolf is now " << get_distance() << "\n\n";
						if (get_distance() <= Enemy.weapon_range)
						{
							dice.roll(1, 1);
							// attempts an attack with bite
							if (dice.get_dice_roll() == 1)
							{
							cout << "The Wolf is in range to attack you.\n\n";
							dice.Attack_roll(Enemy, Player, Enemy.weapon1);
							}
							
								
						}
						else 
						{
							cout << "The Wolf Cannot reach you so its turn ends.\n\n";
						}
					}
					
				}
				else if (get_distance() <= Enemy.weapon_range)
				{
					dice.roll(1, 1);
					if (dice.get_dice_roll() == 1)
					{
						cout << "The Wolf is in range to attack you.\n\n";
						dice.Attack_roll(Enemy, Player, Enemy.weapon1);
					}
				}
			}
		}
	}
}

void Combat::Set_Player_Combat_Options(bool attack1, bool attack2, bool move1, bool move2)
{
	P_attack1 = attack1;
	P_attack2 = attack2;
	P_move1 = move1;
	P_move2 = move2;
}
// make a switch statement that is based on set_player_combat_options or you can use an array to simplify this giant if else if 
void Combat::PrintPlayerCombatOptions(Stats& player)
{
	if (P_attack1 == true)
	{
	cout << "1.Attack with " << player.weapon1 << "\n";
	}
	
	if (P_attack2 == true)
	{
	cout << "2.Attack with " << player.weapon2 << "\n";
	}

	if (P_move1 == true)
	{
	cout << "3.Move Forward\n";
	}

	if (P_move2 == true)
	{
		cout << "4.Move Backward\n";
	}
}

void Combat::Player_Select(Stats &Player, Stats &Enemy, Dice dice)
{
	// in case the player is stunned or cannot act 
	PrintPlayerCombatOptions(Player);
	if (P_attack1 == false && P_attack2 == false && P_move1 == false && P_move2 == false)
	{
		cout << Player.name << " cannot move so their turn ends.\n\n";
	}
	// player can select options and can move first then attack. make sure to add movement after attacking as well 
	else 
	{
		cin >> input;
		cout << "\n";
		switch (input)
		{
		case 1:
			dice.Attack_roll(Player, Enemy, Player.weapon1);
			break;

		case 2:
			dice.Attack_roll(Player, Enemy, Player.weapon2);
			break;

		case 3:
			Player_turn();
			set_distance(get_distance() - Player.speed);
			Check_Distance();
			cout << "You move " << Player.speed << " feet closer to the " << Enemy.name << "\n";
			cout << "You are now " << get_distance() << " feet away from the " << Enemy.name << "\n\n";
			P_move1 = 0, P_move2 = 0;
			PrintPlayerCombatOptions(Player);

			cin >> input;
			cout << "\n";

			switch (input)
			{
			case 1:
				dice.Attack_roll(Player, Enemy, Player.weapon1);
				break;

			case 2:
				dice.Attack_roll(Player, Enemy, Player.weapon2);
				break;
			}
			P_move1 = 1, P_move2 = 1;
			break;

		case 4:
			Player_turn();
			set_distance(get_distance() + Player.speed);
			Check_Distance();
			cout << "You move " << Player.speed << " feet away from the " << Enemy.name << "\n";
			cout << "You are now " << get_distance() << " feet away from the " << Enemy.name << "\n\n";
			P_move1 = 0, P_move2 = 0;
			PrintPlayerCombatOptions(Player);
			cin >> input;
			cout << "\n";

			switch (input)
			{
			case 1:
				dice.Attack_roll(Player, Enemy, Player.weapon1);
				break;

			case 2:
				dice.Attack_roll(Player, Enemy, Player.weapon2);
			}
			P_move1 = 1, P_move2 = 1;
			break;
		}
	}
}

void Combat::Enemy_turn()
{
	E_turn = true;
	if (E_turn == true)
	{
		P_turn = false;
	}

}
void Combat::Player_turn()
{
	P_turn = true;
	if (P_turn == true)
	{
		E_turn = false;

	}
}

void Combat::Check_Distance()
{
	if (get_distance() <= 0)
	{
		set_distance(5);
	}


}
