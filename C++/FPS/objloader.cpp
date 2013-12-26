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

int objloader::load(const std::string& filename,std::vector<collisionplane>* collplane)
{
	ismaterial=false;
	isnormals=false;
	istexture=false;
	isvertexnormal=false;
	std::ifstream in(filename.c_str());
	if(!in.is_open())
	{
		out << "Not opened file " << filename << std::endl;
		return -1;
	}
	std::string path=filename.substr(0,((filename.find_last_of('/')+1!=std::string::npos) ? (filename.find_last_of('/')+1):0));
	out << filename << std::endl;
	char buf[256];
	int curmat=0;
	bool coll=false;
	int z=0;
	int h=-1;
	while(!in.eof())
	{
		in.getline(buf,256);
		coord.push_back(new std::string(buf));
	}	
	for(int i=0;i<coord.size();i++)
	{
		if((*coord[i])[0]=='#')
			continue;
		else if((*coord[i])[0]=='v' && (*coord[i])[1]==' ')
		{
			float tmpx,tmpy,tmpz;
			sscanf(coord[i]->c_str(),"v %f %f %f",&tmpx,&tmpy,&tmpz);
			vertex.push_back(new coordinate(tmpx,tmpy,tmpz));
			out << "v " << tmpx << " " << tmpy << " " << tmpz << std::endl;
		}else if((*coord[i])[0]=='v' && (*coord[i])[1]=='n')
		{
			float tmpx,tmpy,tmpz;
			sscanf(coord[i]->c_str(),"vn %f %f %f",&tmpx,&tmpy,&tmpz);
			normals.push_back(new coordinate(tmpx,tmpy,tmpz));	
			out << "vn " << tmpx << " " << tmpy << " " << tmpz << std::endl;
	}		
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

void objloader::smoothnormals()
{
	for(int i=1;i<vertex.size()+1;i++)
	{
		float vecX=0.0,vecY=0.0,vecZ=0.0;
		int num=0;
		for(int j=0;j<faces.size();j++)
		{
			if(faces[j]->faces[0]==i || faces[j]->faces[1]==i || faces[j]->faces[2]==i || faces[j]->faces[3]==i)
			{
				vecX+=normals[faces[j]->facenum-1]->x;
				vecY+=normals[faces[j]->facenum-1]->y;
				vecZ+=normals[faces[j]->facenum-1]->z;
				num++;
			}
		}
		if(num)
		{
			vecX/=num;
			vecY/=num;
			vecZ/=num;
		}
		float d=sqrt(vecX*vecX+vecY*vecY+vecZ*vecZ);
		if(d)
		{
			vecX/=d;
			vecY/=d;
			vecZ/=d;
		}
		vertexnormals.push_back(new coordinate(vecX,vecY,vecZ));
	}
}