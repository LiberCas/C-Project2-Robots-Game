// T01_G01

#ifndef Player_h
#define Player_h


#include "Misc.h"
using namespace std;

class Player {
public:
	Player(int row, int col, char symbol);
	Player();
	int getRow() const;
	int getCol() const;
	char getSymbol() const;
	bool isAlive() const;
	void setAsDead();
	void move(Movement delta);
	void changeplace(Player& hero);
private:
	int row, col;
	bool alive;
	char symbol;
};

#endif 