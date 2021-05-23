#include "Maze.h"
#include "Misc.h"
#include "Post.h"

Maze::Maze(int numRows, int numCols) {
	this->numCols = numCols;
	this->numRows = numRows;
}

Maze::Maze() {
	numCols = 0;
	numRows = 0;
}

bool Maze::addPost(const Post& post, const Position& position) {
	if (position.col > numCols || position.row > numRows) {
		return false;
	}
	else {
		return true;
	}
}

int Maze::getnumRows() const {
	return numRows;
}

int Maze::getnumCols() const {
	return numCols;
}