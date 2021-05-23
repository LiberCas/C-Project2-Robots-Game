#include <iostream>
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
	bool game_running = true;
	string name, line; 
	int op;
	while (game_running) {
		resetScreenmenu();
		cout << "Choose one option:\n1)Rules\n2)Play\n0)Exit\n";
		cin >> op;
		if (op == 1) {
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
			} 	while (selection != 0);
			resetScreenmenu();
		}
		else if (op == 2) {
			string number;
			resetScreenmenu();
			cout << "Which maze would you like to use:\n";
			cin >> number;
			Game jogo("MAZE_" + number + ".txt");
			game_running = jogo.play();
		}
		else if (op == 0) {
			break;
		}
	}
	}	
