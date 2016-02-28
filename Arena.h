#pragma once

#include "Player.h"
#include <cstdlib>
#include <ctime>

class Arena
{
public:
	Arena(Player pone, Player ptwo);
	~Arena();
	void takeTurn();
	Player simulate();

private:
	int turn;
	Player p1;
	Player p2;
};

