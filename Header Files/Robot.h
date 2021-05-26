// T01_G01

#ifndef Robot_h
#define Robot_h
 // !Robot_h



#include "Misc.h"
#include <vector>
#include "Player.h"

class Robot {
public:
	enum State { ALIVE, STUCK, DEAD };
	Robot(int row, int col, int id);
	int getID() const;
	char getSymbol() const; // get char representation of robot (R if alive, r if dead)
	int getRow() const;
	int getCol() const;
	Position getPosition() const;
	bool isAlive() const;
	void setRow(int x);
	void setCol(int y);
	void setPosition(const Position& pos);
	void setAsDead();
	void moveRobot(Player& player);
private:
	int id;
	int row, col;
	bool alive;
	// other attributes (?)
};
#endif 