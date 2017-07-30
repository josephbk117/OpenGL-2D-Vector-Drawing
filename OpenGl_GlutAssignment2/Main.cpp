#include <GL/glut.h>
#include <iostream>
#include "Vector2.h"
#include "Rectangle.h"
#include "CircleDrawable.h"
#include "Drawable.h"
#include "LineDrawable.h"
#include "PolygonDrawable.h"
#include <list>
#include <iterator>

enum {
	USE_LINES = 1,
	USE_RECTS,
	USE_CIRCS,
	USE_POLYS,
	TOGGLE_POLY_ADDITIONS,
	MENU_EXIT
};

unsigned int useType = USE_LINES;
/*LineDrawable lineDraw;
RectangleDrawable rectDraw;
CircleDrawable circDraw;
PolygonDrawable polyDraw;*/

std::list<Drawable *> drawableList;
Drawable *currentDrawable;
bool continueAddingVerticesToPoly = false;

int globalSegmentCount = 10;
const unsigned int MAX_CIRCLE_SEGMENTS = 30;
const unsigned int MIN_CIRCLE_SEGMENTS = 4;

void processNormalKeys(unsigned char key, int x, int y)
{

}

void SelectFromMenu(int commandID)
{
	switch (commandID)
	{
	case USE_LINES:
		useType = USE_LINES;
		break;
	case USE_RECTS:
		useType = USE_RECTS;
		break;
	case USE_CIRCS:
		useType = USE_CIRCS;
		break;
	case USE_POLYS:
		useType = USE_POLYS;
		break;
	case TOGGLE_POLY_ADDITIONS:
		continueAddingVerticesToPoly = !continueAddingVerticesToPoly;
		break;
	case MENU_EXIT:
		exit(0);
		break;
	}
	glutPostRedisplay();
}

int BuildPopupMenu(void)
{
	int menu;
	menu = glutCreateMenu(SelectFromMenu);
	glutAddMenuEntry("USE LINES", USE_LINES);
	glutAddMenuEntry("USE RECTANGLES", USE_RECTS);
	glutAddMenuEntry("USE CIRCLES", USE_CIRCS);
	glutAddMenuEntry("USE POLYGONS", USE_POLYS);
	glutAddMenuEntry("TOGGLE POLYGON VERTEX ADDITION", TOGGLE_POLY_ADDITIONS);
	glutAddMenuEntry("Exit\tEsc", MENU_EXIT);
	return menu;
}

void mouseClicks(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON)
	{
		if (state == GLUT_DOWN)
		{
			if (useType == USE_LINES)
			{
				currentDrawable = new LineDrawable(Vector2(x, y), Vector2(0, 0));
				//lineDraw.setFirstHotSpot(Vector2(x, y));
			}
			if (useType == USE_RECTS)
			{
				currentDrawable = new RectangleDrawable(Vector2(x, y), Vector2(0, 0), Vector3(0.9f, 0.8f, 0.3f));
				//rectDraw.setStartPosition(Vector2(x, y));
			}
			if (useType == USE_CIRCS)
			{
				currentDrawable = new CircleDrawable(Vector2(x, y), 0);
				//circDraw.setCenterPosition(Vector2(x, y));
			}
			if (useType == USE_POLYS)
			{
				if (!continueAddingVerticesToPoly) // if not continue then reate new poly
				{
					currentDrawable = new PolygonDrawable();
					currentDrawable->setDrawColour(Vector3(0.8f, 0.3f, 0.6f));
					dynamic_cast<PolygonDrawable *>(currentDrawable)->addNewHotSpot(Vector2(x, y));
					continueAddingVerticesToPoly = true;
					drawableList.push_back(currentDrawable);
				}
				else
				{
					dynamic_cast<PolygonDrawable *>(currentDrawable)->addNewHotSpot(Vector2(x, y));
				}
				//polyDraw.addNewHotSpot(Vector2(x, y));
			}
		}
		if (state == GLUT_UP)
		{
			if (useType == USE_LINES)
			{
				dynamic_cast<LineDrawable *>(currentDrawable)->setLastHotSpot(Vector2(x, y));
				dynamic_cast<LineDrawable *>(currentDrawable)->setDrawColour(Vector3(0.5f, 0.8f, 0.12f));
				drawableList.push_back(currentDrawable);
				//lineDraw.setLastHotSpot(Vector2(x, y));
			}
			if (useType == USE_RECTS)
			{
				dynamic_cast<RectangleDrawable *>(currentDrawable)->setEndPosition(Vector2(x, y));
				drawableList.push_back(currentDrawable);
				//rectDraw.setEndPosition(Vector2(x, y));
			}
			if (useType == USE_CIRCS)
			{
				float radius = Vector2::Distance(dynamic_cast<CircleDrawable *>(currentDrawable)->getCircleCenter(), Vector2(x, y));
				dynamic_cast<CircleDrawable *>(currentDrawable)->setCircleRadius(radius);
				dynamic_cast<CircleDrawable *>(currentDrawable)->setDrawColour(Vector3(0, 0.5f, 1));
				drawableList.push_back(currentDrawable);
				//circDraw.setCircleRadius(Vector2::Distance(circDraw.getCircleCenter(), Vector2(x, y)));
			}
			if (useType == USE_POLYS)
			{
				//if(continueAddingVerticesToPoly)
					//dynamic_cast<PolygonDrawable *>(currentDrawable)->addNewHotSpot(Vector2(x, y));
			}
		}
	}
	if (button == 3 || button == 4)
	{
		if (useType == USE_CIRCS)
		{
			if (button == 3)
			{
				if (globalSegmentCount > MAX_CIRCLE_SEGMENTS)
					globalSegmentCount = 30;
				else
					globalSegmentCount++;
			}
			else
			{
				if (globalSegmentCount < MIN_CIRCLE_SEGMENTS)
					globalSegmentCount = MIN_CIRCLE_SEGMENTS;
				else
					globalSegmentCount--;
			}
		}
	}
}

