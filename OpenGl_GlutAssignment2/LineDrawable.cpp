#include "LineDrawable.h"

bool LineDrawable::isEditable = true;

void LineDrawable::draw()
{
	glColor3f(drawColor.getX(), drawColor.getY(), drawColor.getZ());
	if (isEditable)
	{
		glPointSize(5);
		glBegin(GL_POINTS);
		glVertex2i(hotSpot1.getX(), hotSpot1.getY());
		glVertex2i(hotSpot2.getX(), hotSpot2.getY());
		glEnd();
	}
	
	glBegin(GL_LINES);
	glVertex2i(hotSpot1.getX(), hotSpot1.getY());
	glVertex2i(hotSpot2.getX(), hotSpot2.getY());
	glEnd();	
}

void LineDrawable::setDrawColour(Vector3 colour)
{
	drawColor = colour;
}
void LineDrawable::remove()
{

}
Vector3 LineDrawable::getDrawColour()
{
	return drawColor;
}
LineDrawable::LineDrawable()
{
	this->hotSpot1 = Vector2(0, 0);
	this->hotSpot2 = Vector2(0, 0);
}

LineDrawable::LineDrawable(Vector2 hotSpot1, Vector2 hotSpot2)
{
	this->hotSpot1 = hotSpot1;
	this->hotSpot2 = hotSpot2;
}

LineDrawable::~LineDrawable()
{
}

void LineDrawable::setHotSpots(Vector2 hotSpot1, Vector2 hotSpot2)
{
	this->hotSpot1 = hotSpot1;
	this->hotSpot2 = hotSpot2;
}

void LineDrawable::setFirstHotSpot(Vector2 spot)
{
	hotSpot1 = spot;
}

void LineDrawable::setLastHotSpot(Vector2 spot)
{
	hotSpot2 = spot;
}
