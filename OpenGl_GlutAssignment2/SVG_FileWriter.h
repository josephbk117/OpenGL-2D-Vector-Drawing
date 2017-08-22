#pragma once
#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include "Drawable.h"
#include "LineDrawable.h"
#include "Rectangle.h"
#include "CircleDrawable.h"
#include "PolygonDrawable.h"
class SVG_FileWriter
{
public:

	SVG_FileWriter(std::list<Drawable *> drawables);
	void outputToFile(std::string outputFilePath);
	~SVG_FileWriter();
private:
	std::list<Drawable *> drawables;
};

