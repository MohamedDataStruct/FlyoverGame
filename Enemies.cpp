#include<iostream>

using namespace std;

struct Enemy
{
	float x;
	float y;
	bool dead; // a variable that is when set to true it kills the node.
	Enemy *next;
	Enemy *previous;
};

Enemy *firstEnemy = NULL;
Enemy *lastEnemy = NULL;



Enemy *newEnemy(float x, float y)
{
	if (firstEnemy == NULL) // in case we are making the first bullet/Node.
	{
		firstEnemy = new Enemy; 
		lastEnemy = firstEnemy; // head and tail point to the same node since it's the only one for now.
		lastEnemy->next = NULL;
		lastEnemy->previous = NULL;
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

	lastEnemy->dead = false; // we set it to true only when we want the bullet destroyed.
	
	return lastEnemy; // notice that we are returning the pointer to the new bullet.

}

void EnemyLogic()
{
	Enemy *currentEnemy = firstEnemy; // this is a traversing pointer initialized to the first node and it moves through the list.
	
	while (currentEnemy != NULL) 
	{
		currentEnemy->y += .5; // by the way, you can change the speed of the bullet by changing this number to something bigger or smaller.
		void Xmotion(int Xrand)

		{

			while (currentEnemy->dead = false)
			{
				Xrand = rand() % 500;

				if (currentEnemy->x < Xrand)
				{
					do
					{
						currentEnemy->x += .5;



					} while (currentEnemy->x <= Xrand)

				}

				else
				{
					do {
						currentEnemy->x -= .5;


					} while (currentEnemy->x >= Xrand)


				}

				Xrand = rand() % 500;
				Xmotion(Xrand);

			}
			}


		if (currentEnemy < 0)			// killing the bullet if it goes out the screen.
			currentEnemy->dead = true;
		
		currentEnemy = currentEnemy->next; // moving to the next node.
	}

}

void RenderAndDeleteEnemy()
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
			// MOSE ENTER YOUR RENDERING CODE HERE **********************************************
			// USING SFML LIBRARY.***************************************************************

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








