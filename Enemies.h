#include<iostream>
#include<SFML/Graphics.hpp>

using namespace std;

struct Enemy
{
	float x;
	float y;
	bool dead; // a variable that is when set to true it kills the node.
	Enemy *next;
	Enemy *previous;
};

void Xmotion(int, bool, int);

Enemy* newEnemy(float x, float y);

void EnemyLogic();

void RenderAndDeleteEnemy(sf::RenderWindow*);

void DeleteAllEnemys();