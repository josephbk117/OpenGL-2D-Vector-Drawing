#include "Rectangle.h"

bool RectangleDrawable::isEditable = true;

void RectangleDrawable::draw()
{
	glColor3f(drawColour.getX(), drawColour.getY(), drawColour.getZ());

	if (isEditable)
	{
		glPointSize(5);
		glBegin(GL_POINTS);
		glVertex2i(startHotSpot.getX(), startHotSpot.getY());
		glVertex2i(endHotSpot.getX(), endHotSpot.getY());
		glEnd();
	}

	glBegin(GL_LINES);
	
	glVertex2i(startHotSpot.getX(), startHotSpot.getY());
	glVertex2i(startHotSpot.getX(), endHotSpot.getY());

	glVertex2i(startHotSpot.getX(), endHotSpot.getY());
	glVertex2i(endHotSpot.getX(), endHotSpot.getY());

	glVertex2i(endHotSpot.getX(), endHotSpot.getY());
	glVertex2i(endHotSpot.getX(), startHotSpot.getY());

	glVertex2i(endHotSpot.getX(), startHotSpot.getY());
	glVertex2i(startHotSpot.getX(), startHotSpot.getY());
	glEnd();
}

void RectangleDrawable::remove()
{
}

void RectangleDrawable::setDrawColour(Vector3 colour)
{
	drawColour = colour;
}

Vector3 RectangleDrawable::getDrawColour()
{
	return drawColour;
}

void RectangleDrawable::getHotspots(Vector2* ar[])
{
	ar[0] = &startHotSpot;
	ar[1] = &endHotSpot;
}
int RectangleDrawable::getNumberOfHotSpots()
{
	return 2;
}
RectangleDrawable::RectangleDrawable()
{
	this->startHotSpot = Vector2(0, 0);
	this->endHotSpot = Vector2(0, 0);
	drawColour = Vector3(0, 0, 0);	
}

RectangleDrawable::RectangleDrawable(Vector2 startPosition, Vector2 endPosition)
{
	this->startHotSpot = startPosition;
	this->endHotSpot = endPosition;
	drawColour = Vector3(0, 0, 0);	
}

RectangleDrawable::RectangleDrawable(Vector2 startPosition, Vector2 endPosition, Vector3 drawColour)
{
	this->startHotSpot = startPosition;
	this->endHotSpot = endPosition;
	this->drawColour = drawColour;	
}

RectangleDrawable::~RectangleDrawable()
{
}

Vector2 RectangleDrawable::getStartPosition()
{
	return startHotSpot;
}

Vector2 RectangleDrawable::getEndPosition()
{
	return endHotSpot;
}

void RectangleDrawable::setStartPosition(int x, int y)
{
	startHotSpot = Vector2(x, y);
}

void RectangleDrawable::setStartPosition(Vector2 startPosition)
{
	this->startHotSpot = startPosition;
}

void RectangleDrawable::setEndPosition(int x, int y)
{
	endHotSpot = Vector2(x, y);
}

void RectangleDrawable::setEndPosition(Vector2 endPosition)
{
	this->endHotSpot = endPosition;
}

