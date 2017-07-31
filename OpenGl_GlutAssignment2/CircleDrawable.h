#pragma once
#include "Drawable.h"
#include "GL\glut.h"
#include <math.h>
class CircleDrawable : public Drawable
{
public:
	static bool isEditable;
	void Drawable::draw();
	void Drawable::remove();
	void Drawable::setDrawColour(Vector3 colour);
	Vector3 Drawable::getDrawColour();
	CircleDrawable();
	CircleDrawable(Vector2 centerPosition, float radius);
	void setCenterPosition(Vector2 centerPosition);
	void setCircleRadius(float radius);
	void setCircleSegments(unsigned int segments);
	int getCircleSegmentNumber();
	Vector2 getCircleCenter();
	~CircleDrawable();
private:
	Vector2 centerPosition;
	Vector2 outterHotSpot;
	Vector3 drawColour;
	float radius;
	int segments;
};

