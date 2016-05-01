#include "Enemies.h"
#include <SFML/Graphics.hpp>
#include "Bullet.h"


Enemy *firstEnemy = NULL;
Enemy *lastEnemy = NULL;
sf::Texture enemyTexture = sf::Texture();

Enemy *newEnemy(float x, float y)
{
	if (firstEnemy == NULL) // in case we are making the first bullet/Node.
	{
		firstEnemy = new Enemy;
		lastEnemy = firstEnemy; // head and tail point to the same node since it's the only one for now.
		lastEnemy->next = NULL;
		lastEnemy->previous = NULL;
		enemyTexture.loadFromFile("Sprites/medspeedster.png");
	}
	else
	{
		lastEnemy->next = new Enemy; // pointing to the new node which is not known yet.
		lastEnemy->next->previous = lastEnemy; // this might be confusing here but it's just the unknown bullet node
						       // pointing to the previous bullet which is currently "LastBullet" and
						       // in the next step we will shift it to the end of the list again

		lastEnemy = lastEnemy->next;           // shifting to the end of the list
		lastEnemy->next = NULL;                 // making next pointing to nothing again.
	}

	lastEnemy->x = x; // making x data portion of struct equal to the parameter.
	lastEnemy->y = y; // same goes for y
	lastEnemy->look = sf::Sprite();
	lastEnemy->look.setTexture(enemyTexture);
	//lastEnemy->text = sf::Texture();
	//lastEnemy->text.loadFromFile("Sprites/medspeedster.png");
	//lastEnemy->look.setTexture(lastEnemy->text);

	lastEnemy->dead = false; // we set it to true only when we want the bullet destroyed.

	return lastEnemy; // notice that we are returning the pointer to the new bullet.

}

void EnemyLogic()
{
	Enemy *currentEnemy = firstEnemy; // this is a traversing pointer initialized to the first node and it moves through the list.

	while (currentEnemy != NULL)
	{
		currentEnemy->y += 5; // by the way, you can change the speed of the bullet by changing this number to something bigger or smaller.
		Xmotion(50,true,currentEnemy->x);

		if (currentEnemy->y > 600)			// killing the bullet if it goes out the screen.
			currentEnemy->dead = true;

		currentEnemy = currentEnemy->next; // moving to the next node.
	}

}

void RenderAndDeleteEnemy(sf::RenderWindow* window)
{
	Enemy *currentEnemy = firstEnemy; // we'll need this again.
	Enemy *KilledEnemy = NULL;		 // this is used when deleting a bullet from the list.

	while (currentEnemy != NULL)
	{
		if (currentEnemy->dead) // if dead is true
		{
			KilledEnemy = currentEnemy;
			currentEnemy = currentEnemy->next; // moving forward

			if (firstEnemy == KilledEnemy) // special instanses
			{
				firstEnemy = currentEnemy;
				if (currentEnemy != NULL)
					currentEnemy->previous = NULL;
			}
			else
			{
				KilledEnemy->previous->next = currentEnemy;
				if (currentEnemy != NULL)
				{
					currentEnemy->previous = KilledEnemy->previous;
				}
			}

			if (lastEnemy == KilledEnemy)
			{
				lastEnemy = KilledEnemy->previous; // making the tail bullet of the list the one before the deleted one.

			}

			delete KilledEnemy; // this is were we free the memory and delete the killedbullet tagged nodes.
		}
		else
		{
			currentEnemy->look.setPosition(currentEnemy->x,currentEnemy->y);
			window->draw(currentEnemy->look);

			currentEnemy = currentEnemy->next; // so we won't stay in the loop forever.
		}


	}
}

void DeleteAllEnemys()
{
	Enemy *currentEnemy = firstEnemy;
	Enemy *killedEnemy = NULL;            // same as render.

	while (currentEnemy != NULL)
	{
		killedEnemy = currentEnemy; // applying dead to the current node.
		currentEnemy = currentEnemy->next; // tagging all nodes.
		delete killedEnemy;				 // killem all
	}

	firstEnemy =NULL;
	lastEnemy = NULL;
}



void Xmotion(int Xrand, bool j, int i)

		{
			Xrand = rand() % 500;

			while (j = false)
			{
				if (i < Xrand)
				{
					do
					{
						i += .5;
					} while (i <= Xrand);
				}
				else
				{
					do {
						i -= .5;
					} while (i >= Xrand);
				}
				Xrand = rand() % 500;
				// I got rid of Xmotion() since you said it produces endless loops and nice catch by the way.
			}	// and I cleaned up the spaces in the function so it looks more readable.
}

		// ******************* this is assuming that the enemy is 64X64 *********************

		/* if (currentBullet->x >= currentEnemy->x && currentBullet->x <= currentEnemy->x + 64)
		{
			if (currentBullet->y >= currentEnemy->y && currentBullet->y <= currentEnemy->y + 64)
				{
					currentEnemy->dead = true;
					currentBullet->dead = true;
					score += 50; //or what ever you want it to be
				}
		}*/

bool EnemyHit(int x, int y)
{
	Enemy *currentEnemy = firstEnemy;
	while (currentEnemy != NULL)
	{
	if (x >= currentEnemy->x && x <= currentEnemy->x+84)
	{
		if (y >= currentEnemy->x && y <= currentEnemy->x+84)
		{
		currentEnemy->dead = true;
		return true;
		}

	}
	else{return false;}
	currentEnemy = currentEnemy->next;
	}


}

bool PlayerCollision(int x1, int x2, int y)
{
	Enemy *currentEnemy = firstEnemy;	
	while (currentEnemy != NULL)
	{
	
	if (x >= currentEnemy->x && x <= currentEnemy->x+84)
	{
		if (y >= currentEnemy->x && y <= currentEnemy->x+84)
		{
		currentEnemy->dead = true;
		return true;
		}

	}
	else if (x+63 >= currentEnemy->x && x+63 <= currentEnemy->x+84)
	{
		if (y >= currentEnemy->x && y <= currentEnemy->x+84)
		{
		currentEnemy->dead = true;
		return true;
		}
	}
	else{return false;}
	currentEnemy = currentEnemy->next;
	}
	
}

