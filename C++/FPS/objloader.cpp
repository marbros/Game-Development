#include "objloader.h"

	coordinate::coordinate(float a,float b,float c)
	{
		x=a;
		y=b;
		z=c;
	}

	face::face(int facen,int f1,int f2,int f3,int t1,int t2,int t3,int m){
		facenum=facen;
		faces[0]=f1;
		faces[1]=f2;
		faces[2]=f3;
		texcoord[0]=t1;
		texcoord[1]=t2;
		texcoord[2]=t3;
		mat=m;
		four=false;
	}

	material::material(const char* na,float al,float n,float ni2,float* d,float* a,float* s,int i,int t)
	{
		name=na;
		alpha=al;
		ni=ni2;
		ns=n;
		dif[0]=d[0];
		dif[1]=d[1];
		dif[2]=d[2];
		
		amb[0]=a[0];
		amb[1]=a[1];
		amb[2]=a[2];
		
		spec[0]=s[0];
		spec[1]=s[1];
		spec[2]=s[2];
		
		illum=i;
		texture=t;
	}