#include "Vector2.h"
//Cmath is included to use math functions
#include <cmath> 

//Vector2 Constructor
Vector2::Vector2()
{
}

//Vector2 Copy Constructor Holding the x and y positions to be passed into 
Vector2::Vector2(float x, float y) : x(x), y(y)
{
}

//Vector2 Deconstructor
Vector2::~Vector2()
{
}

//Vector2 Addition Operator
Vector2 Vector2::operator + (const Vector2& other) const
{
	//Returns the x and y value added by the x and y value inputed
	return { x + other.x, y + other.y };
}

//Vector2 Subtraction Operator
Vector2 Vector2::operator-(const Vector2 & other) const
{
	//Returns the x and y value subtracted by the x and y value inputed
	return { x - other.x, y - other.y };
}

//Vector2 Multiplication Operator
Vector2 Vector2::operator * (float scalar) const
{
	//Returns the x and y value multiplied by the scalar value inputed
	return { x * scalar, y * scalar };
}

//Vector2 Division Operator
Vector2 Vector2::operator/(float scalar) const
{
	//Returns the x and y value divided by the scalar value inputed
	return { x / scalar, y / scalar };
}

//Vector2 Equals Operator
Vector2 Vector2::operator=(const Vector2 & other)
{
	//Returns the x and y value equaled by the x and y value inputed
	x = other.x; y = other.y;
	return *this;
}

//Vector2 Homogeneous Subtraction Operator
Vector2 Vector2::operator -= (const Vector2& other)
{
	//X and y value subtracted to another by the x and y value inputed
	x -= other.x; y -= other.y;
	//Returns the x and y value
	return *this;
}

//Vector2 Homogeneous Multiplication Operator
Vector2 Vector2::operator*=(float scalar)
{
	//X and y value Multiplied to another by the scalar value inputed
	x *= scalar; y *= scalar;
	//Returns the x and y value
	return *this;
}

//Vector2 Homogeneous Division Operator
Vector2 Vector2::operator /= (float scalar)
{
	//X and y value Divided to another by the scalar value inputed
	x /= scalar; y /= scalar;
	//Returns the x and y value
	return *this;
}

//Vector2 Homogeneous Addition Operator
Vector2 Vector2::operator+=(const Vector2 & other)
{
	//X and y value Added to another by the x and y value inputed
	x += other.x; y += other.y;
	//Returns the x and y value
	return *this;
}

//Vector2 Friend Multiplication Operator
Vector2 operator*(float scalar, const Vector2 & other)
{
	//Returns the x and y value multiplied by the scalar value inputed
	return { other.x * scalar, other.y * scalar };
}

//Vector2 Friend Division Operator
Vector2 operator/(float scalar, const Vector2 & other)
{
	//Returns the x and y value multiplied by the scalar value inputed
	return { other.x / scalar, other.y / scalar };
}

//Vector2 Friend Subtraction Operator
Vector2 operator-(float scalar, const Vector2 & other)
{
	//Returns the x and y value added by the scalar value inputed
	return { other.x - scalar, other.y - scalar };
}

//Vector2 Friend Addition Operator
Vector2 operator+(float scalar, const Vector2 & other)
{
	//Returns the x and y value added by the scalar value inputed
	return { other.x + scalar, other.y + scalar };
}

//Making Vector2 of unit-length
Vector2 Vector2::normalise() const
{
	//Nrm holds the equation of x * x and y * y and then square rooted
	float nrm = sqrt(x * x + y * y);
	//X and Y are divided and added on by nrm 
	return { x / nrm, y / nrm };
}

//Finding the length of Vector2
float Vector2::magnitude() const
{
	//Returns the Square Root of x * x plus y * y
	return sqrt(x * x + y * y);
}

//Finding the distance between two points of Vector2
float Vector2::distance(const Vector2 & other) const
{
	//Diffx and DiffY hold the x and y value minused the x and y value inputed
	float diffX = x - other.x;
	float diffY = y - other.y;
	//Returns the square root of diffx * diffx plus diffy * diffy
	return sqrt(diffX * diffX + diffY * diffY);
}

//Projecting another vector onto another
float Vector2::dot(const Vector2& other) const
{
	//Returns x  and y times the x and y inputed
	return x * other.x + y * other.y;
}

//Vector2 Array Operator
float Vector2::operator[](int index)
{
	//Returns the data array with the index inputed
	return data[index];
}

//Vector2 Explicit Array Operator
Vector2::operator float*()
{
	//Returns Data array
	return data;
}
