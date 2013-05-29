#include "stdafx.h"
#include "Bicycle.h"
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <math.h>


Bicycle::Bicycle(): disc_inner_radius(0), disc_outer_radius(1), slices(30),body_radius(0.4)
{
	x_axis = 0;
	y_axis = 0;
	z_axis = 0;
	wheel_angle = 0;
	handle_angle = 0;
	pedal_angle = 90;
	q = gluNewQuadric();
}


Bicycle::~Bicycle(void)
{
}

void Bicycle::draw_bicycle()
{
	glPushMatrix();
	glTranslatef(x_axis, y_axis, z_axis);//ana matris, hareket icin

	glPushMatrix();//sol teker
		draw_wheel(-13, 0, 0, wheel_angle);
	glPopMatrix();
	glPushMatrix();//sag teker
		draw_wheel(13, 0, 0, wheel_angle);
	glPopMatrix();
	//teker koprusu
	glPushMatrix();
		draw_bridge(q, -13, 0, 0);
	glPopMatrix();
	glPushMatrix();
		draw_bridge(q, 13, 0, 0);
	glPopMatrix();
	//sol asagý kisim
	glPushMatrix();//-z yönündeki kisim
		draw_left_lower_wheel_body(q, 1, 0, -13);
	glPopMatrix();
	glPushMatrix();//+z yönündeki kisim
		draw_left_lower_wheel_body(q, -1, 0, -13);
	glPopMatrix();
	//sol ust kisim
	glPushMatrix();//-z yönündeki kisim
		draw_left_upper_wheel_body(q, -1, 0, -13, 3);
	glPopMatrix();
	glPushMatrix();//+z yönündeki kisim
		draw_left_upper_wheel_body(q, 1, 0, -13, -3);
	glPopMatrix();
	//sag kisim
	glPushMatrix();//-z yönündeki kisim
		draw_right_wheel_body(q, -1, 0, 13, 3
			);
	glPopMatrix();
	glPushMatrix();//+z yönündeki kisim
		draw_right_wheel_body(q, 1, 0, 13, -3);
	glPopMatrix();
	//orta kisim
	glPushMatrix();//orta sol kisim
		draw_mid_left_body(q, 0, -2, -1);
	glPopMatrix();
	glPushMatrix();//orta sag kisim
		draw_mid_right_body(q, 0, -2, -1);
	glPopMatrix();
	glPushMatrix();//mid upper part
		draw_mid_upper_body(q, 0, 7, -6);
	glPopMatrix();
	//gidon
	glPushMatrix();//gidonun demiri
		draw_handlebar_body(q, 0, 7, 10);
	glPopMatrix();
	glPushMatrix();//gidonun 2. demiri
		draw_handlebar_handle(q, 9, 10, -2.5);
	glPopMatrix();
	//gidonun tutacaklari
	glPushMatrix();//+z kismi
		draw_handlebar_handle2(q, 2, 10.5, 9);
	glPopMatrix();
	glPushMatrix();//-z kismi
		draw_handlebar_handle2(q, -3, 10.5, 9);
	glPopMatrix();
	//sele
	glPushMatrix();//sele demiri
		draw_saddle_body(q, 0, 7, -6);
	glPopMatrix();
	glPushMatrix();//selenin oturagi
		draw_saddle(q, -7, 0, -10);
	glPopMatrix();
	//diskler
	glPushMatrix();//+z kismi
		draw_disc(q, -1, -2, 1.5);
	glPopMatrix();
	glPushMatrix();//-z kismi
		draw_disc(q, -1, -2, -1.5);
	glPopMatrix();
	//pedal
	glPushMatrix();//+z kismi
		draw_pedal_body(q, 1, -2, -1, pedal_angle);
	glPopMatrix();
	glPushMatrix();//-z kismi
		draw_pedal_body(q, -1, -2, -1, 180+pedal_angle);
	glPopMatrix();
	glPopMatrix();
}


//private 


void Bicycle::draw_wheel(int x, int y, int z, double angle)
{
	glTranslatef(x, y, z);
	glutSolidTorus(0.5,5.0,10,50);

	glRotatef(90, 0, 1, 0);
	glColor3f(0.5, 0, 0.5);
	for(int i = 1; i < 9; i++){
		glPushMatrix();
		glRotatef(angle + i*45, 1, 0, 0);
		gluCylinder(q, 0.2, 0.2, 4.5, slices, slices);
		glPopMatrix();
	}
	glColor3f(0, 0, 0);
}

void Bicycle::draw_bridge(GLUquadric *q, int x, int y, int z)
{
	glTranslatef(x, y, z);
	gluCylinder(q, 0.3, 0.3, 2, slices, slices);
}

void Bicycle::draw_disc(GLUquadric *q,int x, int y, int z)
{
	glTranslatef(x, y, z);
	gluDisk(q, disc_inner_radius, disc_outer_radius, slices, slices);
}

void Bicycle::draw_left_lower_wheel_body(GLUquadric *q, int x, int y, int z)
{
	glRotatef(90, 0, 1, 0);
	glTranslatef(x, y, z);
	glRotatef(9.462, 1, 0, 0);
	gluCylinder(q, body_radius, body_radius, 12.165, slices, slices);
}

