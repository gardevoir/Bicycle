// Deneme1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <math.h>

void init(void)
{
	glClearColor (0.0, 0.0, 0.0, 0.0);
	glShadeModel (GL_FLAT);
}

void display(void)
{
	GLUquadric *quad = gluNewQuadric();

	glClear (GL_COLOR_BUFFER_BIT);
	glColor3f (1.0, 1.0, 1.0);
	glLoadIdentity ();
	gluLookAt (0.0, 0.0, 40.0, 0.0, 0.0, 0.0, 0.0, 1.0, 1.0);
	glScalef (1, 1, 1);
	glPushMatrix();//sol teker
		glTranslatef(-13, 0, 0);
		glutSolidTorus(0.5,5.0,10,50);
	glPopMatrix();
	glPushMatrix();//sag teker
		glTranslatef(13, 0, 0);
		glutSolidTorus(0.5,5.0,10,50);
	glPopMatrix();
	glPushMatrix();
		glTranslatef(-1, -2, 1);
		//gluCylinder(quad, 0, 1, 1, 30, 30);
		gluDisk(quad, 0, 1, 30, 30);
	glPopMatrix();
	glPushMatrix();
		glTranslatef(-1, -2, -1);
		//gluCylinder(quad, 0, 1, 1, 30, 30);
		gluDisk(quad, 0, 1, 30, 30);
	glPopMatrix();
	glPushMatrix();//3. cubuk
		glRotatef(90, 0, 1, 0);
		glTranslatef(1, 0, -13);
		glRotatef(9.462, 1, 0, 0);
		gluCylinder(quad, 0.4, 0.4, 12.165, 30, 30);
	glPopMatrix();
	glPushMatrix();
		glRotatef(90, 0, 1, 0);
		glTranslatef(-1, 0, -13);
		glRotatef(9.462, 1, 0, 0);
		gluCylinder(quad, 0.4, 0.4, 12.165, 30, 30);
	glPopMatrix();
	glPushMatrix();//4. cubuk
		glRotatef(90, 0, 1, 0);
		glTranslatef(-1, 0, -13);
		glRotatef(-45, 1, 0, 0);
		gluCylinder(quad, 0.4, 0.4, 9.899, 30, 30);
	glPopMatrix();
	glPushMatrix();
		glRotatef(90, 0, 1, 0);
		glTranslatef(1, 0, -13);
		glRotatef(-45, 1, 0, 0);
		gluCylinder(quad, 0.4, 0.4, 9.899, 30, 30);
	glPopMatrix();
	glPushMatrix();//5. cubuk
		glRotatef(90, 0, 1, 0);
		glTranslatef(0, -2, -1);
		glRotatef(-187+68.256, 1, 0, 0);
		gluCylinder(quad, 0.4, 0.4, 10.298, 30, 30);
	glPopMatrix();
	glPushMatrix();//6. cubuk
		glRotatef(90, 0, 1, 0);
		glTranslatef(0, -2, -1);
		glRotatef(-90+50.710, 1, 0, 0);
		gluCylinder(quad, 0.4, 0.4, 14.212, 30, 30);
	glPopMatrix();
	glPushMatrix();//uzun cubuk
		glRotatef(90, 0, 1, 0);
		glTranslatef(0, 7, -6);
		gluCylinder(quad, 0.4, 0.4 ,16, 30, 30);
	glPopMatrix();//sag tekerlegin cubugu
	glPushMatrix();
		glRotatef(90, 0, 1, 0);
		glTranslatef(-1, 0, 13);
		glRotatef(-180+66.801, 1, 0, 0);
		gluCylinder(quad, 0.4, 0.4 ,7.615, 30, 30);
	glPopMatrix();
	glPushMatrix();
		glRotatef(90, 0, 1, 0);
		glTranslatef(1, 0, 13);
		glRotatef(-113.199, 1, 0, 0);
		gluCylinder(quad, 0.4, 0.4 ,7.615, 30, 30);
	glPopMatrix();
	glPushMatrix();//gidon ilk parca
		glRotatef(90, 0, 1, 0);
		glTranslatef(0, 7, 10);
		glRotatef(-113.199, 1, 0, 0);
		gluCylinder(quad, 0.4, 0.4, sqrtf(8), 30, 30);
	glPopMatrix();
	glPushMatrix();//gidon 2. parca
		glTranslatef(9, 10, -2.5);
		gluCylinder(quad, 0.4, 0.4, 5, 30, 30);
	glPopMatrix();
	/*glPushMatrix();//gidon 2. parca
		glRotatef(90, 0, 1, 0);
		glTranslatef(0, 9, 8);
		glRotatef(-26.565, 1, 0, 0);
		gluCylinder(quad, 0.4, 0.4, sqrtf(5), 30, 30);
	glPopMatrix();
	glPushMatrix();//gidon 3. parca
		glRotatef(90, 0, 1, 0);
		glTranslatef(0, 10, 10);
		glRotatef(-135, 1, 0, 0);
		gluCylinder(quad, 0.4, 0.4, sqrtf(2), 30, 30);
	glPopMatrix();
	glPushMatrix();//gidon son parca
		glRotatef(90, 0, 1, 0);
		glTranslatef(-1, 11, 9);
		gluCylinder(quad, 0.4, 0.4, 2, 30, 30);
	glPopMatrix();
	glPushMatrix();//gidon son parca
		glRotatef(90, 0, 1, 0);
		glTranslatef(1, 11, 9);
		gluCylinder(quad, 0.4, 0.4, 2, 30, 30);
	glPopMatrix();*/
	glPushMatrix();//selenin demiri
		glRotatef(90, 0, 1, 0);
		glTranslatef(0, 7, -6);
		glRotatef(-187+68.256, 1, 0, 0);
		gluCylinder(quad, 0.4, 0.4, sqrtf(5), 30, 30);
	glPopMatrix();
	glPushMatrix();//sele
		glRotatef(90, 1, 0, 0);
		glTranslatef(-7, 0, -10);
		gluCylinder(quad, 2, 2, 1, 30, 30);
	glPopMatrix();
	glPushMatrix();//sol teker susu
		glRotatef(90, 0, 1, 0);
		glTranslatef(0, 0, -13);
		for(int i = 1; i < 9; i++){
			glRotatef(45, 1, 0, 0);
			gluCylinder(quad, 0.2, 0.2 , 5.0, 30, 30);
		}
	glPopMatrix();
	glPushMatrix();//sag teker susu
		glRotatef(90, 0, 1, 0);
		glTranslatef(0, 0, 13);
		for(int i = 1; i < 9; i++){
			glRotatef(45, 1, 0, 0);
			gluCylinder(quad, 0.2, 0.2 , 5.0, 30, 30);
		}
	glPopMatrix();
	glPushMatrix();//sag pedal
		glRotatef(90, 0, 1, 0);
		glTranslatef(2, -2, -1);
		glRotatef(90, 1, 0, 0);
		gluCylinder(quad, 0.3, 0.3, 3, 30, 30);
	glPopMatrix();
	glPushMatrix();//sol pedal
		glRotatef(90, 0, 1, 0);
		glTranslatef(-2, -2, -1);
		glRotatef(360-90, 1, 0, 0);
		gluCylinder(quad, 0.3, 0.3, 3, 30, 30);

	
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
	glutMainLoop();
	return 0;
}