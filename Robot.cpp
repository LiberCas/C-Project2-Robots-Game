#include "Robot.h"
#include <vector>

double const PI = 3.141592653589793;


Robot::Robot(int row, int col, int id){
	this->row = row;
	this->col = col;
	this->id = id;
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

void Robot::moveRobot(Player& player) {
	if (this->alive == true) {
		float y = player.getRow() - this->row, x = player.getCol() - this->col, angle;
		angle = 180 * acos(x / sqrt((x * x) + (y * y))) / PI;
		if (y < 0)
			angle = 360 - angle;
		//Moving the robots
		if (angle >= 337.5 || angle < 22.5) {
			//Angle closest to 0º
			this->col++;
		}
		else if (angle >= 22.5 && angle < 67.5) {
			//Angle closest to 45º
			this->col++;
			this->row++;
		}
		else if (angle >= 67.5 && angle < 112.5) {
			//Angle closest to 90º
			this->row++;
		}
		else if (angle >= 112.5 && angle < 157.5) {
			//Angle closest to 135º
			this->col--;
			this->row++;
		}
		else if (angle >= 157.5 && angle < 202.5) {
			//Angle closest to 180º
			this->col--;

		}
		else if (angle >= 202.5 && angle < 247.5) {
			//Angle closest to 225º
			this->col--;
			this->row--;

		}
		else if (angle >= 247.5 && angle < 292.5) {
			//Angle closest to 270º
			this->row--;
		}
		else {
			//Angle closest to 315º
			this->row--;
			this->col++;
		}
	}

}
