#include <iostream>

class Vector3D
{
private:
	double x, y, z;
public:
	~Vector3D();
	Vector3D(double _x = 0 , double _y = 0 , double _z = 0) :
		x(_x), y(_y), z(_z) {}
	//Operator overloads
	bool operator== (const Vector3D & other);
	bool operator!= (const Vector3D & other);
	Vector3D operator+ (const Vector3D & other);
	Vector3D operator- (const Vector3D & other);
	void operator+= (const Vector3D & other);
	void operator= (const Vector3D & other);
	//The operator << is at ostream, you use friend to access it.
	friend std::ostream & operator<< (std::ostream & stream, const Vector3D & vector);
};

bool Vector3D::operator== (const Vector3D & other)
{
	return (x == other.x && y == other.y && z == other.z);
}

bool Vector3D::operator!= (const Vector3D & other)
{
	return (!operator == (other));
}

Vector3D Vector3D::operator+ (const Vector3D & other)
{
	Vector3D result;
	result.x = x + other.x;
	result.y = y + other.y;
	result.z = z + other.z;
	return result;
}

Vector3D Vector3D::operator- (const Vector3D & other)
{
	Vector3D result;
	result.x = x - other.x;
	result.y = y - other.y;
	result.z = z - other.z;
	return result;
}

void Vector3D::operator+= (const Vector3D & other)
{
	x += other.x;
	y += other.y;
	z += other.z;
}

void Vector3D::operator= (const Vector3D & other)
{
	x = other.x;
	y = other.y;
	z = other.z;
}
			
std::ostream & operator<< (std::ostream & stream, const Vector3D & vector)
{
	stream << "[x =  " << vector.x << ", y = " << vector.y << ", z = " << vector.z << "]"<< std::endl;
	return stream;
}