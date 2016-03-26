#pragma once
class player
{
private: 
	
	const int width = 40;
	const int height = 40;
	int x, y, score;
	enum Direction { STOP = 0, LEFT, RIGHT, UP, DOWN };
	Direction dir;
public:
	bool gameOver;
	void setup();
	void Draw();
	void input();
	void logic();
};

