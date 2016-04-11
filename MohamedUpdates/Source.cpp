#include<iostream>

using namespace std;

struct Bullet
{
	float x;
	float y;
	bool dead; // a variable that is when set to true kills the node.
	Bullet *next;
	Bullet *previous;
};

Bullet *firstBullet = NULL;
Bullet *lastBullet = NULL;



// the updating function :

Bullet *newbullet(float x, float y)
{
	if (firstBullet == NULL) // in case we are making the first bullet/Node.
	{
		firstBullet = new Bullet; 
		lastBullet = firstBullet; // head and tail point to the same node since it's the only one for now.
		lastBullet->next = NULL;
		lastBullet->previous = NULL;
	}
	else
	{
		lastBullet->next = new Bullet; // pointing to the new node which is not known yet.
		lastBullet->next->previous = lastBullet; // this might be confusing here but it's just the unknown bullet node
												 // pointing to the previous bullet which is currently "LastBullet" and
												 // in the next step we will shift it to the end of the list again

		lastBullet = lastBullet->next;           // shifting to the end of the list
		lastBullet->next = NULL;                 // making next pointing to nothing again. 
	}

	lastBullet->x = x; // making x data portion of struct equal to the parameter. 
	lastBullet->y = y; // same goes for y

	lastBullet->dead = false; // we set it to true only when we want the bullet destroyed.
	
	return lastBullet; // notice that we are returning the pointer to the new bullet.

}

void BulletLogic()
{
	Bullet *currentBullet = firstBullet; // this is a traversing pointer initialized to the first node and it moves through the list.
	
	while (currentBullet != NULL) 
	{
		currentBullet->y -= 1; // by the way, you can change the speed of the bullet by changing this number to something bigger.
		
		if (currentBullet < 0)			// killing the bullet if it goes out the screen.
			currentBullet->dead = true;
		
		currentBullet = currentBullet->next; // moving to the next node.
	}

}

void RenderAndDeleteBullet()
{
	Bullet *currentBullet = firstBullet; // we'll need this again.
	Bullet *KilledBullet = NULL;		 // this is used when deleting a bullet from the list.

	while (currentBullet != NULL)
	{
		if (currentBullet->dead) // if dead is true
		{
			KilledBullet = currentBullet;
			currentBullet = currentBullet->next; // moving forward

			if (firstBullet == KilledBullet) // special instanses
			{
				firstBullet = currentBullet;
				if (currentBullet != NULL)
					currentBullet->previous = NULL;
			}
			else
			{
				KilledBullet->previous->next = currentBullet;
				if (currentBullet != NULL)
				{
					currentBullet->previous = KilledBullet->previous;
				}
			}

			if (lastBullet == KilledBullet)
			{
				lastBullet = KilledBullet->previous; // making the tail bullet of the list the one before the deleted one.

			}

			delete KilledBullet; // this is were we free the memory and delete the killedbullet tagged nodes.
		}
		else
		{
			// MOSE ENTER YOUR RENDERING CODE HERE **********************************************
			// USING SFML LIBRARY.***************************************************************

			currentBullet = currentBullet->next; // so we won't stay in the loop forever.
		}
	}
}

void DeleteAllBullets()
{
	Bullet *currentBullet = firstBullet;
	Bullet *killedBullet = NULL;            // same as render.

	while (currentBullet != NULL) 
	{
		killedBullet = currentBullet; // applying dead to the current node.
		currentBullet = currentBullet->next; // tagging all nodes.
		delete killedBullet;				 // killem all
	}
	
	firstBullet=NULL;
	lastBullet = NULL;
}







int main() {



	system("pause");
}

	


