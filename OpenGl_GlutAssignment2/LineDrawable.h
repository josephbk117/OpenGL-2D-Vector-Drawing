#pragma once
#include "Drawable.h"
#include <GL\glut.h>
#include <vector>
class LineDrawable : public Drawable
{
public:
	static bool isEditable;
	void Drawable::draw();
	void Drawable::remove();
	void Drawable::setDrawColour(Vector3 colour);
	Vector3 Drawable::getDrawColour();
	void Drawable::getHotspots(Vector2* ar[]);
	int Drawable::getNumberOfHotSpots();
	LineDrawable();
	LineDrawable(Vector2 hotspot1, Vector2 hotspot2);
	~LineDrawable();
	void setHotSpots(Vector2 hotspot1, Vector2 hotspot2);
	void setFirstHotSpot(Vector2 spot);
	void setLastHotSpot(Vector2 spot);
	
private:
	Vector2 hotSpot1, hotSpot2;
	Vector3 drawColor;
};

