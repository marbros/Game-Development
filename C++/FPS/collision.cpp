#include "collision.h"

bool collision::raysphere(float xc, float yc, float zc, float xd, floar yd,float zd, float xs, float ys, float zs, float r,float *dist =NULL, coordinate* point=NULL) {

	float b=2*(xd*(xs-xc)+yd*(ys-yc)+zd*(zs-zc));
	float c=xs*xs-2*xs*xc+xc*xc+ys*ys-
		          2*ys*yc+yc*yc*yc+zs-
		          2*zs*zc+zc*zc-r*r;
	float disc = (b*b-4*c);
	if(disc < 0)
		return false;
	if(dist != NULL) {
		//-b + disc/2
		(*dist) = (-b + disc)/2;
		if(point != NULL) {
			//xs+t*xd
			point->x = xs+(*dist)*xd;
			point->y = ys+(*dist)*yd;
			point->z = zs+(*dist)*zd;
		}
	}
	return true;
		//(x+y)^2=x^2+2xy+y^2
}

float collision::trianglearea(vector3d p1,vector3d p2,vector3d p3)
{
	//area of the triangle with the heron fomula
	float a=sqrt((p2.x-p1.x)*(p2.x-p1.x)+(p2.y-p1.y)*(p2.y-p1.y)+(p2.z-p1.z)*(p2.z-p1.z));
	float b=sqrt((p3.x-p2.x)*(p3.x-p2.x)+(p3.y-p2.y)*(p3.y-p2.y)+(p3.z-p2.z)*(p3.z-p2.z));
	float c=sqrt((p1.x-p3.x)*(p1.x-p3.x)+(p1.y-p3.y)*(p1.y-p3.y)+(p1.z-p3.z)*(p1.z-p3.z));
	float s=(a+b+c)/2.;
	return (sqrt(s*((s-a)*(s-b)*(s-c))));
}

float collision::pointdistance(coordinate c1,, coordinate c2) {
	coordinate vec(c2.x-c1.x,c2.y-c1.y,c2.z-c1.z);
	return (vec.x*vec.x+vec.y*vec.y+vec.z*vec.z);
}