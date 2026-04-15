#ifndef blackjack_h
#define blackjack_h

#include <ctime>
#include <cmath>
#include <cstdlib>
#include <iostream>


class Player {
public:
	Player() { playernum = rand() % 11; };
	void check();
	int play();
	int getPlayerNum() { return playernum; };
private:
	int playernum;
};

class Computer {
public:
	Computer() { computernum = rand() % 11; };
	void check();
	int play();
	int getComputerNum() { return computernum; };
private:
	int computernum;
};

#endif