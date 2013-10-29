#include "vector3d.h"

vector3d::vector3d() {
	x = y = z = 0;
}

vector3d::vector3d(float a, float b)
{
	x = a;
	y = b;
	z = 0;
}

vector3d::vector3d(float a, float b, float c) {
	x = a;
	y = b;
	z = c;
}

vector3d::vector3d();
	  vector3d::vector3d(float a, float b);
	  vector3d::vector3d(float a, float b, float c);

	  float vector3d::dotProduct(const vector3d& vec2);
	  vector3d vector3d::crossProduct(const vector3d& vec2);
	  float vector3d::normalize();

	  void vector3d::change(float a, float b, float c);
	  void vector3d::change(vector3d& vec2);
	  void vector3d::change(vector3d vec2);
	  void vector3d::changeX(float a);
	  void vector3d::changeY(float a);
	  void vector3d::changeZ(float a);

	  vector3d vector3d::operator+(const vector3d& vec2);
	  vector3d vector3d::operator-(const vector3d& vec2);
	  vector3d vector3d::operator*(float vec2);
	  vector3d vector3d::operator/(float vec2);

	  vector3d& vector3d::operator+=(const vector3d& vec2);
	  vector3d& vector3d::operator-=(const vector3d& vec2);
	  vector3d& vector3d::operator*=(float vec2);
	  vector3d& vector3d::operator/=(float vec2);

	  bool vector3d::operator==(const vector3d vec2);
	  bool vector3d::operator!=(const vector3d vec2);

	  cout << vec;

	  friend std::ostream& operator<<(std::ostream& out, const vector3d& vec);
};

#endif