// T01_G01

#include "Post.h"


Post::Post(int row, int col, char type) {
	this->row = row;
	this->col = col;
	this->type = type;
}

Post::Post() {
	row = 0;
	col = 0;
	type = '*';
}

int Post::getRow() const {
	return row;
}

int Post::getCol() const {
	return col;
}

char Post::getSymbol() const {
	return type;
}

bool Post::isElectrified() const {
	if (type == '*') {
		return true;
	}
	else {
		return  false;
	}
}