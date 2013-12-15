#ifndef CAMERA_H
#define CAMERA_H
#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <cmath>
#include <iostream>

class camera {
	vector3d loc;
	float camPitch, camYaw;
	float movevel;
	float mousevel;
	bool mi;
	void lockCamera();
	void moveCamera(float dir);
	void moveCameraUp(float dir);
public:
	camera();
	camera(vector3d loc);
	camera(vector3d loc, float yaw, float pitch);
	camera(vector3d loc, float yaw, float pitch, float mv, float mov);
	void control();
};

#endif