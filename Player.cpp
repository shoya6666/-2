#include "Player.h"
#include<Novice.h>

Player::Player() {
	posX_ = 600;
	posY_ = 650;
	speedX_ = 7;
	radius_ = 25;
	bullet = new Bullet(-10, 5);
	isAlive_ = true;
}

void Player::Reset()
{
	posX_ = 600;
	posY_ = 650;
	speedX_ = 7;
	radius_ = 25;
	bullet = new Bullet(-10, 5);
	isAlive_ = true;
}

void Player::Update(char* keys)
{
	if (keys[DIK_W]) {
		if (posY_ >= 0 + radius_) {
			posY_ -= speedX_;
		}
	}
	if (keys[DIK_S]) {
		if (posY_ <= 720 - radius_) {
			posY_ += speedX_;
		}
	}
	if (keys[DIK_A]) {
		if (posX_ >= 0 + radius_) {
			posX_ -= speedX_;
		}
	}
	if (keys[DIK_D]) {
		if (posX_ <= 1280 - radius_) {
			posX_ += speedX_;
		}
	}

	if (keys[DIK_SPACE]) {
		if (bullet->isShot_ == false) {
			bullet->isShot_ = true;
			bullet->posX_ = posX_;
			bullet->posY_ = posY_;
		}
	}

	bullet->Update();


}


void Player::Draw()
{
	if (isAlive_ == 1) {
		Novice::DrawEllipse(posX_, posY_, radius_, radius_, 0.0f, WHITE, kFillModeSolid);
	}
	bullet->Draw();

}