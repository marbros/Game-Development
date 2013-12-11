#ifndef COLLISION_H
#define COLLISION_H
##include "objloader.h"

class collision
{
	static bool raysphere(float xc, float yc, float zc, float xd, floar yd,
				   float zd, float xs, float ys, float zs, float r,
				   float *dist =NULL, coordinate* point=NULL);

	static bool rayplane(float nx, float ny, float nz, float xs, floar ys,
				  float zs, float xd, float yd, float zd, coordinate p1,
				  coordinate p2, coordinate p3, coordinate p4,
				  float *dist =NULL, coordinate* point=NULL);

	static float trianglearrea(coordinate p1, coordinate p2, coordinate p3);

	static bool spheresphere(coordinate& c1, float r1, coordinate c2, float r2);

	static float pointdistance(coordinate c1,, coordinate c2);

	static bool sphereplane(coordinate& sp, coordinate vn, coordinate p1, coordinate p2, coordinate p3, coordinate p4, float r);
};

#endif