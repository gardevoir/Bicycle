#pragma once

#include "stdafx.h"
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>

class Bicycle
{
public:
	Bicycle(void);

public:
	void draw_bicycle();
	void accelerate();
	void brake();
	void turn_left();
	void turn_right();

private:
	void draw_wheel(int x, int y, int z, double angle);
	void draw_disc(GLUquadric *q, int x, int y, int z);
	void draw_pedal();
	void draw_left_lower_wheel_body(GLUquadric *q, int x, int y, int z);
	void draw_left_upper_wheel_body(GLUquadric *q, int x, int y, int z);
	void draw_right_wheel_body(GLUquadric *q, int x, int y, int z);
	void draw_mid_left_body(GLUquadric *q, int x, int y, int z);
	void draw_mid_right_body(GLUquadric *q, int x, int y, int z);
	void draw_mid_upper_body(GLUquadric *q, int x, int y, int z);
	void draw_mid_body(GLUquadric *q, int x, int y, int z);
	void draw_handlebar_body(GLUquadric *q, int x, int y, int z, double angle);
	void draw_handlebar_handle(GLUquadric *q, int x, int y, int z, double angle);
	void draw_saddle_body(GLUquadric *q, int x, int y, int z);
	void draw_saddle(GLUquadric *q, int x, int y, int z);
	void draw_pedal_body(GLUquadric *q, int x, int y, int z, double angle);
	void draw_pedal(GLUquadric *q, int x, int y ,int z, double angle);

	const double disc_inner_radius;
	const double disc_outer_radius;
	const double body_radius;
	const int slices;

	double x_axis, y_axis, z_axis, wheel_angle;
	GLUquadric *q;
	//-----------------------------------------------

	

	

	~Bicycle(void);
};

