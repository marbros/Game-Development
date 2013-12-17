#include "camera.h"

void camera::lockCamera() {
	if(camPitch>90)
		camPitch=90;
	if(camPitch<-90)
		camPitch=-90;
	if(camYaw<0.0)
		camYaw+=360.0;
	if(camYaw>360.0)
		camYaw-=360;
}

void camera::moveCamera(float dir) {
	float rad=(camYaw+dir)*M_PI/180.0;
	loc.x-=sin(rad)*mv;
	loc.z-=cos(rad)*mv;	
}

void camera::moveCameraUp(float dir) {
	float rad=(camPitch+dir)*M_PI/180.0;
	camY.y+=sin(rad)*movevel;		
}

camera::camera() {
	camPitch = 0;
	camYaw = 0;
	movevel = 0.2;
	mouseVel = 0.2;
	mi = false;
}

camera::camera(vector3d l) {
	loc.change(l);
	camPitch = 0;
	camYaw = 0;
	movevel = 0.2;
	mouseVel = 0.2;
	mi = false;
}

camera::camera(vector3d loc, float yaw, float pitch) {
	loc.change(l);
	camPitch = pitch;
	camYaw = 0;
	movevel = 0.2;
	mouseVel = 0.2;
	mi = false;
}

camera::camera(vector3d loc, float yaw, float pitch, float mv, float mov) {
	loc.change(l);
	camPitch = pitch;
	camYaw = yaw;
	movevel = mv;
	mouseVel = mov;
	mi = false;
}

void camera::control()
{
	if(mi)
	{

		int MidX=320;
		int MidY=240;
		SDL_ShowCursor(SDL_DISABLE);
		int tmpx,tmpy;
		SDL_GetMouseState(&tmpx,&tmpy);
		camYaw+=mousespeed*(MidX-tmpx);
		camPitch+=mousespeed*(MidY-tmpy);
		lockCamera();
		SDL_WarpMouse(MidX,MidY);
		Uint8* state=SDL_GetKeyState(NULL);
		if(state[SDLK_w])
		{
				moveCamera(0.0);
		}else if(state[SDLK_s])
		{
				moveCamera(180.0);
		}		
		if(state[SDLK_a])
			moveCamera(90.0);
		else if(state[SDLK_d])
			moveCamera(270);	
	}

	glRotatef(-camPitch,1.0,0.0,0.0);
	glRotatef(-camYaw,0.0,1.0,0.0);
}

void camera::update()
{
	glTranslatef(-loc.x,-loc.y,-loc.z);
}

vector3d camera::getLocation()
{
	return loc;
}

float camera::getYaw()
{
	return camYaw;
}
float camera::getPitch()
{
	return camPitch;
}
	vector3d getVector();
	float camPitch();
	float camYaw();
	float getMovevel();
	float getMouseVel();
	bool isMouseIn();

	void setLocation(vector3d vec);
	void lookAt(float pitch, float yaw);
	void mouseIn(bool b);
	void setSpeed(float mv, float mov);