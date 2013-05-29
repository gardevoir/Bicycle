#pragma once

#include "stdafx.h"
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>

class Bicycle
{
public:
	Bicycle();
	void draw_bicycle();
	void go_forward();
	void go_back();
	void reset();
	~Bicycle(void);

private:
	void draw_wheel(int x, int y, int z, double angle);
	void draw_disc(GLUquadric *q, int x, int y, int z);
	void draw_pedal();
	void draw_left_lower_wheel_body(GLUquadric *q, int x, int y, int z);
	void draw_left_upper_wheel_body(GLUquadric *q, int x, int y, int z, int axis);
	void draw_right_wheel_body(GLUquadric *q, int x, int y, int z, int axis);
	void draw_mid_left_body(GLUquadric *q, int x, int y, int z);
	void draw_mid_right_body(GLUquadric *q, int x, int y, int z);
	void draw_mid_upper_body(GLUquadric *q, int x, int y, int z);
	void draw_mid_body(GLUquadric *q, int x, int y, int z);
	void draw_handlebar_body(GLUquadric *q, int x, int y, int z);
	void draw_handlebar_handle(GLUquadric *q, int x, int y, int z);
	void draw_handlebar_handle2(GLUquadric *q, int x, int y, int z);
	void draw_saddle_body(GLUquadric *q, int x, int y, int z);
	void draw_saddle(GLUquadric *q, int x, int y, int z);
	void draw_pedal_body(GLUquadric *q, int x, int y, int z, double angle);
	void draw_pedal(GLUquadric *q, int x, int y ,int z, double angle);
	void draw_bridge(GLUquadric *q, int x, int y, int z);
	const double disc_inner_radius;
	const double disc_outer_radius;
	const double body_radius;
	const int slices;

	double x_axis, y_axis, z_axis, wheel_angle, handle_angle, pedal_angle;
	GLUquadric *q;
	//-----------------------------------------------

	

	

	
};

