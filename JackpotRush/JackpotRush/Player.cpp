#include "Player.h"
#include "DxLib.h"

Player::Player()
{
	x = 300;
	y = 400;

	vy = 0;
	isGround = false;

	moveSpeed = 5;
}

void Player::Update()
{
	// 左右移動
	if (CheckHitKey(KEY_INPUT_A))
	{
		x -= moveSpeed;
	}

	if (CheckHitKey(KEY_INPUT_D))
	{
		x += moveSpeed;
	}

	// ジャンプ処理
	if (CheckHitKey(KEY_INPUT_SPACE) && isGround) {
		vy = -12;
		isGround = false;
	}
	// 重力
	vy += 0.5f;
	//落下
	y += vy;
	// 床判定
	if (y >= 400) {
		y = 400;
		vy = 0;
		isGround = true;
	}
}

void Player::Draw()
{
	DrawBox(x, y, x + 50, y + 50, GetColor(255, 255, 255), TRUE);
}