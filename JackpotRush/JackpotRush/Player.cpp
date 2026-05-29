#include "Player.h"
#include "DxLib.h"

Player::Player()
{
	x = 300;
	y = 400;
}

void Player::Update()
{
	if (CheckHitKey(KEY_INPUT_A))
	{
		x -= 5;
	}

	if (CheckHitKey(KEY_INPUT_D))
	{
		x += 5;
	}
}

void Player::Draw()
{
	DrawBox(x, y, x + 50, y + 50, GetColor(255, 255, 255), TRUE);
}