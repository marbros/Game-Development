#ifndef VECTOR3D_H
#define VECTOR#D_H

class vector3d{
	public:
	  float3d();
	  vector3d();
	  vector3d(float a, float b);
	  vector3d(float a, float b, float c);

	  float dotProduct(const vector3d& vec2);
	  vector3d crossProduct(const vector3d& vec2);
	  float normalize();

	  
}