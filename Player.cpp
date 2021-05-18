#include "Player.h"
using namespace std;

Player::Player(int row, int col, char symbol) {
	this->row = row;
	this->col = col;
	this->symbol = symbol;
}

int Player::getRow() const {
	return row;
}

int Player::getCol() const {
	return col;
}

char Player::getSymbol() const {
	return symbol;
}

bool Player::isAlive() const {
	return alive;
}

void Player::setAsDead() {
	alive = false;
}

bool Player::move(Movement delta) {
	row = row + delta.dRow;
	col = col + delta.dCol;
}
