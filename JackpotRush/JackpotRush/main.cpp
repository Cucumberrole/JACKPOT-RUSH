#include "DxLib.h"
#include "Player.h"

#include "math.h"

int coinX = 500;
int coinY = 350;
bool coinGet = false;

int score = 0;

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

		ScreenFlip();
	}

	DxLib_End();

	return 0;
}