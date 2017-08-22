#include "SVG_FileWriter.h"


SVG_FileWriter::SVG_FileWriter(std::list<Drawable> drawables)
{
	this->drawables = drawables;
}

void SVG_FileWriter::outputToFile(std::string outputFilePath)
{
	for (std::list<Drawable>::iterator it = drawables.begin(); it != drawables.end(); it++)
	{
		//if (typeid(**it) == typeid(CircleDrawable))
			//dynamic_cast<CircleDrawable *>(*it)->setCircleSegments(globalSegmentCount);
		(*it)->draw();
	}
}

SVG_FileWriter::~SVG_FileWriter()
{
}
