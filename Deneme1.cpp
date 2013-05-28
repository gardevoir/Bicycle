// Deneme1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <math.h>
#include "Bicycle.h"
#include "Road.h"

float x_axis = 0, y_axis = 0, z_axis = 0, cam_x_axis = 0;
Bicycle *b = new Bicycle();
Road *r = new Road();

void init(void)
{
	glClearColor (0.0, 1, 1, 0.3);
	glShadeModel (GL_FLAT);
}

void display(void)
{
	GLUquadric *quad = gluNewQuadric();

	glClear (GL_COLOR_BUFFER_BIT);
	glColor3f (1.0, 1.0, 1.0);
	glLoadIdentity ();
	gluLookAt (x_axis, y_axis, 40.0, cam_x_axis, 0.0, 0.0, 0.0, 1.0, 1.0);
	glScalef (1, 1, 1);

	r->draw_road();
	glColor3f(0, 0, 0);
	b->draw_bicycle();
	
	glFlush ();
}

void reshape (int w, int h)
{
	glViewport (0, 0, (GLsizei) w, (GLsizei) h);
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();
	glFrustum (-1.0, 1.0, -1.0, 1.0, 1.5, 70.0);
	glMatrixMode (GL_MODELVIEW);
}

void keyboard(unsigned char key, int x, int y)
{
	switch(key)
	{
	case 'a':
		b->go_back();
			break;
		

	case 'd':
		b->go_forward();
			break;

	case 'w':
			y_axis += 0.5;
			glutPostRedisplay();
		break;
	case 's':
			y_axis -= 0.5;
			glutPostRedisplay();
		break;
	
	case 'q':
			x_axis += 0.5;
			glutPostRedisplay();
		break;

	case 'e':
			x_axis -= 0.5;
			glutPostRedisplay();
		break;
		
	case 'r':
		x_axis = 0;
		y_axis = 0;
		glutPostRedisplay();
		break;
	case 'y':
		b->reset();
		break;
	
	case 'l':
		cam_x_axis += 0.5;
		glutPostRedisplay();
		break;
	case 'k':
		cam_x_axis -= 0.5;
		glutPostRedisplay();
		break;
	}
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (500, 500);
	glutInitWindowPosition (100, 100);
	glutCreateWindow (argv[0]);
	init ();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}

