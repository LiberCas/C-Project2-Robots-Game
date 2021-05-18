#include "Robot.h"
#include <vector>
Robot::Robot(int row, int col){
	this->row = row;
	this->col = col;
	alive = true;
	id = 0;
	}

int Robot::getID() const {
	return id;
}

char Robot::getSymbol() const {
	if (alive == true) {
		return 'R';
	}
	else {
		return 'r';
	}
}

int Robot::getRow() const {
	return row;
}

int Robot::getCol() const {
	return col;
}

Position Robot::getPosition() const {
	Position a;
	a.row = row;
	a.col = col;
	return a;
}

bool Robot::isAlive() const {
	return alive;
}

void Robot::setRow(int x) {
	row = x;
}

void Robot::setCol(int y) {
	col = y;
}

void Robot::setPosition(const Position& pos) {
	row = pos.row;
	col = pos.col;
}

void Robot::setAsDead() {
	alive = false;
}

void Robot::setId(const std::vector<Robot>& robots) {
	int i = sizeof(robots), j;
	for (j = 1; j <= i; j++) {
		id = j;
	}
}