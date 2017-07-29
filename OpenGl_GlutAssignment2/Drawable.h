#pragma once
#include "Vector3.h"
class Drawable
{
public:
	Drawable();
	virtual ~Drawable();
	virtual void draw() =0;
	virtual void remove() = 0;
	virtual void setDrawColour(Vector3 colour) = 0;
	virtual Vector3 getDrawColour() = 0;
};

