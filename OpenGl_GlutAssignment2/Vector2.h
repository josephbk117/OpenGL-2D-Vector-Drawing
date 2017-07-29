#pragma once
class Vector2
{
public:
	Vector2();
	Vector2(int x, int y);
	int getX();
	int getY();
	static float Distance(Vector2 x, Vector2 y);
	~Vector2();
public:
	int x, y;
};

