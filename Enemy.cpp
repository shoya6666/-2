#include "Enemy.h"
#include<Novice.h>

Enemy::Enemy(int posX, int posY) {
	posX_ = posX;
	posY_ = posY;
	speedX_ = 10;
	radius_ = 30;
	isAlive_ = true;

}

void Enemy::Reset(int posX, int posY)
{
	posX_ = posX;
	posY_ = posY;
	speedX_ = 10;
	radius_ = 30;
	isAlive_ = true;
}

void Enemy::Update() {
	if (isAlive_ == 1) {
		posX_ += speedX_;

		if (posX_ - radius_ <= 0 || posX_ + radius_ >= 1280) {
			speedX_ *= -1;
		}
	}
}

void Enemy::Draw() {
	if (isAlive_ == 1) {
		Novice::DrawEllipse(posX_, posY_, radius_, radius_, 0.0f, RED, kFillModeSolid);
	}
}