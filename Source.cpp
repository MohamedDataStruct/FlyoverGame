#include<iostream>
#include "player.h"
using namespace std;



int main() {
	player ob;
	ob.setup();
	while (!ob.gameOver)
	{
		ob.Draw();
		ob.input();
		ob.logic();
	}

	
}