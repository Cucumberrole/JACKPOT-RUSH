#include "DxLib.h"
#include "Player.h"

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
		player.Draw();

		ScreenFlip();
	}

	DxLib_End();

	return 0;
}