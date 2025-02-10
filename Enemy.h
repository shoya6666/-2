#pragma once
class Enemy
{
public:

	int GetPosX()const { return posX_; };
	int GetPosY()const { return posY_; };
	int GetSpeedX()const { return speedX_; };
	int GetRadius()const { return radius_; };

	static int isAlive_;


	Enemy(int posX, int posY);
	void Reset(int posX, int posY);
	virtual void Update();
	virtual void Draw();

private:

	int posX_;
	int posY_;
	int speedX_;
	int radius_;
};
