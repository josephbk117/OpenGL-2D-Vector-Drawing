#include "Vector3.h"

Vector3::Vector3()
{
	this->x = 0;
	this->y = 0;
	this->z = 0;
}

Vector3::Vector3(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

float Vector3::getZ()
{
	return z;
}
float Vector3::getY()
{
	return y;
}
float Vector3::getX()
{
	return x;
}

Vector3::~Vector3()
{
}
