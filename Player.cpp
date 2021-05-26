#include "Player.h"
using namespace std;

Player::Player(int row, int col, char symbol) {
	this->row = row;
	this->col = col;
	this->symbol = symbol;
	alive = true;
}

Player::Player() {
	this->row = 0;
	this->col = 0;
	this->symbol = 'H';
	alive = true;
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
	symbol = 'h';
	alive = false;
}

void Player::move(Movement delta) {
	row = row + delta.dRow;
	col = col + delta.dCol;
}

void Player::changeplace(Player& hero) {
	this->col = hero.getCol();
	this->row = hero.getRow();
}