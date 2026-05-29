#pragma once

class Player
{
public:

	int x;
	int y;

	float vy;

	bool isGround;

	Player();

	void Update();
	void Draw();
};