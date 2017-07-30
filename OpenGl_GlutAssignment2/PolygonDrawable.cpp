#include "PolygonDrawable.h"

void PolygonDrawable::draw()
{
	glPointSize(5);
	glBegin(GL_POINTS);
	glColor3f(drawColour.getX() + 0.3f, drawColour.getY() + 0.1f, drawColour.getZ() + 0.1f);
	for (std::list<Vector2>::iterator it = hotSpots.begin(); it != hotSpots.end(); it++)
	{
		glVertex2i(it->getX(), it->getY());
	}
	glEnd();

	glColor3f(drawColour.getX(), drawColour.getY(), drawColour.getZ());
	glBegin(GL_POLYGON);

	for (std::list<Vector2>::iterator it = hotSpots.begin(); it != hotSpots.end(); it++)
	{
		glVertex2i(it->getX(), it->getY());
	}
	glEnd();	
}
void PolygonDrawable::setDrawColour(Vector3 colour)
{
	drawColour = colour;
}
Vector3 PolygonDrawable::getDrawColour()
{
	return drawColour;
}

void PolygonDrawable::remove()
{

}

PolygonDrawable::PolygonDrawable()
{
}
PolygonDrawable::~PolygonDrawable()
{
}

void PolygonDrawable::addNewHotSpot(Vector2 hotSpot)
{
	hotSpots.push_back(hotSpot);
}

void PolygonDrawable::addNewHotSpotArray(Vector2* hotSpotArray, int size)
{
	for (int i = 0; i < size; i++)
	{
		hotSpots.push_back(hotSpotArray[i]);
	}
}
