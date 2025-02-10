#include "Bullet.h"
#include<Novice.h>

Bullet::Bullet(int speed, int radius)
{
	posX_ = 0;
	posY_ = 0;
	isShot_ = false;
	speed_ = speed;
	radius_ = radius;
}

void Bullet::Update()
{
	if (isShot_ == true) {
		posY_ += speed_;
	}
	if (posY_ < 0 - radius_) {
		isShot_ = false;
	}



}

void Bullet::Draw()
{
	if (isShot_ == true) {
		Novice::DrawEllipse(posX_, posY_, radius_, radius_, 0.0f, WHITE, kFillModeSolid);
	}
}