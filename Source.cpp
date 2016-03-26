#include<iostream>
#include "player.h"
using namespace std;



int mainx() {
	player ob;
	ob.setup();
	while (!ob.gameOver)
	{
		ob.Draw();
		ob.input();
		ob.logic();
	}
	return 0;
	
}