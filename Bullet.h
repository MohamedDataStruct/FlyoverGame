#ifndef BULLET_H
#define BULLET_H
// the updating function :

struct Bullet
{
	float x;
	float y;
	bool dead; // a variable that is when set to true
	sf::RectangleShape sprite;
	Bullet *next;
	Bullet *previous;
};

Bullet* newbullet(float x, float y);

int BulletLogic();

void RenderAndDeleteBullet(sf::RenderWindow*);

void DeleteAllBullets();

#endif
