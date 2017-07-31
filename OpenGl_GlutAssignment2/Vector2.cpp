#include "Vector2.h"
#include <math.h>
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
float Vector2::Distance(Vector2 a, Vector2 b)
{
	float xDelta = a.getX() - b.getX();
	float yDelta = a.getY() - b.getY();
	return sqrt(xDelta*xDelta + yDelta*yDelta);
}
Vector2::~Vector2()
{
}
