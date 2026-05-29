#pragma once

class Player
{
public:

	int x;
	int y;

	float vy; // Vertical Velocity

	bool isGround;

	Player();

	void Update();
	void Draw();
};