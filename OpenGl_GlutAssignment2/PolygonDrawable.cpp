#include "PolygonDrawable.h"

bool PolygonDrawable::isEditable = true;

void PolygonDrawable::draw()
{
	if (isEditable)
	{
		glPointSize(5);
		glBegin(GL_POINTS);
		glColor3f(drawColour.getX() + 0.3f, drawColour.getY() + 0.1f, drawColour.getZ() + 0.1f);
		for (std::list<Vector2>::iterator it = hotSpotList.begin(); it != hotSpotList.end(); it++)
		{
			glVertex2i(it->getX(), it->getY());
		}
		glEnd();
	}

	glColor3f(drawColour.getX(), drawColour.getY(), drawColour.getZ());
	glBegin(GL_LINES);
	for (int i = 1; i < hotSpotCount; i++)
	{
		glVertex2i(std::next(hotSpotList.begin(), i)->getX(), std::next(hotSpotList.begin(), i)->getY());
		glVertex2i(std::next(hotSpotList.begin(), i - 1)->getX(), std::next(hotSpotList.begin(), i - 1)->getY());
	}
	if (hotSpotCount > 2)
	{
		glVertex2i(std::next(hotSpotList.begin(), 0)->getX(), std::next(hotSpotList.begin(), 0)->getY());
		glVertex2i(std::next(hotSpotList.begin(), hotSpotCount - 1)->getX(), std::next(hotSpotList.begin(), hotSpotCount - 1)->getY());
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

void PolygonDrawable::getHotspots(Vector2* ar[])
{
	int cnt = 0;
	for (std::list<Vector2>::iterator it = hotSpotList.begin(); it != hotSpotList.end(); it++)
	{
		ar[cnt] = &(*it);
		cnt++;
	}
}

int PolygonDrawable::getNumberOfHotSpots()
{
	return hotSpotCount;
}

PolygonDrawable::PolygonDrawable()
{
	hotSpotCount = 0;
}
PolygonDrawable::~PolygonDrawable()
{
}

void PolygonDrawable::addNewHotSpot(Vector2 hotSpot)
{
	hotSpotCount++;
	hotSpotList.push_back(hotSpot);
}

void PolygonDrawable::addNewHotSpotArray(Vector2* hotSpotArray, int size)
{
	for (int i = 0; i < size; i++)
	{
		hotSpotCount++;
		hotSpotList.push_back(hotSpotArray[i]);
	}
}
