#include "Matrix2.h"
//Cmath is included to use math functions
#include <cmath>

//Matrix2 Constructor
Matrix2::Matrix2()
{
	//For each time i is lesser than 4, increment by 1
	for (int i = 0; i < 4; i++)
	{
		//Set all axis indexs to 0
		axis[i] = 0;
	}
}

//Matrix2 Copy Constructor Holding the x and y positions to be passed into 
Matrix2::Matrix2(float ax, float ay, float bx, float by)
{
	//Assigns The array indexes to its holding positions
	axis[0] = ax;
	axis[1] = ay;
	axis[2] = bx;
	axis[3] = by; 
}

//Matrix2 Copy Constructor that references back of Matrix2 type
Matrix2::Matrix2(const Matrix2 & other)
{
	//Declares the axis array of type Matrix2
	axis[0] = other.axis[0];
	axis[1] = other.axis[1];
	axis[2] = other.axis[2];
	axis[3] = other.axis[3];
}

//Matrix2 Deconstructor
Matrix2::~Matrix2()
{
}

//Matrix2 Array Operator
float Matrix2::operator[](int index)
{
	//Returns the axis array with the index inputed
	return axis[index];
}

//Matrix2 Explicit Array Operator
Matrix2::operator float*()
{
	//Returns the Axis array
	return axis;
}

//Created an unchanged matrix
Matrix2 Matrix2::Identity()
{
	// Sets Matrix2 to its corresponding values between 0 - 1
	return Matrix2(1.0f, 0.0f, 
		           0.0f, 1.0f);
}

//Flips the Elements of a matrix between rows and columns
Matrix2 Matrix2::Transpose()
{
	//Returns the Matrix in column form
	return Matrix2(axis[0],axis[1],axis[2],axis[3]);
}

//Matrix2 Multiplication of Matrix2
Matrix2 Matrix2::operator*(const Matrix2 & a_matrix) const
{
	//Returns the 2X2 Matrix that has multiplied and added its values
	return Matrix2(axis[0] * a_matrix.axis[0] + axis[1] * a_matrix.axis[2],
		           axis[0] * a_matrix.axis[1] + axis[1] * a_matrix.axis[3],
		           axis[2] * a_matrix.axis[0] + axis[3] * a_matrix.axis[2],
		           axis[2] * a_matrix.axis[1] + axis[3] * a_matrix.axis[3]);
}

//Matrix2 Transformation to Vector2
Vector2 Matrix2::operator*(const Vector2 & a_vector) const
{
	//Returns the axis values that are multiplied and added of type vector 
	return Vector2(axis[0] * a_vector.x + axis[2] * a_vector.y,
		           axis[1] * a_vector.x + axis[3] * a_vector.y);
}

//Sets the Rotation of The axis
void Matrix2::setRotate(float radians)
{
	//Set Axis points to the corresponding cos/sin functions needed
	axis[0] = { cosf(radians) };
	axis[1] = { sinf(radians) };
	axis[2] = { -sinf(radians) };
	axis[3] = { cosf(radians) };
}

