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
	static bool isEditable;
	void Drawable::draw();
	void Drawable::remove();
	void Drawable::setDrawColour(Vector3 colour);
	Vector3 Drawable::getDrawColour();
	void Drawable::getHotspots(Vector2* ar[]);
	int Drawable::getNumberOfHotSpots();
	PolygonDrawable();
	~PolygonDrawable();
	void addNewHotSpot(Vector2 hotSpot);
	void addNewHotSpotArray(Vector2* hotSpot, int size);

private:
	int hotSpotCount;
	std::list<Vector2> hotSpotList;
	Vector3 drawColour;
};

