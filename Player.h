#pragma once

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

class Player
{
public:
	Player();
	Player(int s, int w, int a);
	void output();
	~Player();
	string weaponColor() { return weapon; }
	string shieldColor() { return shield; }
	string armorColor() { return armor; }
	bool stunned() { return isStun; }
	bool poisoned() { return isPois; }
	bool bleeding() { return isBleed; }
	int currentHealth() { return health; }
	void attack(Player& rhs);

	void poison() { isPois = true; }
	void bleed() { isBleed = true; }
	void stun() { isStun = true; }
	void hurt(int dam) { health -= dam; }
	void adjMult()
	{
		damMult = 1 + (((1000 - health) / 100)*.05);
	}

	void advTurn() { turn++; }

	void cureAll() { isPois = false; isBleed = false; isStun = false; }
	void unstun() { isStun = false; }
protected:
	string shield;
	string armor;
	string weapon;
private:
	int health;
	int damage;
	bool isPois;
	bool isBleed;
	bool isStun;
	double damMult;
	int turn;
};

