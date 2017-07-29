#include "Vector2.h"
//By default it will be int 0
Vector2::Vector2()
{
	this->x = 0;
	this->y = 0;
}
Vector2::Vector2(int x, int y)
{
	this->x = x;
	this->y = y;
}
int Vector2::getX()
{
	return x;
}
int Vector2::getY()
{
	return y;
}
Vector2::~Vector2()
{
}
