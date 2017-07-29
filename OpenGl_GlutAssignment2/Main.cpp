#include <GL/glut.h>
#include <iostream>
#include "Vector2.h"
#include "Rectangle.h"
#include "CircleDrawable.h"
#include "Drawable.h"
#include "LineDrawable.h"
#include "PolygonDrawable.h"

enum {
	USE_LINES = 1,
	USE_RECTS,
	USE_CIRCS,
	USE_POLYS,
	MENU_EXIT
};

unsigned int useType = USE_LINES;
LineDrawable lineDraw;
RectangleDrawable rectDraw;
CircleDrawable circDraw;
PolygonDrawable polyDraw;

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
				lineDraw.setFirstHotSpot(Vector2(x, y));
			}
			if (useType == USE_RECTS)
			{
				rectDraw.setStartPosition(Vector2(x, y));
			}
			if (useType == USE_CIRCS)
			{
				circDraw.setCenterPosition(Vector2(x, y));
			}
			if (useType == USE_POLYS)
			{
				polyDraw.addNewHotSpot(Vector2(x, y));
			}
		}
		if (state == GLUT_UP)
		{
			if (useType == USE_LINES)
			{
				lineDraw.setLastHotSpot(Vector2(x, y));
			}
			if (useType == USE_RECTS)
			{
				rectDraw.setEndPosition(Vector2(x, y));
			}
			if (useType == USE_CIRCS)
			{
				circDraw.setCircleRadius(Vector2::Distance(circDraw.getCircleCenter(), Vector2(x, y)));
			}
			if (useType == USE_POLYS)
			{
				
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
	lineDraw.setDrawColour(Vector3(0.6f, 0.9f, 0.2f));
	lineDraw.draw();

	rectDraw.setDrawColour(Vector3(0.2f, 0.7f, 0.9f));
	rectDraw.draw();

	circDraw.setDrawColour(Vector3(0.9f, 0.7f, 0.4f));
	circDraw.draw();

	polyDraw.setDrawColour(Vector3(0.9f, 0.2f, 0.9f));
	polyDraw.draw();

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

	glutDisplayFunc(display);
	glutReshapeFunc(reshape);

	BuildPopupMenu();
	glutAttachMenu(GLUT_RIGHT_BUTTON);

	glutKeyboardFunc(processNormalKeys);
	glutMainLoop();
	return 0;
}
