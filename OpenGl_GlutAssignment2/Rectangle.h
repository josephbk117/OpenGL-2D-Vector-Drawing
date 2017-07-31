#pragma once
#include "Drawable.h"
#include "Vector2.h"
#include "GL\glut.h"
#include "Vector3.h"
class RectangleDrawable : public Drawable
{
public:
	static bool isEditable;
	void Drawable::draw();
	void Drawable::remove();
	void Drawable::setDrawColour(Vector3 colour);
	Vector3 Drawable::getDrawColour();
	RectangleDrawable();
	RectangleDrawable(Vector2 startPosition, Vector2 endPosition);
	RectangleDrawable(Vector2 startPosition, Vector2 endPosition, Vector3 drawColour);
	~RectangleDrawable();
	Vector2 getStartPosition();
	Vector2 getEndPosition();
	void setStartPosition(int x,int y); 
	void setStartPosition(Vector2 startPosition);
	void setEndPosition(int x,int y);
	void setEndPosition(Vector2 endPosition);
private:

	Vector2 startHotSpot, endHotSpot;
	Vector3 drawColour;
};

