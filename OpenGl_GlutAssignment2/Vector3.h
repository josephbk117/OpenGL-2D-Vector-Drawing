#pragma once
#include "Vector2.h"
class Vector3
{
public:
	Vector3();
	Vector3(float x, float y, float z);
	float getZ();
	float getX();
	float getY();
	~Vector3();
private:
	float x, y, z;
};

