// T01_G01

#ifndef Post_h
#define Post_h
 // !Post_h


#include "Misc.h"

class Post {
public:
	Post(int row, int col, char type);
	Post();
	int getRow() const;
	int getCol() const;
	char getSymbol() const; // get char representation of Post
	bool isElectrified() const;
	//other methods
private:
	int row, col;
	char type; // '*' - electrified; '+'- non-electrified
	// other attributes (?)
	// could also have a state, like the robot(?)
}; 
#endif 