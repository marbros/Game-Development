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
	camY.y+=sin(rad)*mv;		
}
public:
	camera();
	camera(vector3d loc);
	camera(vector3d loc, float yaw, float pitch);
	camera(vector3d loc, float yaw, float pitch, float mv, float mov);
	void Control();
	void UpdateCamera();
	vector3d getVector();
	vector3d getLocation();
	float camPitch();
	float camYaw();
	float getMovevel();
	float getMouseVel();
	bool isMouseIn();

	void setLocation(vector3d vec);
	void lookAt(float pitch, float yaw);
	void mouseIn(bool b);
	void setSpeed(float mv, float mov);