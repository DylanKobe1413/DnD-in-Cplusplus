#include "Combat.h"

void Combat::set_distance(int Distance)
{
	distance = Distance;
}

int Combat::get_distance()
{
	return distance;
}

void Combat::Initiative_compare(int player, int enemy)
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

void Combat::check_player_distance(Stats character)
{
	if (character.weapon_function == "Ranged" && get_distance() > character.weapon_range)
	{
		P_attack1 = 0;
	}
	 if (character.weapon_function == "Ranged" && get_distance() <= 5)
	{
		// make sure this works in combat AND stat rolls
		 disadvantage = true;
	}
}



void Combat::StartCombat(Stats player_character, Enemy enemy, Dice dice)
{
	combat = true;
	
	if (compare == true)
	{
		cout << "You go first! \n\n";

		while (player_character.HP > 0 && E_HP > 0)
		{
			check_player_distance(player_character);
			Player_Select(player_character, enemy, dice);
			if (E_HP <= 0)
			{
				cout << "You deafeat the " << E_name << "\n\n";
				break;
			}
			Enemy_turn();
			setEnemyBehavior(enemy, dice, player_character);
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

		while (player_character.HP > 0 && E_HP > 0)
		{
			setEnemyBehavior(enemy, dice, player_character);
			if (player_character.HP <= 0)
			{
				cout << "You Die... :( \n\n";
				break;
			}

			Player_turn();
			check_player_distance(player_character);
			Player_Select(player_character, enemy, dice);

			if (E_HP <= 0)
			{
				cout << "You deafeat the " << E_name << "\n\n";
				break;
			}
		}

	}

}

void Combat::setEnemyBehavior(Enemy enemy, Dice dice, Stats player_character)
{
	if (E_name == "Wolf")
	{
		//bite
		E_attack1 = E_weapon;
		if (player_character.HP > 0 && E_HP > 0)
		{
			if (compare == false || E_turn == true)
			{
				if (get_distance() > E_weapon_range)
				{
					dice.roll(1, 1);
					if (dice.get_dice_roll() == 1)
					{
						cout << "The Wolf rushes towards you...\n";
						set_distance(get_distance() - E_speed);
						Check_Distance();
						cout << "Distance between you and the wolf is now " << get_distance() << "\n\n";
						if (get_distance() <= E_weapon_range)
						{
							dice.roll(1, 1);
							// attempts an attack with bite
							if (dice.get_dice_roll() == 1)
							{
							dice.Enemy_Attack_roll(enemy, E_weapon, player_character);
							}

								
						}
					}
					
				}
				else if (get_distance() <= E_weapon_range)
				{
					dice.roll(1, 1);
					if (dice.get_dice_roll() == 1)
					{
						cout << "The Wolf is in range to attack you.\n";
						dice.Enemy_Attack_roll(enemy, E_weapon, player_character);
					}
				}
			}
		}
	}
}

void Combat::Set_Player_Combat_Options(int attack1, int attack2, int move1, int move2)
{
	P_attack1 = attack1;
	P_attack2 = attack2;
	P_move1 = move1;
	P_move2 = move2;
}

void Combat::PrintPlayerCombatOptions(Stats player)
{	// 1111
	if (P_attack1 == 1 && P_attack2 == 1 && P_move1 == 1 && P_move2 == 1)
	{
		cout << "1. Attack with " << player.weapon1 << "\n";
		cout << "2. Attack with " << player.weapon2 << "\n";
		cout << "3. Move Forward	\n";
		cout << "4. Move Backward	\n\n";
	}
	// 0111
	else if (P_attack1 == 0 && P_attack2 == 1 && P_move1 == 1 && P_move2 == 1)
	{

		cout << "1. Attack with " << player.weapon2 << "\n";
		cout << "2. Move Forward	\n";
		cout << "3. Move Backward	\n\n";
	}
	// 0011
	else if (P_attack1 == 0 && P_attack2 == 0 && P_move1 == 1 && P_move2 == 1)
	{
		cout << "1. Move Forward	\n";
		cout << "2.Move Backward	\n\n";
	}
	// 0001
	else if (P_attack1 == 0 && P_attack2 == 0 && P_move1 == 0 && P_move2 == 1)
	{
		cout << "1.Move Backward	\n\n";
	}
	// 1011
	else if (P_attack1 == 1 && P_attack2 == 0 && P_move1 == 1 && P_move2 == 1)
	{
		cout << "1. Attack with " << player.weapon1 << "\n";
		cout << "2. Move Forward	\n";
		cout << "3. Move Backward	\n\n";
	}
	// 1001
	else if (P_attack1 == 1 && P_attack2 == 0 && P_move1 == 0 && P_move2 == 0)
	{
		cout << "1. Attack with " << player.weapon1 << "\n";
		cout << "2. Move Backward	\n\n";
	}
	// 1010
	else if (P_attack1 == 1 && P_attack2 == 0 && P_move1 == 1 && P_move2 == 0)
	{
		cout << "1. Attack with " << player.weapon1 << "\n";
		cout << "2. Move Forward	\n\n";
	}
	// 1000
	else if (P_attack1 == 1 && P_attack2 == 0 && P_move1 == 0 && P_move2 == 0)
	{
		cout << "1. Attack with " << player.weapon1 << "\n\n";
	}
	//	0010
	else if (P_attack1 == 0 && P_attack2 == 0 && P_move1 == 1 && P_move2 == 0)
	{
		cout << "1. Move Forward	\n\n";
	}
	//	0100
	else if (P_attack1 == 0 && P_attack2 == 1 && P_move1 == 0 && P_move2 == 0)
	{
		cout << "1. Attack with " << player.weapon2 << "\n\n";
	}
	//	0110
	else if (P_attack1 == 0 && P_attack2 == 1 && P_move1 == 1 && P_move2 == 0)
	{
		cout << "1. Attack with " << player.weapon2 << "\n";
		cout << "2. Move Forward \n\n";
	}
	//	0101
	else if (P_attack1 == 0 && P_attack2 == 1 && P_move1 == 0 && P_move2 == 1)
	{
		cout << "1. Attack with " << player.weapon2 << "\n";
		cout << "2. Move Backward \n\n";
	}
	//	1110

	else if (P_attack1 == 1 && P_attack2 == 1 && P_move1 == 1 && P_move2 == 0)
	{
		cout << "1. Attack with " << player.weapon1 << "\n";
		cout << "2. Attack with " << player.weapon2 << "\n";
		cout << "3. Move Forward \n\n";
	}
	// 1100
	else if (P_attack1 == 1 && P_attack2 == 1 && P_move1 == 0 && P_move2 == 0)
	{
		cout << "1. Attack with " << player.weapon1 << "\n";
		cout << "2. Attack with " << player.weapon2 << "\n";

	}
}

void Combat::Player_Select(Stats player, Enemy enemy, Dice dice)
{
	PrintPlayerCombatOptions(player);
	cin >> input;
	cout << "\n";
	switch (input)
	{
	case 1:
		dice.Player_Attack_roll(player, enemy, player.weapon1);
		break;

	case 2:
		dice.Player_Attack_roll(player, enemy, player.weapon2);
		break;

	case 3:
		Player_turn();
		set_distance(get_distance() - player.speed);
		Check_Distance();
		cout << "You move " << player.speed << " feet closer to the " << E_name << "\n";
		cout << "You are now " << get_distance() << " feet away from the " << E_name << "\n\n";
		P_move1 = 0, P_move2 = 0;
		PrintPlayerCombatOptions(player);

		cin >> input;
		cout << "\n";

		switch (input)
		{
		case 1:
			dice.Player_Attack_roll(player, enemy, player.weapon1);
			break;

		case 2:
			dice.Player_Attack_roll(player, enemy, player.weapon2);
			break;
		}
		P_move1 = 1, P_move2 = 1;
		break;

	case 4:
		Player_turn();
		set_distance(get_distance() + player.speed);
		Check_Distance();
		cout << "You move " << player.speed << " feet away from the " << E_name << "\n";
		cout << "You are now " << get_distance() << " feet away from the " << E_name << "\n\n";
		P_move1 = 0, P_move2 = 0;
		PrintPlayerCombatOptions(player);
		cin >> input;
		cout << "\n";

		switch (input)
		{
		case 1:
			dice.Player_Attack_roll(player, enemy, player.weapon1);
			break;

		case 2:
			dice.Player_Attack_roll(player, enemy, player.weapon2);
		}
		P_move1 = 1, P_move2 = 1;
		break;
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
