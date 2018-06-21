#include "Vector3.h"
//Cmath is included to use math functions
#include <cmath>

//Vector3 Constructor
Vector3::Vector3()
{
}

//Vector3 Copy Constructor Holding the x, y, z positions to be passed into 
Vector3::Vector3(float x, float y, float z) : x(x), y(y), z(z)
{
}

//Vector3 Deconstructor
Vector3::~Vector3()
{
}

//Vector3 Addition Operator
Vector3 Vector3::operator+(const Vector3 & other) const
{
	//Returns the x, y and z value added by the x, y and z value inputed
	return { x + other.x, y + other.y, z + other.z };
}

//Vector3 Homogeneous Addition Operator
Vector3 Vector3::operator+=(const Vector3 & other)
{
	//X, y and z value added to another by the x, y and z value inputed
	x += other.x; y += other.y; z += other.z;
	//Returns the x, y and z value
	return *this;
}

//Vector3 Homogeneous Subtraction Operator
Vector3 Vector3::operator-=(const Vector3 & other)
{
	//X, y and z value subtracted to another by the x, y and z value inputed
	x -= other.x; y -= other.y; z -= other.z;
	//Returns the x, y and z value
	return *this;
}

//Vector3 Homogeneous Multiplication Operator
Vector3 Vector3::operator*=(float scalar)
{
	//X, y and z value multiplied to another by the x, y and z value inputed
	x *= scalar; y *= scalar; z *= scalar;
	//Returns the x, y and z value
	return *this;
}

//Vector3 Homogeneous Division Operator
Vector3 Vector3::operator/=(float scalar)
{
	//X, y and z value divided to another by the x, y and z value inputed
	x /= scalar; y /= scalar; z /= scalar;
	//Returns the x, y and z value
	return *this;
}

//Vector3 Equals Operator
Vector3 Vector3::operator=(const Vector3 & other)
{
	//Returns the x, y and z value equaled by the x, y and z value inputed
	x = other.x; y = other.y; z = other.z;
	return { x, y ,z };
}


//Three Vectors Result in A Fourth Vector that is perpendicular
Vector3 Vector3::cross(const Vector3 & other) const
{
	/*Returns y * inputed z minus z * inputed y,
	          z* inputed z minus z * inputed z,
			  x* inputed y minus y * inputed x */
	return { (y * other.z) - (z * other.y),
		     (z * other.x) - (x * other.z),
		     (x * other.y) - (y * other.x) };
}

//Vector3 Subtraction Operator
Vector3 Vector3::operator-(const Vector3 & other) const
{
	//Returns the x, y and z value subtracted by the x, y and z value inputed
	return { x - other.x, y - other.y, z - other.z };
}

//Vector3 Multiplication Operator
Vector3 Vector3::operator*(float scalar) const
{
	//Returns the x, y and z value multiplied by the x, y and z value inputed
	return { x * scalar, y * scalar, z * scalar };
}

//Vector3 Division Operator
Vector3 Vector3::operator/(float scalar) const
{
	//Returns the x, y and z value divided by the x, y and z value inputed
	return { x / scalar, y / scalar, z / scalar };
}

//Making Vector3 of unit-length
void Vector3::normalise() 
{
	//Nrm holds the equation of x * x + y * y + z * z and then square rooted
	float nrm = sqrt(x * x + y * y + z * z);
	//X, Y and Z are divided and added on by nrm 
	x /= nrm; y /= nrm; z /= nrm;
}

//Finding the length of Vector3
float Vector3::magnitude() const
{
	//Returns the Square Root of x * x plus y * y plus z * z
	return sqrt(x * x + y * y + z * z);
}

//Finding the distance between three points of Vector3
float Vector3::distance(const Vector3 & other) const
{
	//Diffx, Diffy and Diffz hold the x, y and z value minused the x, y and z value inputed
	float diffX = x - other.x;
	float diffY = y - other.y;
	float diffZ = z - other.z;
	//Returns the square root of diffx * diffx plus diffy * diffy plus diffz * diffz
	return sqrt(diffX * diffX + diffY * diffY + diffZ * diffZ);
}

//Projecting another vector onto another
float Vector3::dot(const Vector3 & other) const
{
	//Returns x, y and z times the x, y and z inputed
	return x * other.x + y * other.y + z * other.z;
}

//Vector3 Array Operator
float Vector3::operator[](int index)
{
	//Returns the data array with the index inputed
	return data[index];
}

//Vector3 Explicit Array Operator
Vector3::operator float*()
{
	//Returns Data array
	return data;
}

//Vector3 Friend Multiplication Operator
Vector3 operator*(float scalar, const Vector3 & other)
{
	//Returns the x, y and z value multiplied by the scalar value inputed
	return { other.x * scalar, other.y * scalar, other.z * scalar };
}

//Vector3 Friend Division Operator
Vector3 operator/(float scalar, const Vector3 & other)
{
	//Returns the x, y and z value divided by the scalar value inputed
	return { other.x / scalar, other.y / scalar, other.z / scalar };
}

//Vector3 Friend Subtraction Operator
Vector3 operator-(float scalar, const Vector3 & other)
{
	//Returns the x, y and z value added by the scalar value inputed
	return { other.x - scalar, other.y - scalar, other.z - scalar };
}

//Vector3 Friend Addition Operator
Vector3 operator+(float scalar, const Vector3 & other)
{
	//Returns the x, y and z value added by the scalar value inputed
	return { other.x + scalar, other.y + scalar, other.z + scalar };
}

Vector3 operator*=(float scalar, Vector3 & other)
{
	return { other.x *= scalar, other.y *= scalar, other.z *= scalar };
}

Vector3 operator/=(float scalar, Vector3 & other)
{
	return { other.x /= scalar, other.y /= scalar, other.z /= scalar };
}

Vector3 operator-=(float scalar, Vector3 & other)
{
	return { other.x -= scalar, other.y -= scalar, other.z -= scalar };
}

Vector3 operator+=(Vector3 & other, float scalar)
{
	return { other.x += scalar, other.y += scalar, other.z += scalar };
}

