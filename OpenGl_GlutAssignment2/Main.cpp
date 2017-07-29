#include <GL/glut.h>
#include <iostream>
#include "Vector2.h"
#include "Rectangle.h"
#include "CircleDrawable.h"
#include "Drawable.h"

enum {
	USE_LINES = 1,
	USE_RECTS,
	USE_POLYS,
	MENU_EXIT
};

unsigned int useType = USE_LINES;

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
	glutAddMenuEntry("USE POLYGONS", USE_POLYS);
	glutAddMenuEntry("Exit\tEsc", MENU_EXIT);
	return menu;
}

void reshape(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, w, 0, h);
	glMatrixMode(GL_MODELVIEW);
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	Drawable *dr;
	RectangleDrawable rect(Vector2(30, 60), Vector2(140, 330));
	CircleDrawable circ(Vector2(85, 70), 50);
	circ.setCircleSegments(12);
	dr = &rect;
	dr->setDrawColour(Vector3(0.8f, 0.1f, 0.4f));	
	dr->draw();
	dr = &circ;
	dr->setDrawColour(Vector3(0.1f, 0.7f, 0.7f));
	dr->draw();
	
	glutPostRedisplay();
	glutSwapBuffers();
}

int main(int argc, char **argv)
{

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(16*60, 9*60);
	glutCreateWindow("Open GL");
	glEnable(GL_DEPTH_TEST);

	glutDisplayFunc(display);
	glutReshapeFunc(reshape);

	BuildPopupMenu();
	glutAttachMenu(GLUT_RIGHT_BUTTON);

	glutKeyboardFunc(processNormalKeys);
	glutMainLoop();
	return 0;
}
