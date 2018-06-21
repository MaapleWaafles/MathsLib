#include "Matrix3.h"
//Cmath is included to use math functions
#include <cmath>

// create a static const identity matrix const 
const Matrix3 Matrix3::identity = Matrix3(1, 0, 0, 0, 1, 0, 0, 0, 1);

//Matrix3 Constructor
Matrix3::Matrix3()
{
	//For each time i is lesser than 9, increment by 1
	for (int i = 0; i < 9; i++)
	{
		//Set all axis indexs to 0
		axis[i] = 0;
	}
}

//Matrix3 Copy Constructor Holding the x, y and z positions to be passed into 
Matrix3::Matrix3(float ax, float ay, float az, float bx, float by, float bz, float cx, float cy, float cz)
{
	//Assigns The array indexes to its holding positions
	axis[0] = ax;
	axis[1] = ay;
	axis[2] = az;
	axis[3] = bx;
	axis[4] = by;
	axis[5] = bz;
	axis[6] = cx;
	axis[7] = cy;
	axis[8] = cz;
}

//Matrix3 Copy Constructor that references back of Matrix3 type
Matrix3::Matrix3(const Matrix3 & other)
{
	//Declares the axis array of type Matrix3
	axis[0] = other.axis[0];
	axis[1] = other.axis[1];
	axis[2] = other.axis[2];
	axis[3] = other.axis[3];
	axis[4] = other.axis[4];
	axis[5] = other.axis[5];
	axis[6] = other.axis[6];
	axis[7] = other.axis[7];
	axis[8] = other.axis[8];
}

//Matrix3 Deconstructor
Matrix3::~Matrix3()
{
}

//Matrix3 Array Operator
Vector3& Matrix3::operator[](int index)
{
	//Returns the axis array of Vector3 type with the index inputed
	return axisV3[index];
}

//Matrix3 Explicit Array Operator
Matrix3::operator float*()
{
	//Returns Axis array
	return axis;
}

//Sets how wide and long the matrix is
void Matrix3::setScaled(float x, float y, float z)
{
	*this = { x, 0, 0,
			 0, y, 0,
			 0, 0, z };
}

void Matrix3::scale(float x, float y, float z)
{
	Matrix3 m;
	m.setScaled(x, y, z);

	*this = *this * m;
}

//Flips the Elements of a matrix between rows and columns
Matrix3 Matrix3::Transpose()
{
	//Returns the Matrix in column form
	return Matrix3(axis[0], axis[1], axis[2], axis[3], axis[4], axis[5], axis[6], axis[7], axis[8]);
}

//Matrix3 = Matrix3 Type Operator
Matrix3& Matrix3::operator=(const Matrix3 & m_matrix)
{
	//Sets the axis values to matrix type axis values
	axis[0] = m_matrix.axis[0]; axis[1] = m_matrix.axis[1]; axis[2] = m_matrix.axis[2],
	axis[3] = m_matrix.axis[3]; axis[4] = m_matrix.axis[4]; axis[5] = m_matrix.axis[5],
	axis[6] = m_matrix.axis[6]; axis[7] = m_matrix.axis[7]; axis[8] = m_matrix.axis[8];
	//Returns all the axis
	return *this;
}

