#pragma once
#include"Bullet.h"
class Player
{
public:

	int GetPosX()const { return posX_;};
	int GetPosY()const { return posY_; };
	int GetSpeedX()const { return speedX_; };
	int GetRadius()const { return radius_; };

	static int isAlive_;
	
	Bullet* bullet;



	Player();
	void Reset();
	virtual void Update(char* keys);
	virtual void Draw();

private:
	int posX_;
	int posY_;
	int speedX_;
	int radius_;
};
