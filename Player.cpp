#include "stdafx.h"
#include "Player.h"







Player::Player()
{
}

Player::Player(int s, int w, int a)
{
	if (s == 0) {
		shield = "Red";
	}
	if (s == 1) {
		shield = "Blue";
	}
	if (s == 2) {
		shield = "Yellow";
	}
	if (s == 3) {
		shield = "Green";
	}


	if (w == 0) {
		weapon = "Red";
		damage = 80;
	}
	if (w == 1) {
		weapon = "Blue";
		damage = 90;
	}
	if (w == 2) {
		weapon = "Yellow";
		damage = 100;
	}
	if (w == 3) {
		weapon = "Green";
		damage = 60;
	}


	if (a == 0) {
		armor = "Red";
		health = 1000;
	}
	if (a == 1) {
		armor = "Blue";
		health = 800;
	}
	if (a == 2) {
		armor = "Yellow";
		health = 1000;
	}
	if (a == 3) {
		armor = "Green";
		health = 600;
	}

	isPois = false;
	isBleed = false;
	isStun = false;
	damMult = 1.0;


	//Placeholder
	if (s == 4) {
		weapon = "NULL";
		shield = "NULL";
		armor = "NULL";
	}
}

void Player::output()
{
	cout << "Shield: " << shield << endl;
	cout << "Weapon: " << weapon << endl;
	cout << "Armor : " << armor << endl;
}

Player::~Player()
{
}

void Player::attack(Player& rhs)
{
	//initial damage calc
	int doDam = damage*damMult;
	if (shieldColor() == "Red" && turn % 2 == 0) doDam = 0;	
	if (weaponColor() == "Red" && rand() % 100 < 20) doDam *= 2;
	if (weaponColor() == "Yellow" && rand() % 100 < 15) doDam = 0;

	//is it dodged
	if (rhs.armorColor() == "Blue" && rand()%100 < 15) 
	{
		return;
	}

	//shield properties
	if (rhs.shieldColor() == "Red" && turn % 2 == 0 && weaponColor() != "Yellow") doDam = 0;
	if (rhs.shieldColor() == "Blue" && weaponColor() != "Yellow") doDam = doDam*0.8;
	if (rhs.shieldColor() == "Green" && weaponColor() != "Yellow") poison();

	//status effects
	if (weaponColor() == "Blue" && rand() % 100 < 10 && doDam > 0) rhs.stun();
	if (weaponColor() == "Green") rhs.bleed();

	//deal damage
	rhs.hurt(doDam);
	if (rhs.armorColor() == "Green") hurt(doDam / 2);
}
