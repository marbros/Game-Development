#include "camera.h"

	void lockCamera();
	void moveCamera(float dir);
	void moveCameraUp(float dir);
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