//Matrix3 Multiplication of Matrix3
Matrix3 Matrix3::operator*(const Matrix3 & a_matrix) const
{
	//Returns the 3X3 Matrix that has multiplied and added its values
	Matrix3 result;
	result.axis[0] = axis[0] * a_matrix.axis[0] + axis[3] * a_matrix.axis[1] + axis[6] * a_matrix.axis[2];
	result.axis[3] = axis[0] * a_matrix.axis[3] + axis[3] * a_matrix.axis[4] + axis[6] * a_matrix.axis[5];
	result.axis[6] = axis[0] * a_matrix.axis[6] + axis[3] * a_matrix.axis[7] + axis[6] * a_matrix.axis[8];
	result.axis[1] = axis[1] * a_matrix.axis[0] + axis[4] * a_matrix.axis[1] + axis[7] * a_matrix.axis[2];
	result.axis[4] = axis[1] * a_matrix.axis[3] + axis[4] * a_matrix.axis[4] + axis[7] * a_matrix.axis[5];
	result.axis[7] = axis[1] * a_matrix.axis[6] + axis[4] * a_matrix.axis[7] + axis[7] * a_matrix.axis[8];
	result.axis[2] = axis[2] * a_matrix.axis[0] + axis[5] * a_matrix.axis[1] + axis[8] * a_matrix.axis[2];
	result.axis[5] = axis[2] * a_matrix.axis[3] + axis[5] * a_matrix.axis[4] + axis[8] * a_matrix.axis[5];
	result.axis[8] = axis[2] * a_matrix.axis[6] + axis[5] * a_matrix.axis[7] + axis[8] * a_matrix.axis[8];
	return result;
}

//Matrix3 Transformation to Vector3
Vector3 Matrix3::operator*(const Vector3 & a_vector) const
{
	//Returns the axis values that are multiplied and added of type vector 
	return Vector3(axis[0] * a_vector.x + axis[3] * a_vector.y + axis[6] * a_vector.z,
		           axis[1] * a_vector.x + axis[4] * a_vector.y + axis[7] * a_vector.z,
		           axis[2] * a_vector.x + axis[5] * a_vector.y + axis[8] * a_vector.z);
}

//Sets the Rotation for Point X
void Matrix3::setRotateX(float radians)
{
	//Set Axis points to the corresponding cos/sin functions needed
	axis[0] = { 1.0f };
	axis[1] = { 0.0f };
	axis[2] = { 0.0f };
	axis[3] = { 0.0f };
	axis[4] = { cosf(radians) };
	axis[5] = { sinf(radians) };
	axis[6] = { 0.0f };
	axis[7] = { -sinf(radians) };
	axis[8] = { cosf(radians) };
}

//Sets the Rotation for Point Y
void Matrix3::setRotateY(float radians)
{
	//Set Axis points to the corresponding cos/sin functions needed
	axis[0] = { cosf(radians) };
	axis[1] = { 0.0f };
	axis[2] = { -sinf(radians) };
	axis[3] = { 0.0f };
	axis[4] = { 1.0f };
	axis[5] = { 0.0f };
	axis[6] = { sinf(radians) };
	axis[7] = { 0.0f };
	axis[8] = { cosf(radians) };
}

//Sets the Rotation for Point Z
void Matrix3::setRotateZ(float radians)
{
	//Set Axis points to the corresponding cos/sin functions needed
	axis[0] = { cosf(radians) };
	axis[1] = { sinf(radians) };
	axis[2] = { 0.0f };
	axis[3] = { -sinf(radians) };
	axis[4] = { cosf(radians) };
	axis[5] = { 0.0f };
	axis[6] = { 0.0f };
	axis[7] = { 0.0f };
	axis[8] = { 1.0f };
}

//Rotates Point X to the position entered
void Matrix3::rotateX(float radians)
{
	//Uses the SetRotate Function to rotate x
	Matrix3 mX;
	mX.setRotateX(radians);
	//Returns X
	*this = *this * mX;
}

//Rotates Point Y to the position entered
void Matrix3::rotateY(float radians)
{
	//Uses the SetRotate Function to rotate y
	Matrix3 mY;
	mY.setRotateY(radians);
	//Returns Y
	*this = *this * mY;
}

//Rotates Point Z to the position entered
void Matrix3::rotateZ(float radians)
{
	//Uses the SetRotate Function to rotate z
	Matrix3 mZ;
	mZ.setRotateZ(radians);
	//Returns Z
	*this = *this * mZ;
}

void Matrix3::translate(float x, float y)
{
	Translate += Vector3(x, y, 0);
}