void Bicycle::draw_left_upper_wheel_body(GLUquadric *q, int x, int y, int z, int axis)
{
	glRotatef(90, 0, 1, 0);
	glTranslatef(x, y, z);
	glRotatef(-45, 1, 0, 0);
	glRotatef(axis, 0, 1, 0);
	gluCylinder(q, body_radius, body_radius, 9.899, slices, slices);
}

void Bicycle::draw_right_wheel_body(GLUquadric *q, int x, int y, int z, int axis)
{
	glRotatef(90, 0, 1, 0);
	glTranslatef(x, y, z);
	glRotatef(-180+66.801, 1, 0, 0);
	glRotatef(axis, 0, 1, 0);
	gluCylinder(q, body_radius, body_radius, 7.615, slices, slices);
}

void Bicycle::draw_mid_left_body(GLUquadric *q, int x, int y, int z)
{
	glRotatef(90, 0, 1, 0);
	glTranslatef(x, y, z);
	glRotatef(-187+68.256, 1, 0, 0);
	gluCylinder(q, body_radius, body_radius, 10.298, slices ,slices);
}

void Bicycle::draw_mid_right_body(GLUquadric *q, int x, int y, int z)
{
	glRotatef(90, 0, 1, 0);
	glTranslatef(x, y, z);
	glRotatef(-90+50.710, 1, 0, 0);
	gluCylinder(q, body_radius, body_radius, 14.212, slices, slices);
}

void Bicycle::draw_mid_upper_body(GLUquadric *q, int x, int y, int z)
{
	glRotatef(90, 0, 1, 0);
	glTranslatef(x, y, z);
	gluCylinder(q, body_radius, body_radius, 16, slices, slices);
}

void Bicycle::draw_handlebar_body(GLUquadric *q, int x, int y, int z)
{
	glRotatef(90, 0, 1, 0);
	glTranslatef(x, y, z);
	glRotatef(-113.199, 1, 0, 0);
	gluCylinder(q, body_radius, body_radius, 2.8284, slices, slices);
}

void Bicycle::draw_handlebar_handle(GLUquadric *q, int x, int y, int z)
{
	glTranslatef(x, y, z);
	gluCylinder(q, body_radius, body_radius, 5, 30, 30);
}

void Bicycle::draw_handlebar_handle2(GLUquadric *q, int x, int y, int z)
{
	glRotatef(90, 0, 1, 0);
	glTranslatef(x, y, z);
	glRotatef(240, 1, 0, 0);

	gluCylinder(q, body_radius, body_radius, 3, 30, 30);
}

void Bicycle::draw_saddle_body(GLUquadric *q, int x, int y, int z)
{
	glRotatef(90, 0, 1, 0);
	glTranslatef(x, y, z);
	glRotatef(-187+68.256, 1, 0, 0);
	gluCylinder(q, body_radius, body_radius, 2.236, slices, slices);
}

void Bicycle::draw_saddle(GLUquadric *q, int x, int y, int z)
{
	glColor3f(0.8, 0, 0);
	glPushMatrix();
		glRotatef(90, 1, 0, 0);	
		glTranslatef(x, y ,z);
		gluCylinder(q, 2, 2, 1, slices, slices);
	glPopMatrix();
	glPushMatrix();
	glRotatef(90, 1, 0, 0);
		glTranslatef(x, y, z+0.2);
		gluDisk(q, 0, 2, slices, slices);
	glPopMatrix();
	glPushMatrix();
	glRotatef(90, 1, 0, 0);
		glTranslatef(x, y, z-0.2);
		gluDisk(q, 0, 2, slices, slices);
	glPopMatrix();
	glColor3f(0, 0, 0);
}

void Bicycle::draw_pedal_body(GLUquadric *q, int x, int y, int z, double angle)
{
	glRotatef(90, 0, 1, 0);
	glTranslatef(x, y, z);
	glRotatef(angle, 1, 0, 0);
	gluCylinder(q, 0.3, 0.3, 3, slices, slices);
	glTranslatef(0, 0, 3);
	gluCylinder(q, 0.7, 0.7, 1, slices, slices);
	glTranslatef(0, 0, 0.10);
	gluDisk(q, 0, 0.7, slices, slices);
	glTranslatef(0, 0, -0.20);
	gluDisk(q, 0, 0.7, slices, slices);

}

void Bicycle::draw_pedal(GLUquadric *q, int x, int y, int z, double angle)
{
	glRotatef(90, 1, 0, 0);
	glTranslatef(x, y, z);
	gluCylinder(q, 0.7, 0.7, 1, slices, slices);
}

void Bicycle::go_forward()
{
	x_axis += 0.5;
	wheel_angle += 10;
	pedal_angle += 10;
	glutPostRedisplay();
}

void Bicycle::go_back()
{
	x_axis -= 0.5;
	wheel_angle -= 10;
	pedal_angle -= 10;
	glutPostRedisplay();
}

void Bicycle::reset()
{
	x_axis = 0;
	wheel_angle = 0;
	pedal_angle = 0;
	glutPostRedisplay();
}