#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <map>
#include "collisionplane.h"

struct coordinate{
	float x,y,z;
	coordinate(float a,float b,float c);
};

struct face{
	int facenum;
	bool four;
	int faces[4];
	int texcoord[4];
	int mat;
	face(int facen,int f1,int f2,int f3,int t1,int t2,int t3,int m);
	face(int facen,int f1,int f2,int f3,int f4,int t1,int t2,int t3,int t4,int m);
};

struct material{
	std::string name;
	float alpha,ns,ni;
	float dif[3],amb[3],spec[3];
	int illum;
	int texture;
	material(const char* na,float al,float n,float ni2,float* d,float* a,float* s,int i,int t);
};

struct texcoord{
	float u,v;
	texcoord(float a,float b);
};