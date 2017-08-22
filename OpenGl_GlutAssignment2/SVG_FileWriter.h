#pragma once
#include <iostream>
#include <sstream>
#include <list>
#include "Drawable.h"
class SVG_FileWriter
{
public:

	SVG_FileWriter(std::list<Drawable> drawables);
	void outputToFile(std::string outputFilePath);
	~SVG_FileWriter();
private:
	std::list<Drawable> drawables;
};