void reshape(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	float aspect = 16.0f / 9.0f;
	/*if (w >= h) {
		gluOrtho2D(-(960 / 2) * aspect, (960 / 2) * aspect, -(960 / 2), (960 / 2));
	}
	else {
		gluOrtho2D(-(960 / 2), (960 / 2), -(960 / 2) / aspect, (960 / 2) / aspect);
	}*/
	gluOrtho2D(0, w, h, 0);
	glMatrixMode(GL_MODELVIEW);
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	/*Drawable *dr;
	RectangleDrawable rect(Vector2(0, 0), Vector2(200, 200));
	CircleDrawable circ(Vector2(0, 0), 50);
	LineDrawable ld(Vector2(100, 100), Vector2(300, 300));
	PolygonDrawable pd;

	Vector2 hotAr[] = { Vector2(-200,-200), Vector2(-300,-80),Vector2(-240,-90), Vector2(-220,-280), Vector2(-420,-350) };
	int size = sizeof(hotAr) / sizeof(hotAr[0]);
	pd.addNewHotSpotArray(hotAr, size);

	circ.setCircleSegments(12);
	dr = &circ;
	dr->setDrawColour(Vector3(0.1f, 0.7f, 0.7f));
	dr->draw();
	dr = &rect;
	dr->setDrawColour(Vector3(0.8f, 0.1f, 0.4f));
	dr->draw();

	dr = &ld;
	dr->setDrawColour(Vector3(0.4f, 0.9f, 0.7f));
	dr->draw();

	dr = &pd;
	dr->setDrawColour(Vector3(0.7f, 0.9f, 0.4f));
	dr->draw();*/
	//circDraw.setCircleSegments(globalSegmentCount);
	for (std::list<Drawable *>::iterator it = drawableList.begin(); it != drawableList.end(); it++)
	{
		(*it)->draw();
	}

	glutPostRedisplay();
	glutSwapBuffers();
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(960, 540);
	glutCreateWindow("Open GL");
	glEnable(GL_DEPTH_TEST);
	glutMouseFunc(mouseClicks);

	/*lineDraw.setDrawColour(Vector3(0.6f, 0.9f, 0.2f));
	rectDraw.setDrawColour(Vector3(0.2f, 0.7f, 0.9f));
	circDraw.setDrawColour(Vector3(0.9f, 0.7f, 0.4f));
	polyDraw.setDrawColour(Vector3(0.9f, 0.2f, 0.9f));

	drawableList.push_back(&lineDraw);
	drawableList.push_back(&rectDraw);
	drawableList.push_back(&circDraw);
	drawableList.push_back(&polyDraw);*/

	glutDisplayFunc(display);
	glutReshapeFunc(reshape);

	BuildPopupMenu();
	glutAttachMenu(GLUT_RIGHT_BUTTON);

	glutKeyboardFunc(processNormalKeys);
	glutMainLoop();
	
	return 0;
}
