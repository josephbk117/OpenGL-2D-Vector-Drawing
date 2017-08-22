#include "SVG_FileWriter.h"


SVG_FileWriter::SVG_FileWriter(std::list<Drawable *> drawables)
{
	this->drawables = drawables;
}

void SVG_FileWriter::outputToFile(std::string outputFilePath)
{
	std::ofstream file(outputFilePath);
	if (file.is_open())
	{
		file << "<?xml version=\"1.0\" encoding=\"UTF-8\" ?>";
		file << "<svg xmlns = \"http://www.w3.org/2000/svg\" version = \"1.1\">";
		for (std::list<Drawable *>::iterator it = drawables.begin(); it != drawables.end(); it++)
		{
			int count = (*it)->getNumberOfHotSpots();
			Vector2* vec[150];
			(*it)->getHotspots(vec);
			Vector3 colorVal = (*it)->getDrawColour();
			//stroke = "rgb(190,50,120)"
			std::string color = "rgb(" + std::to_string(colorVal.getX()) + "," + std::to_string(colorVal.getY()) + "," + std::to_string(colorVal.getZ()) + ")";
			if (typeid(**it) == typeid(LineDrawable))
			{
				//<line x1="50" y1="50" x2="200" y2="200" stroke="blue" stroke-width="4" />
				int x1, y1, x2, y2;
				x1 = vec[0]->getX();
				y1 = vec[0]->getY();
				x2 = vec[1]->getX();
				y2 = vec[1]->getY();
				file << "<line x1=\"" + std::to_string(x1) + "\" y1=\"" + std::to_string(y1) + "\" x2 =\"" + std::to_string(x2) + "\" y2 = \"" + std::to_string(y2) + "\" stroke=\"" + color + "\" stroke-width =\"4\"/>";
			}
		}
		file << "</svg>";
		file.close();
	}
	else
		std::cout << "Unable to open file";
}

SVG_FileWriter::~SVG_FileWriter()
{
}
