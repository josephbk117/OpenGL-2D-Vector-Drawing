#pragma once
#include "Drawable.h"
#include <GL\glut.h>
#include <list>
#include <algorithm>
#include <iterator>
#include "Vector2.h"
class PolygonDrawable : public Drawable
{
public:
	void Drawable::draw();
	void Drawable::remove();
	void Drawable::setDrawColour(Vector3 colour);
	Vector3 Drawable::getDrawColour();
	PolygonDrawable();
	~PolygonDrawable();
	void addNewHotSpot(Vector2 hotSpot);
	void addNewHotSpotArray(Vector2* hotSpot, int size);

private:
	std::list<Vector2> hotSpots;
	Vector3 drawColour;
};

