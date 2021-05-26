// T01_G01

#include <iostream>
#include <iomanip>
#include <fstream>
#include<string>
#include "Misc.h"
#include "Player.h"
#include "Robot.h"
#include "Post.h"
#include "Maze.h"
#include "Game.h"


using namespace std;
void resetScreenmenu() {
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
}

int main()
{
	string name, line;
	int op;
	while (true) {
		resetScreenmenu();
		cout << "Choose one option:\n1)Rules\n2)Play\n3)Winners\n0)Exit\n";
		cin >> op;
		if (cin.eof())
			return 0;
		else if (op == 1) {
			int selection;
			resetScreenmenu();
			ifstream rules;
			rules.open("RULES.txt");
			while (getline(rules, line)) {
				cout << line << endl;
			}
			do {
				cin >> selection;
				if (cin.eof())
					return 0;
			} while (selection != 0);
			resetScreenmenu();
		}
		else if (op == 2) {
			string number;
			resetScreenmenu();
			while (true) {
				cout << "Which maze would you like to use:\n";
				cin >> number;
				if (number.size() == 1) {
					number = "0" + number;
				}
				if (cin.eof()) {
					return 0;
				}
				ifstream stream;
				stream.open("MAZE_" + number + ".txt");
				if (stream) {
					stream.close();
					break;
				}
				else {
					stream.close();
					cout << "Maze doesn't exist\n\n";
				}
			}
			Game jogo("MAZE_" + number + ".txt");
			jogo.play(number);
		}
		else if (op == 3) {
			while (cin) {
				string number = "", line;
				cout << "\nWhich Maze would you like to see the winners of?(0 to go back to Menu)\n";
				cin >> number;
				if (number == "0")
					break;
				if (number.size() == 1) {
					number = "0" + number;
				}
				if (cin.eof()) {
					return 0;
				}
				fstream winners;
				winners.open("MAZE_" + number + "_WINNERS.txt");
				if (winners.is_open()) {
					while (getline(winners, line))
					{
						cout << line << '\n';
					}
					winners.close();
				}
				else
					cout << "empty list\n";
			}
		}
		else if (op == 0) {
			return 0;
		}
	}
}

