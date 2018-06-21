#include "Vector4.h"
//Cmath is included to use math functions
#include <cmath>

//Vector4 Constructor
Vector4::Vector4()
{
}

//Vector4 Copy Constructor Holding the x, y, z and w positions to be passed into 
Vector4::Vector4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w)
{
}

//Vector4 Deconstructor
Vector4::~Vector4()
{
}

//Vector4 Addition Operator
Vector4 Vector4::operator+(const Vector4 & other) const
{
	//Returns the x, y, z and w value added by the x, y, z and w value inputed
	return { x + other.x, y + other.y, z + other.z, w + other.w };
}

//Vector4 Subtraction Operator
Vector4 Vector4::operator-(const Vector4 & other) const
{
	//Returns the x, y, z and w value subtracted by the x, y, z and w value inputed
	return { x - other.x, y - other.y, z - other.z, w - other.w };
}

//Vector4 Multiplication Operator
Vector4 Vector4::operator*(float scalar) const
{
	//Returns the x, y, z and w value Multiply by the x, y, z and w value inputed
	return { x * scalar, y * scalar, z * scalar, w * scalar };
}

//Vector4 Division Operator
Vector4 Vector4::operator/(float scalar) const
{
	//Returns the x, y, z and w value Divided by the x, y, z and w value inputed
	return { x / scalar, y / scalar, z / scalar, w / scalar };
}

//Vector4 Homogeneous Addition Operator
Vector4 Vector4::operator+=(const Vector4 & other)
{
	//X, y, z and w value added to another by the x, y, z and w value inputed
	x += other.x; y += other.y; z += other.z; w += other.w;
	//Returns the x, y, z and w value
	return *this;
}

//Vector4 Homogeneous Subtraction Operator
Vector4 Vector4::operator-=(const Vector4 & other)
{
	//X, y, z and w value subtracted to another by the x, y, z and w value inputed
	x -= other.x; y -= other.y; z -= other.z; w -= other.w;
	//Returns the x, y, z and w value
	return *this;
}

//Vector4 Homogeneous Multiplication Operator
Vector4 Vector4::operator*=(float scalar)
{
	//X, y, z and w value multiplied to another by the x, y, z and w value inputed
	x *= scalar; y *= scalar; z *= scalar; w *= scalar;
	//Returns the x, y, z and w value
	return *this;
}

//Vector4 Homogeneous Division Operator
Vector4 Vector4::operator/=(float scalar)
{
	//X, y, z and w value divided to another by the x, y, z and w value inputed
	x /= scalar; y /= scalar; z /= scalar; w /= scalar;
	//Returns the x, y, z and w value
	return *this;
}

//Vector4 Equals Operator
Vector4 Vector4::operator=(const Vector4 & other)
{
	//X, y, z and w value equals to another by the x, y, z and w value inputed
	x = other.x; y = other.y; z = other.z; w = other.w;
	//Returns the x, y, z and w value
	return *this;
}

//Four Vectors Result in A Fifth Vector that is perpendicular
Vector4 Vector4::cross(const Vector4 & other) const
{
	/*Returns y * inputed z minus z * inputed y,
	          z* inputed z minus z * inputed z,
	          x* inputed y minus y * inputed x, 
			  w* inputed w minus w * inputed w,*/
	return { (y * other.z) - (z * other.y),
		     (z * other.x) - (x * other.z),
		     (x * other.y) - (y * other.x),
		     (w * other.w) - (w * other.w)                                     
	};
}

//Making Vector4 of unit-length
void Vector4::normalise()
{
	//Nrm holds the equation of x * x + y * y + z * z + w * w and then square rooted
	float nrm = sqrt(x * x + y * y + z * z + w * w);
	//X, Y, Z, W are divided and added on by nrm 
	x /= nrm; y /= nrm; z /= nrm; w /= nrm;
}

//Finding the length of Vector4
float Vector4::magnitude() const
{
	//Returns the Square Root of x * x plus y * y plus z * z plus w * w
	return sqrt(x * x + y * y + z * z + w * w);
}

//Finding the distance between four points of Vector4
float Vector4::distance(const Vector4 & other) const
{
	//Diffx, Diffy, Diffz and Diffw holds the x, y, z and w value minused the x, y, z and w value inputed
	float diffX = x - other.x;
	float diffY = y - other.y;
	float diffZ = z - other.z;
	float diffW = w - other.w;
	//Returns the square root of diffx * diffx plus diffy * diffy plus diffz * diffz plus diffw * diffw
	return sqrt(diffX * diffX + diffY * diffY + diffZ * diffZ + diffW * diffW);
}

//Projecting another vector onto another
float Vector4::dot(const Vector4 & other) const
{
	//Returns x, y, z and w times the x, y, z and w inputed
	return x * other.x + y * other.y + z * other.z + w * other.w;
}

//Vector4 Array Operator
float Vector4::operator[](int index)
{
	//Returns the data array with the index inputed
	return data[index];
}

//Vector4 Explicit Array Operator
Vector4::operator float*()
{
	//Returns Data array
	return data;
}

//Vector4 Friend Multiplication Operator
Vector4 operator*(float scalar, const Vector4 & other)
{
	//Returns the x, y, z and w value multiplied by the scalar value inputed
	return { other.x * scalar, other.y * scalar, other.z * scalar, other.w * scalar };
}

//Vector4 Friend Division Operator
Vector4 operator/(float scalar, const Vector4 & other)
{
	//Returns the x, y, z and w value divided by the scalar value inputed
	return { other.x / scalar, other.y / scalar, other.z / scalar, other.w / scalar };
}

//Vector4 Friend Subtraction Operator
Vector4 operator-(float scalar, const Vector4 & other)
{
	//Returns the x, y, z and w value subtracted by the scalar value inputed
	return { other.x - scalar, other.y - scalar, other.z - scalar, other.w - scalar };
}

//Vector4 Friend Addition Operator
Vector4 operator+(float scalar, const Vector4 & other)
{
	//Returns the x, y, z and w value added by the scalar value inputed
	return { other.x + scalar, other.y + scalar, other.z + scalar, other.w + scalar };
}
