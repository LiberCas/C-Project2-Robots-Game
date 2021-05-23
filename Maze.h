#ifndef Maze_h
#define Maze_h
 // !Maze_h


#include "Post.h"
#include "Misc.h"

class Maze {
public:
	Maze(int numRows, int numCols);
	Maze();
	bool addPost(const Post& post, const Position& position);
	int getnumRows() const;
	int getnumCols() const;
	// other methods
private:
	int numRows, numCols;
	// data structure that represents the posts
};

#endif 