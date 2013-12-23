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

	face::face(int facen,int f1,int f2,int f3,int f4,int t1,int t2,int t3,int t4,int m){
		facenum=facen;
		faces[0]=f1;
		faces[1]=f2;
		faces[2]=f3;
		faces[3]=f4;
		texcoord[0]=t1;
		texcoord[1]=t2;
		texcoord[2]=t3;
		texcoord[3]=t4;
		mat=m;
		four=true;
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

	texcoord::texcoord(float a,float b)
	{
		u=a;
		v=b;
	}

	unsigned int objloader::loadTexture(const char* filename)
	{
		unsigned int num;
		glGenTextures(1,&num);
		SDL_Surface* img=SDL_LoadBMP(filename);
		glBindTexture(GL_TEXTURE_2D,num);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D,0,GL_RGB,img->w,img->h,0,GL_RGB,GL_UNSIGNED_SHORT_5_6_5,img->pixels);
		glTexEnvi(GL_TEXTURE_2D,GL_TEXTURE_ENV_MODE,GL_MODULATE);
		SDL_FreeSurface(img);
		texture.push_back(num);
		loadedTextures.push_back(filename);
		loadedTexturesNum.push_back(num);
		return num;
	}