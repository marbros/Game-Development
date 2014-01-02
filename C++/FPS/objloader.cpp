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
		}else if((*coord[i])[0]=='f')
		{
			int a,b,c,d,e;			
			if(coll && collplane!=NULL)
			{
				sscanf(coord[i]->c_str(),"f %d//%d %d//%d %d//%d %d//%d",&a,&b,&c,&b,&d,&b,&e,&b);
				collplane->push_back(collisionplane(normals[b-1]->x,normals[b-1]->y,normals[b-1]->z,vertex[a-1]->x,vertex[a-1]->y,vertex[a-1]->z,vertex[c-1]->x,vertex[c-1]->y,vertex[c-1]->z,vertex[d-1]->x,vertex[d-1]->y,vertex[d-1]->z,vertex[e-1]->x,vertex[e-1]->y,vertex[e-1]->z));
			}else
			{
				if(count(coord[i]->begin(),coord[i]->end(),' ')==4)
				{
					if(coord[i]->find("//")!=std::string::npos)
					{
						sscanf(coord[i]->c_str(),"f %d//%d %d//%d %d//%d %d//%d",&a,&b,&c,&b,&d,&b,&e,&b);
						faces.push_back(new face(b,a,c,d,e,0,0,0,0,curmat));
					}else if(coord[i]->find("/")!=std::string::npos)
					{
						int t[4];
						sscanf(coord[i]->c_str(),"f %d/%d/%d %d/%d/%d %d/%d/%d %d/%d/%d",&a,&t[0],&b,&c,&t[1],&b,&d,&t[2],&b,&e,&t[3],&b);
						out << t[0] << " " <<t[1] << " " <<t[2] << " " <<t[3] << " " << a << " " << b << " " << c << " " << d << " " << e << std::endl;
						faces.push_back(new face(b,a,c,d,e,t[0],t[1],t[2],t[3],curmat));
					}else{
						sscanf(coord[i]->c_str(),"f %d %d %d %d",&a,&b,&c,&d);
						faces.push_back(new face(-1,a,b,c,d,0,0,0,0,curmat));					
					}
				}else{
						if(coord[i]->find("//")!=std::string::npos)
						{
							sscanf(coord[i]->c_str(),"f %d//%d %d//%d %d//%d",&a,&b,&c,&b,&d,&b);
							faces.push_back(new face(b,a,c,d,0,0,0,curmat));
						}else if(coord[i]->find("/")!=std::string::npos)
						{
							int t[3];
							sscanf(coord[i]->c_str(),"f %d/%d/%d %d/%d/%d %d/%d/%d",&a,&t[0],&b,&c,&t[1],&b,&d,&t[2],&b);
							faces.push_back(new face(b,a,c,d,t[0],t[1],t[2],curmat));
						}else{
							sscanf(coord[i]->c_str(),"f %d %d %d",&a,&b,&c);
							faces.push_back(new face(-1,a,b,c,0,0,0,curmat));					
						}
				}
			}			
		}			
	}else if((*coord[i])[0]=='u' && (*coord[i])[1]=='s' && (*coord[i])[2]=='e')
	{
		char tmp[200];
		sscanf(coord[i]->c_str(),"usemtl %s",tmp);
		if(strcmp(tmp,"collision")==0)
		{
			coll=true;
		}else{
			coll=false;
			for(int i=0;i<materials.size();i++)
			{
				if(strcmp(materials[i]->name.c_str(),tmp)==0)
				{
					curmat=i;
					out << "curmat=" << i  << std::endl;
					break;
				}
			}
		}
	}else if((*coord[i])[0]=='m' && (*coord[i])[1]=='t' && (*coord[i])[2]=='l' && (*coord[i])[3]=='l')
	{
		char filen[200];
		sscanf(coord[i]->c_str(),"mtllib %s",filen);
		std::string filen2=path+filen;
		std::ifstream mtlin(filen2.c_str());
		if(!mtlin.is_open())
		{
			out << "connot open the material file " << filen2 << std::endl;
			clean();
			return -1;
		}
		ismaterial=true;
		std::vector<std::string> tmp;
		char c[200];
		while(!mtlin.eof())
		{
			mtlin.getline(c,200);
			tmp.push_back(c);
		}
	}		
}

void objloader::clean()
{
	for(int i=0;i<coord.size();i++)
		delete coord[i];
	coord.clear();
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

objloader::objloader()
{
	ismaterial=false;
	isnormals=false;
	istexture=false;
	isvertexnormal=false;
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