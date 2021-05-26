// T01_G01

#ifndef Game_h
#define Game_h


#include <iostream>
#include "Misc.h"
#include "Player.h"
#include "Robot.h"
#include "Post.h"
#include "Maze.h"
#include <vector>

class Game {
public:
	Game(const string& filename);
	// This constructor should initialize the Maze, the vector of Robots, and the Player,
	// using the chars read from the file
	bool play(string number); // implements the game loop; returns true if player wins, false otherwise
	void showGameDisplay() const;
	bool collide(Robot& robot, Post& post); // check if robot collided with post (and possibly set it as dead)
	bool collide(Robot& robot, Player& player);
	bool collide(Robot& robot1, Robot& robot2);// check if human and robot collided (and possibly set human as dead)
	// other methods, for example:
	// to check if player is trying to move to a valid place
	// to apply a valid play and check collisions
	// to check if two robots collide (and possibly set them as dead)
	// etc.
private:
	Maze maze;
	Player player;
	vector<Robot> robots;
	vector<Post> posts;
};

#endif 