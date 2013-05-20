#include "stdafx.h"
#include "Bicycle.h"
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>


Bicycle::Bicycle(): disc_inner_radius(0), disc_outer_radius(1), slices(30),body_radius(0.4)
{
	x_axis = 0;
	y_axis = 0;
	z_axis = 0;
	wheel_angle = 0;
	handle_angle = 0;
	q = gluNewQuadric();
}


Bicycle::~Bicycle(void)
{
}

void Bicycle::draw_bicycle()
{
	
	glTranslatef(x_axis, y_axis, z_axis);//master matrix

	glPushMatrix();//left wheel
		draw_wheel(-13, 0, 0, wheel_angle);
	glPopMatrix();
	glPushMatrix();//right wheel
		draw_wheel(13, 0, 0, wheel_angle);
	glPopMatrix();
	//left lower body
	glPushMatrix();//-z axis part
		draw_left_lower_wheel_body(q, 1, 0, -13);
	glPopMatrix();
	glPushMatrix();//+z axis part
		draw_left_lower_wheel_body(q, -1, 0, -13);
	glPopMatrix();
	//left upper body
	glPushMatrix();//-z axis part
		draw_left_upper_wheel_body(q, -1, 0, -13);
	glPopMatrix();
	glPushMatrix();//+z axis part
		draw_left_upper_wheel_body(q, 1, 0, -13);
	glPopMatrix();
	//right body
	glPushMatrix();//-z axis part
		draw_right_wheel_body(q, -1, 0, 13);
	glPopMatrix();
	glPushMatrix();//+z axis part
		draw_right_wheel_body(q, 1, 0, 13);
	glPopMatrix();
	//mid body
	glPushMatrix();//mid left part
		draw_mid_left_body(q, 0, -2, -1);
	glPopMatrix();
	glPushMatrix();//mid right part
		draw_mid_right_body(q, 0, -2, -1);
	glPopMatrix();
	glPushMatrix();//mid upper part
		draw_mid_upper_body(q, 0, 7, -6);
	glPopMatrix();
	//handle
	glPushMatrix();//handle body
		draw_handlebar_body(q, 0, 7, 10, handle_angle);
	glPopMatrix();
	glPushMatrix();//handlebar
		draw_handlebar_handle(q, 9, 10, -2.5, handle_angle);
	glPopMatrix();
	//saddle
	glPushMatrix();//saddle body
		draw_saddle_body(q, 0, 7, -6);
	glPopMatrix();
	glPushMatrix();//saddle
		draw_saddle(q, -7, 0, -10);
	glPopMatrix();
	//discs
	glPushMatrix();//+z axis disc
		draw_disc(q, -1, -2, 1.5);
	glPopMatrix();
	glPushMatrix();//-z axis disc
		draw_disc(q, -1, -2, -1.5);
	glPopMatrix();
	//pedal body
	glPushMatrix();//+z axis pedal
		draw_pedal_body(q, 2, -2, -1, pedal_angle);
	glPopMatrix();
	glPushMatrix();//-z axis pedal
		draw_pedal_body(q, -2, -2, -1, pedal_angle);
	glPopMatrix();
	//pedal
	glPushMatrix();//+z axis 
		draw_pedal(q, -1 ,3, -1, pedal_angle);
	glPopMatrix();
	glPushMatrix();//-z axis
		draw_pedal(q, -1, -3, 5, pedal_angle);
	glPopMatrix();
}


//private methods


void Bicycle::draw_wheel(int x, int y, int z, double angle)
{
	glTranslatef(x, y, z);
	glutSolidTorus(0.5,5.0,10,50);

	glRotatef(90, 0, 1, 0);
	for(int i = 1; i < 9; i++){
		glRotatef(45, 1, 0, 0);
		gluCylinder(q, 0.2, 0.2, 5, slices, slices);
	}
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

void Bicycle::draw_left_upper_wheel_body(GLUquadric *q, int x, int y, int z)
{
	glRotatef(90, 0, 1, 0);
	glTranslatef(x, y, z);
	glRotatef(-45, 1, 0, 0);
	gluCylinder(q, body_radius, body_radius, 9.899, slices, slices);
}

void Bicycle::draw_right_wheel_body(GLUquadric *q, int x, int y, int z)
{
	glRotatef(90, 0, 1, 0);
	glTranslatef(x, y, z);
	glRotatef(-180+66.801, 1, 0, 0);
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

void Bicycle::draw_handlebar_body(GLUquadric *q, int x, int y, int z, double angle)
{
	glRotatef(90, 0, 1, 0);
	glTranslatef(x, y, z);
	glRotatef(-113.199, 1, 0, 0);
	gluCylinder(q, body_radius, body_radius, 2.8284, slices, slices);
}

void Bicycle::draw_handlebar_handle(GLUquadric *q, int x, int y, int z, double angle)
{
	glTranslatef(x, y, z);
	gluCylinder(q, body_radius, body_radius, 5, 30, 30);
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
	glRotatef(90, 1, 0, 0);	
	glTranslatef(x, y ,z);
	gluCylinder(q, 2, 2, 1, slices, slices);
}

void Bicycle::draw_pedal_body(GLUquadric *q, int x, int y, int z, double angle)
{
	glRotatef(90, 0, 1, 0);
	glTranslatef(x, y, z);
	glRotatef(90, 1, 0, 0);
	gluCylinder(q, 0.3, 0.3, 3, slices, slices);
}

void Bicycle::draw_pedal(GLUquadric *q, int x, int y, int z, double angle)
{
	glRotatef(90, 1, 0, 0);
	glTranslatef(x, y, z);
	gluCylinder(q, 0.7, 0.7, 1, slices, slices);
}