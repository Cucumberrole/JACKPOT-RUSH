#pragma once

class Player
{
public:

	int x;
	int y;

	float vy; // Vertical Velocity

	bool isGround;

	float moveSpeed;

	Player();

	void Update();
	void Draw();
};