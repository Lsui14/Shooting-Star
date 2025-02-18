#include "Vector3D.h"

Vector3D Vector3D::Add(const Vector3D& b)
{
	Vector3D result(x + b.x, y + b.y, z + b.z);
	return result;
}

Vector3D Vector3D::operator+( const Vector3D& b)
{
	//Vector3D<float> result(x + b.x, y + b.y, z + b.z);
	//return result;
	return Vector3D(this->GetX() + b.GetX(), this->GetY() + b.GetY(), this->GetZ() + b.GetZ());
}

Vector3D Vector3D::Substract(const Vector3D& b)
{
	Vector3D result(x - b.x, y - b.y, z - b.z);
	return result;
}

Vector3D Vector3D::operator-( const Vector3D& b)
{
	/*Vector3D<S> result(x - b.x, y - b.y, z - b.z);
	return result;*/
	return Vector3D(this->GetX() - b.GetX(), this->GetY() - b.GetY(), this->GetZ() - b.GetZ());
}

Vector3D Vector3D::Product(const float& b)
{
	Vector3D result(x * b, y * b, z * b);
	return result;
}

Vector3D Vector3D::operator*( const float& b)
{
	/*Vector3D<S> result(x * b, y * b, z * b);
	return result;*/
	return Vector3D(this->GetX() * b, this->GetY() * b, this->GetZ() * b);
}

Vector3D Vector3D::operator*( const float& b) const
{
	/*Vector3D<S> result(x * b, y * b, z * b);
	return result;*/
	return Vector3D(this->GetX() * b, this->GetY() * b, this->GetZ() * b);
}

Vector3D Vector3D::operator/( const float& m)
{
	/*Vector3D<S> result;
	result.x = x / m;
	result.y = y / m;
	result.z = z / m;
	return result;*/
	return Vector3D(this->GetX()/m, this->GetY() / m, this->GetZ() / m);
}

float Vector3D::DotProduct(const Vector3D& v)
{
	float result;
	result = x * v.x + y * v.y + z * v.z;
	return result;
}

float Vector3D::operator*( const Vector3D& v)
{
	float result;
	result = x * v.x + y * v.y + z * v.z;
	return result;
	
}

