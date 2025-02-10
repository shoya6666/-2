#include <Novice.h>
#include"Enemy.h"
#include"Player.h"
#include"Bullet.h"

const char kWindowTitle[] = "GC1C_08_タナカ_ショウヤ_タイトル";
const int kWindowWidth = 1280;
const int kWindowHeight = 720;

enum Scene
{
	TITLE,
	Play,
};

int Enemy::isAlive_;
int Player::isAlive_;



// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, kWindowWidth, kWindowHeight);

	Player* player = new Player;

	Enemy* enemy[2];
	enemy[0] = new Enemy(50, 300);
	enemy[1] = new Enemy(500, 400);

	int currentScene = TITLE;

	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };


	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///

		switch (currentScene) {
		case TITLE:
			if (keys[DIK_RETURN]) {
				player->Reset();
				enemy[0]->Reset(50, 300);
				enemy[1]->Reset(500, 400);
				currentScene = Play;
			}
			break;
		case Play:
			player->Update(keys);

			for (int i = 0; i < 2; i++) {
				enemy[i]->Update();

				float distX = static_cast<float>(enemy[i]->GetPosX() - player->bullet->posX_);
				float distY = static_cast<float>(enemy[i]->GetPosY() - player->bullet->posY_);
				float dist = (distX * distX) + (distY * distY);
				float radius = static_cast<float>(enemy[i]->GetRadius() + player->bullet->radius_);
				if (dist <= radius * radius) {
					Enemy::isAlive_ = false;
				}
			}

			for (int i = 0; i < 2; i++) {
				enemy[i]->Update();

				float distX = static_cast<float>(enemy[i]->GetPosX() - player->GetPosX());
				float distY = static_cast<float>(enemy[i]->GetPosY() - player->GetPosY());
				float dist = (distX * distX) + (distY * distY);
				float radius = static_cast<float>(enemy[i]->GetRadius() + player->GetRadius());
				if (dist <= radius * radius) {
					Player::isAlive_ = false;
				}
			}

			if (keys[DIK_R]) {
				Enemy::isAlive_ = true;
			}

			if (Player::isAlive_ == false) {
				currentScene = TITLE;
			}
			if (Enemy::isAlive_ == false) {
				currentScene = TITLE;
			}
			break;
		}
		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		switch (currentScene) {
		case TITLE:

			Novice::ScreenPrintf(kWindowWidth / 2, kWindowHeight / 2, "ENTER",WHITE, kFillModeSolid);

			Novice::DrawBox(0, 0, kWindowWidth, kWindowHeight, 0.0f, BLACK, kFillModeSolid);
			break;
		case Play:
			player->Draw();

			for (int i = 0; i < 2; i++) {
				enemy[i]->Draw();
			}
			break;
		}
		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}