// ShieldWeaponArmor.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Player.h"
#include "Arena.h"
#include <cstdlib>
#include <ctime>


int main()
{
	srand(time(0));
	const int REPS = 1000000;
	int timesRan = 0;
	Player winner;

	int weaponWinners[4] = {};
	int shieldWinners[4] = {};
	int armorWinners[4] = {};

	while (timesRan < REPS)	
	{
		Player p1(rand() % 4, rand() % 4, rand() % 4);
		Player p2(rand() % 4, rand() % 4, rand() % 4);
		Arena arena(p1, p2);
		winner = arena.simulate();
		//shields
		if (winner.shieldColor() == "Red") ++shieldWinners[0];
		if (winner.shieldColor() == "Blue") ++shieldWinners[1];
		if (winner.shieldColor() == "Yellow") ++shieldWinners[2];
		if (winner.shieldColor() == "Green") ++shieldWinners[3];

		//weapons
		if (winner.weaponColor() == "Red") ++weaponWinners[0];
		if (winner.weaponColor() == "Blue") ++weaponWinners[1];
		if (winner.weaponColor() == "Yellow") ++weaponWinners[2];
		if (winner.weaponColor() == "Green") ++weaponWinners[3];

		//armor
		if (winner.armorColor() == "Red") ++armorWinners[0];
		if (winner.armorColor() == "Blue") ++armorWinners[1];
		if (winner.armorColor() == "Yellow") ++armorWinners[2];
		if (winner.armorColor() == "Green") ++armorWinners[3];
		timesRan++;
	}

	cout << "End stats after " << REPS << " simulated battles: " << endl;
	cout << "Shields: " << endl;
	cout << "        Red: " << shieldWinners[0] << " victories" << endl;
	cout << "       Blue: " << shieldWinners[1] << " victories" << endl;
	cout << "     Yellow: " << shieldWinners[2] << " victories" << endl;
	cout << "      Green: " << shieldWinners[3] << " victories" << endl << endl;

	cout << "Weapons: " << endl;
	cout << "        Red: " << weaponWinners[0] << " victories" << endl;
	cout << "       Blue: " << weaponWinners[1] << " victories" << endl;
	cout << "     Yellow: " << weaponWinners[2] << " victories" << endl;
	cout << "      Green: " << weaponWinners[3] << " victories" << endl << endl;

	cout << "Armor: " << endl;
	cout << "        Red: " << armorWinners[0] << " victories" << endl;
	cout << "       Blue: " << armorWinners[1] << " victories" << endl;
	cout << "     Yellow: " << armorWinners[2] << " victories" << endl;
	cout << "      Green: " << armorWinners[3] << " victories" << endl << endl;

	cout << "Press enter to quit. ";
	cin.get();
    return 0;
}

