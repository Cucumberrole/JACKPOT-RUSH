#include "DxLib.h"
#include "Player.h"

#include "math.h"

int coinX = 500;
int coinY = 350;
bool coinGet = false;

int score = 3;

int slotResult = 0;
int speedTimer = 0;

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	ChangeWindowMode(TRUE);

	if (DxLib_Init() == -1)
	{
		return -1;
	}

	Player player;

	while (ProcessMessage() == 0)
	{
		ClearDrawScreen();

		player.Update();

		// スロット
		if (CheckHitKey(KEY_INPUT_E)) {
			if (score >= 3) {
				score -= 3;

				slotResult = GetRand(2) + 1;

				// スピードアップ!!!!!!!!!
				if (slotResult == 1) {
					player.moveSpeed = 10;
					speedTimer = 100;
				}
			}
		}

		// スピード効果時間
		if (speedTimer > 0)
		{
			speedTimer--;

			if (speedTimer <= 0)
			{
				player.moveSpeed = 5;
			}
		}

		// コイン取得
		if (!coinGet) {
			float dx = player.x - coinX;
			float dy = player.y - coinY;

			float distance = sqrtf(dx * dx + dy * dy);

			if (distance < 50) {
				coinGet = true;

				score += 1;
			}
		}

		// コイン描画
		if (!coinGet) {
			DrawCircle(coinX, coinY, 20, GetColor(255, 255, 0), TRUE);
		}

		player.Draw();

		// スコア表示
		DrawFormatString(20, 20, GetColor(255, 255, 255), "Score : %d", score);

		DrawFormatString(20, 60, GetColor(255, 255, 255), "Eキーでスロット！");
		DrawFormatString(20, 100, GetColor(255, 255, 0), "Slot Result : %d", slotResult);

		ScreenFlip();
	}

	DxLib_End();

	return 0;
}