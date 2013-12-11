#include "collision.h"

bool collision::raysphere(float xc, float yc, float zc, float xd, floar yd,float zd, float xs, float ys, float zs, float r,float *dist =NULL, coordinate* point=NULL) {

	float b=2*(xd*(xs-xc)+yd*(ys-yc)+zd*(zs-zc));
	float c=xs*xs-2*xs*xc+xc*xc+ys*ys-
		          2*ys*yc+yc*yc*yc+zs-
		          2*zs*zc+zc*zc;
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