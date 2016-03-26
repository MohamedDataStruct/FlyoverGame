#pragma once
class player
{
private: 
	
	static const int width = 40;
	static const int height = 40;
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

