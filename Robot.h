#include "Misc.h"
#include <vector>

class Robot {
public:
	enum State { ALIVE, STUCK, DEAD };
	Robot(int row, int col);
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
	void setId(const std::vector<Robot> &robots);
private:
	int id;
	int row, col;
	bool alive;
	// other attributes (?)
};