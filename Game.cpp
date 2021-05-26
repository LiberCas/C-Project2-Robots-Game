#include <iostream>
#include "Misc.h"
#include "Player.h"
#include "Robot.h"
#include "Post.h"
#include "Maze.h"
#include "Game.h"
#include <string>
#include <fstream>
#include<vector>
#include <cmath>
#include <iomanip>

using namespace std;

void resetScreen() {
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
}

void changePlace(Movement& move, char mov) {
	if (mov == 'q') {
		move.dRow = -1;
		move.dCol = -1;
	}
	else if (mov == 'w') {
		move.dCol = 0;
		move.dRow = -1;
	}
	else if (mov == 'e') {
		move.dRow = -1;
		move.dCol = 1;
	}
	else if (mov == 'a') {
		move.dRow = 0;
		move.dCol = -1;
	}
	else if (mov == 'd') {
		move.dRow = 0;
		move.dCol = 1;
	}
	else if (mov == 'z') {
		move.dRow = 1;
		move.dCol = -1;
	}
	else if (mov == 'x') {
		move.dRow = 1;
		move.dCol = 0;
	}
	else if (mov == 'c') {
		move.dRow = 1;
		move.dCol = 1;
	}
}

Game::Game(const string& filename) {
	ifstream file;
	int nlines, ncols, i, j, id = 1;
	vector<Robot> robos;
	vector<Post> fences;
	file.open(filename);
	if (file.is_open()){
		cout << "ABRIU!";
		file >> nlines;
		file.ignore(3);
		file >> ncols;
		file.ignore(1);
		Maze mazefile(nlines, ncols);
		maze = mazefile;
		for (i = 0; i < maze.getnumRows(); i++) {
			string line;
			getline(file, line);
			for (j = 0; j < maze.getnumCols(); j++) {
				if (line[j] == 'H') {
					Player hero(i, j, 'H');
					player = hero;
				}
				else if (line[j] == 'R') {
					Robot robo(i, j, id);
					robos.push_back(robo);
					id++;
				}
				else if (line[j] == '*') {
					Post fence(i, j, '*');
					fences.push_back(fence);
				}
				else if (line[j] == '+') {
					Post fence(i, j, '+');
					fences.push_back(fence);
				}
				else if (line[j] == 'O') {
					Post fence(i, j, 'O');
					fences.push_back(fence);
				}
			}
		}
		posts = fences;
		robots = robos;
		}
	else {
		cout << "Unable to open file\n\n";
	}
}

bool Game::play() {
	while (true) {
		showGameDisplay();
		char movement;
		if (player.getSymbol() == 'h') {
			cout << "Sorry but you LOST!\n";
			return false;
		}
		Player hero1(player.getRow(), player.getCol(), player.getSymbol());
		while (true) {
			do {
				cout << "Input valid movement(q/w/e/a/s/d/z/x/c): \n";
				cin >> movement;
				if (!cin.eof())
					movement = tolower(movement);
				else {
					return 0;
				}
			} while (movement != 'q' && movement != 'w' && movement != 'e' && movement != 'a' && movement != 's' && movement != 'd' && movement != 'z' && movement != 'x' && movement != 'c' && movement != 's');
			Movement move;
			changePlace(move, movement);
			Player hero2(player.getRow() + move.dRow, player.getCol() + move.dCol, player.getSymbol());
			bool valid = true;
			bool elet = false;
			for (int z = 0; z < posts.size(); z++) {
				if (hero2.getRow() == posts[z].getRow() && hero2.getCol() == posts[z].getCol()) {
					if (posts[z].getSymbol() == '*') {
						player.setAsDead();
						elet = true;
					}
					else if (posts[z].getSymbol() == 'O') {
						player.move(move);
						posts.erase(posts.begin() + z);
						showGameDisplay();
						string name;
						cout << "Congratulations! You won! Now write your name to put in the leaderboard!\n";
						cin >> name;
						return true;
					}
					else {
						cout << "You cannot go through a non-electrified post!\n";
						valid = false;
					}
				}
			}
			for (int z = 0; z < robots.size(); z++) {
				if (robots[z].isAlive() == false && hero2.getRow() == robots[z].getRow() && hero2.getCol() == robots[z].getCol()) {
					cout << "you cannot go through a dead robot!\n";
					valid = false;
				}
			}
			if (valid == true) {
				if (elet != true) {
					player.move(move);
				}
				break;
			}
		}
		for (int z = 0; z < robots.size(); z++) {
			Robot aux(robots[z].getRow(), robots[z].getCol(), robots[z].getID());
			robots[z].moveRobot(player);
			for (int i = 0; i < posts.size(); i++) {
				if (robots[z].getCol() == posts[i].getCol() && robots[z].getRow() == posts[i].getRow()) {
					if (posts[i].getSymbol() != '*') {
						posts.erase(posts.begin() + i);
						robots[z].setAsDead();
					}
					else {
						robots[z].setAsDead();
						robots[z].setPosition(aux.getPosition());
					}
				}
			}
			if (collide(robots[z], player) == true) {
				player.setAsDead();
				robots[z].setPosition(aux.getPosition());
				break;
			}
		}
		for (int z = 0; z < robots.size(); z++) {
			for (int i = z+1; i < robots.size(); i++) {
				collide(robots[z], robots[i]);
			}
		}
	}
}


void Game::showGameDisplay() const {
	resetScreen();
	for (int i = 0; i < maze.getnumRows(); i++) {
		for (int j = 0; j < maze.getnumCols(); j++) {
			bool over = false;
			if (i == player.getRow() && j == player.getCol()) {
				cout << player.getSymbol();
				over = true;
			}
			for (int z = 0; z < posts.size(); z++) {
				if (i == posts[z].getRow() && j == posts[z].getCol()) {
					cout << posts[z].getSymbol();
					over = true;
					break;
				}
			}
			for (int z = 0; z < robots.size(); z++) {
				if (i == robots[z].getRow() && j == robots[z].getCol()) {
					cout << robots[z].getSymbol();
					over = true;
					break;
				}
			}
			if (over == false) {
				cout << ' ';
			}
		}
		cout << endl;
	}
}

bool Game::collide(Robot& robot, Post& post) {
	if (robot.getCol() == post.getCol() && robot.getRow() == post.getCol()) {
		robot.setAsDead();
		return true;
	}
	else {
		return false;
	}
}

bool Game::collide(Robot& robot, Player& player) {
	if (robot.getCol() == player.getCol() && robot.getRow() == player.getRow()) {
		player.setAsDead();
		return true;
	}
	else {
		return false;
	}
}

bool Game::collide(Robot& robot1, Robot& robot2) {
	if (robot1.getCol() == robot2.getCol() && robot1.getRow() == robot2.getRow()) {
		robot1.setAsDead();
		robot2.setAsDead();
		return true;
	}

	else {
		return false;
	}
}