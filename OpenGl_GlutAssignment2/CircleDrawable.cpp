#include "CircleDrawable.h"
#define PI 3.14159265

bool CircleDrawable::isEditable = true;
void CircleDrawable::draw()
{
	float incValue = (float)(2.0f * PI) / (float)segments;
	glColor3f(drawColour.getX(), drawColour.getY(), drawColour.getZ());
	float radius = Vector2::Distance(centerPosition, outterHotSpot);

	if (isEditable)
	{
		glPointSize(5);
		glBegin(GL_POINTS);
		glVertex2i(centerPosition.getX(), centerPosition.getY());
		glVertex2i(centerPosition.getX(), centerPosition.getY() + radius);
		glEnd();

		glBegin(GL_LINES);
		glVertex2i(centerPosition.getX(), centerPosition.getY());
		glVertex2i(centerPosition.getX(), centerPosition.getY() + radius);
		glEnd();
	}

	glBegin(GL_LINES);
	for (int i = 1; i < segments; i++)
	{
		int x = centerPosition.getX() + (sin(i * incValue) * radius);
		int y = centerPosition.getY() + (cos(i * incValue) * radius);

		int x1 = centerPosition.getX() + (sin((i - 1) * incValue) * radius);
		int y1 = centerPosition.getY() + (cos((i - 1) * incValue) * radius);
		glVertex2i(x, y);
		glVertex2i(x1, y1);
	}
	int x = centerPosition.getX() + (sin(0 * incValue) * radius);
	int y = centerPosition.getY() + (cos(0 * incValue) * radius);

	int x1 = centerPosition.getX() + (sin((segments - 1) * incValue) * radius);
	int y1 = centerPosition.getY() + (cos((segments - 1) * incValue) * radius);

	glVertex2i(x, y);
	glVertex2i(x1, y1);
	glEnd();

}
void CircleDrawable::remove()
{

}
void CircleDrawable::setDrawColour(Vector3 colour)
{
	this->drawColour = colour;
}

Vector3 CircleDrawable::getDrawColour()
{
	return this->drawColour;
}

void CircleDrawable::getHotspots(Vector2* ar[])
{
	ar[0] = &centerPosition;
	ar[1] = &outterHotSpot;
}
int CircleDrawable::getNumberOfHotSpots()
{
	return 2;
}

CircleDrawable::CircleDrawable()
{
	this->centerPosition = Vector2(0, 0);
	this->radius = 1;
	this->segments = 10;
	this->outterHotSpot = Vector2(0, radius);
}

CircleDrawable::CircleDrawable(Vector2 centerPosition, float radius)
{
	this->centerPosition = centerPosition;
	this->radius = radius;
	this->segments = 10;
	this->outterHotSpot = Vector2(centerPosition.getX(), centerPosition.getY() + radius);
}

void CircleDrawable::setCenterPosition(Vector2 centerPosition)
{
	this->centerPosition = centerPosition;
	this->outterHotSpot = Vector2(centerPosition.getX(), centerPosition.getY() + radius);
}

void CircleDrawable::setOutterPosition(Vector2 outterPosition)
{
	float radius = Vector2::Distance(centerPosition, outterPosition);
	setCircleRadius(radius);
}

void CircleDrawable::setCircleRadius(float radius)
{
	this->radius = radius;
	this->outterHotSpot = Vector2(centerPosition.getX(), centerPosition.getY() + radius);
}

void CircleDrawable::setCircleSegments(unsigned int segments)
{
	this->segments = segments;
}

int CircleDrawable::getCircleSegmentNumber()
{
	return segments;
}

Vector2 CircleDrawable::getCircleCenter()
{
	return centerPosition;
}

CircleDrawable::~CircleDrawable()
{
}
