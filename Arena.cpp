#include "stdafx.h"
#include "Arena.h"


Arena::Arena(Player pone, Player ptwo)
{
	p1 = pone;
	p2 = ptwo;
	turn = 0;
}

Arena::~Arena()
{
}

void Arena::takeTurn()
{
	turn++;
	p1.advTurn();
	p2.advTurn();

	//Do attacks
	if (p1.stunned()) p1.unstun();
	else if (p1.armorColor() == "Blue" && rand() % 100 < 15)
	{
		p1.attack(p2);
		p1.attack(p2);
	}
	else p1.attack(p2);

	if (p2.stunned()) p2.unstun();
	else if (p2.armorColor() == "Blue" && rand() % 100 < 15)
	{
		p2.attack(p1);
		p2.attack(p1);
	}
	else p2.attack(p1);

	//did yellow shields trigger
	if (p1.shieldColor() == "Yellow" && rand() % 2 == 0) p1.cureAll();
	if (p2.shieldColor() == "Yellow" && rand() % 2 == 0) p2.cureAll();

	//heal red armors
	if (p1.armorColor() == "Red") p1.hurt(-20);
	if (p2.armorColor() == "Red") p2.hurt(-20);

	//deal DoT
	if (p1.poisoned()) p1.hurt(20);
	if (p2.poisoned()) p2.hurt(20);
	if (p1.bleeding()) p1.hurt(20);
	if (p2.bleeding()) p2.hurt(20);

	//adjust yellow armor bonus
	if (p1.armorColor() == "Yellow") p1.adjMult();
	if (p2.armorColor() == "Yellow") p2.adjMult();
}

Player Arena::simulate()
{
	while (p1.currentHealth() > 0 && p2.currentHealth() > 0) {
		takeTurn();
	}
	if (p1.currentHealth() > 0 && p2.currentHealth() <= 0)
	{
		return p1;
	}
	else if (p2.currentHealth() > 0 && p1.currentHealth() <= 0)
	{
		return p2;
	}
	else return Player(4, 4, 4);
}
