#include "Matrix4.h"
//Cmath is included to use math functions
#include <cmath>

//Matrix4 Constructor
Matrix4::Matrix4()
{
	//For each time i is lesser than 15, increment by 1
	for (int i = 0; i < 15; i++)
	{
		//Set all axis indexs to 0
		axis[i] = 0;
	}
}

//Matrix4 Copy Constructor Holding the x, y, z and w positions to be passed into 
Matrix4::Matrix4(float ax, float ay, float az, float aw, float bx, float by, float bz, float bw, float cx, float cy, float cz, float cw, float dx, float dy, float dz, float dw)
{
	//Assigns The array indexes to its holding positions
	axis[0] = ax;
	axis[1] = ay;
	axis[2] = az;
	axis[3] = aw;
	axis[4] = bx;
	axis[5] = by;
	axis[6] = bz;
	axis[7] = bw;
	axis[8] = cx;
	axis[9] = cy;
	axis[10] = cz;
	axis[11] = cw;
	axis[12] = dx;
	axis[13] = dy;
	axis[14] = dz;
	axis[15] = dw;
}

//Matrix4 Copy Constructor that references back of Matrix4 type
Matrix4::Matrix4(const Matrix4 & other)
{
	//Declares the axis array of type Matrix4
	axis[0] = other.axis[0];
	axis[1] = other.axis[1];
	axis[2] = other.axis[2];
	axis[3] = other.axis[3];
	axis[4] = other.axis[4];
	axis[5] = other.axis[5];
	axis[6] = other.axis[6];
	axis[7] = other.axis[7];
	axis[8] = other.axis[8];
	axis[9] = other.axis[9];
	axis[10] = other.axis[10];
	axis[11] = other.axis[11];
	axis[12] = other.axis[12];
	axis[13] = other.axis[13];
	axis[14] = other.axis[14];
	axis[15] = other.axis[15];
}

//Matrix4 Deconstructor
Matrix4::~Matrix4()
{
}

//Matrix4 Array Operator
Vector4& Matrix4::operator[](int index)
{
	//Returns the axis array of Vector3 type with the index inputed
	return axisV4[index];
}

//Matrix4 Explicit Array Operator
Matrix4::operator float*()
{
	//Returns Axis array
	return axis;
}

//Created an unchanged matrix
Matrix4 Matrix4::Identity()
{
	// Sets Matrix4 to its corresponding values between 0 - 1
	return Matrix4(1.0f, 0.0f, 0.0f, 0.0f, 
		           0.0f, 1.0f, 0.0f, 0.0f, 
		           0.0f, 0.0f, 1.0f, 0.0f,
	               0.0f, 0.0f, 0.0f, 1.0f);
}

//Flips the Elements of a matrix between rows and columns
Matrix4 Matrix4::Transpose()
{
	//Returns the Matrix in column form
	return Matrix4(axis[0], axis[1], axis[2], axis[3], 
		           axis[4], axis[5], axis[6], axis[7], 
		           axis[8], axis[9], axis[10], axis[11], 
		           axis[12], axis[13], axis[14], axis[15]);
}

//Matrix4 = Matrix4 Type Operator
Matrix4 & Matrix4::operator=(const Matrix4 & m_matrix)
{
	//Sets the axis values to matrix type axis values
	axis[0] = m_matrix.axis[0]; axis[1] = m_matrix.axis[1]; axis[2] = m_matrix.axis[2]; axis[3] = m_matrix.axis[3],
	axis[4] = m_matrix.axis[4]; axis[5] = m_matrix.axis[5]; axis[6] = m_matrix.axis[6]; axis[7] = m_matrix.axis[7],
	axis[8] = m_matrix.axis[8]; axis[9] = m_matrix.axis[9]; axis[10] = m_matrix.axis[10]; axis[11] = m_matrix.axis[11],
	axis[12] = m_matrix.axis[12]; axis[13] = m_matrix.axis[13]; axis[14] = m_matrix.axis[14]; axis[15] = m_matrix.axis[15];
	//Returns all the axis
	return *this;
}

//Matrix4 Multiplication of Matrix4
Matrix4 Matrix4::operator*(const Matrix4 & a_matrix) const
{
	//Returns the 4X4 Matrix that has multiplied and added its values
	Matrix4 result;
	result.axis[0] = axis[0] * a_matrix.axis[0] + axis[4] * a_matrix.axis[1] + axis[8] * a_matrix.axis[2] + axis[12] * a_matrix.axis[3];
	result.axis[4] = axis[0] * a_matrix.axis[4] + axis[4] * a_matrix.axis[5] + axis[8] * a_matrix.axis[6] + axis[12] * a_matrix.axis[7];
	result.axis[8] = axis[0] * a_matrix.axis[8] + axis[4] * a_matrix.axis[9] + axis[8] * a_matrix.axis[10] + axis[12] * a_matrix.axis[11];
	result.axis[12] = axis[0] * a_matrix.axis[12] + axis[4] * a_matrix.axis[13] + axis[8] * a_matrix.axis[14] + axis[12] * a_matrix.axis[15];
	result.axis[1] = axis[1] * a_matrix.axis[0] + axis[5] * a_matrix.axis[1] + axis[9] * a_matrix.axis[2] + axis[13] * a_matrix.axis[3];	
	result.axis[5] = axis[1] * a_matrix.axis[4] + axis[5] * a_matrix.axis[5] + axis[9] * a_matrix.axis[6] + axis[13] * a_matrix.axis[7];
	result.axis[9] = axis[1] * a_matrix.axis[8] + axis[5] * a_matrix.axis[9] + axis[9] * a_matrix.axis[10] + axis[13] * a_matrix.axis[11];	
	result.axis[13] = axis[1] * a_matrix.axis[12] + axis[5] * a_matrix.axis[13] + axis[9] * a_matrix.axis[14] + axis[13] * a_matrix.axis[15];
	result.axis[2] = axis[2] * a_matrix.axis[0] + axis[6] * a_matrix.axis[1] + axis[10] * a_matrix.axis[2] + axis[14] * a_matrix.axis[3];
	result.axis[6] = axis[2] * a_matrix.axis[4] + axis[6] * a_matrix.axis[5] + axis[10] * a_matrix.axis[6] + axis[14] * a_matrix.axis[7];
	result.axis[10] = axis[2] * a_matrix.axis[8] + axis[6] * a_matrix.axis[9] + axis[10] * a_matrix.axis[10] + axis[14] * a_matrix.axis[11];
	result.axis[14] = axis[2] * a_matrix.axis[12] + axis[6] * a_matrix.axis[13] + axis[10] * a_matrix.axis[14] + axis[14] * a_matrix.axis[15];
	result.axis[3] = axis[3] * a_matrix.axis[0] + axis[7] * a_matrix.axis[1] + axis[11] * a_matrix.axis[2] + axis[15] * a_matrix.axis[3];
	result.axis[7] = axis[3] * a_matrix.axis[4] + axis[7] * a_matrix.axis[5] + axis[11] * a_matrix.axis[6] + axis[15] * a_matrix.axis[7];
	result.axis[11] = axis[3] * a_matrix.axis[8] + axis[7] * a_matrix.axis[9] + axis[11] * a_matrix.axis[10] + axis[15] * a_matrix.axis[11];
	result.axis[15] = axis[3] * a_matrix.axis[12] + axis[7] * a_matrix.axis[13] + axis[11] * a_matrix.axis[14] + axis[15] * a_matrix.axis[15];
	return result;
}

//Matrix4 Transformation to Vector3
Vector4 Matrix4::operator*(const Vector4 & a_vector) const
{
	//Returns the axis values that are multiplied and added of type vector 
     return Vector4(axis[0] * a_vector.x + axis[4] * a_vector.y + axis[8] * a_vector.z + axis[12] * a_vector.w,
		            axis[1] * a_vector.x + axis[5] * a_vector.y + axis[9] * a_vector.z + axis[13] * a_vector.w,
	                axis[2] * a_vector.x + axis[6] * a_vector.y + axis[10] * a_vector.z + axis[14] * a_vector.w,
		            axis[3] * a_vector.x + axis[7] * a_vector.y + axis[11] * a_vector.z + axis[15] * a_vector.w);
}

//Sets the Rotation for Point X
void Matrix4::setRotateX(float radians)
{
	//Set Axis points to the corresponding cos/sin functions needed
	axis[0] = { 1.0f };
	axis[1] = { 0.0f };
	axis[2] = { 0.0f };
	axis[3] = { 0.0f };
	axis[4] = { 0.0f };
	axis[5] = { cosf(radians) };
	axis[6] = { sinf(radians) };
	axis[7] = { 0.0f };
	axis[8] = { 0.0f };
	axis[9] = { -sinf(radians) };
	axis[10] = { cosf(radians) };
	axis[11] = { 0.0f };
	axis[12] = { 0.0f };
	axis[13] = { 0.0f };
	axis[14] = { 0.0f };
	axis[15] = { 1.0f };
}

//Sets the Rotation for Point Y
void Matrix4::setRotateY(float radians)
{
	//Set Axis points to the corresponding cos/sin functions needed
	axis[0] = { cosf(radians) };
	axis[1] = { 0.0f };
	axis[2] = { -sinf(radians) };
	axis[3] = { 0.0f };
	axis[4] = { 0.0f };
	axis[5] = { 1.0f };
	axis[6] = { 0.0f };
	axis[7] = { 0.0f };
	axis[8] = { sinf(radians) };
	axis[9] = { 0.0f };
	axis[10] = { cosf(radians) };
	axis[11] = { 0.0f };
	axis[12] = { 0.0f };
	axis[13] = { 0.0f };
	axis[14] = { 0.0f };
	axis[15] = { 1.0f };
}

//Sets the Rotation for Point Z
void Matrix4::setRotateZ(float radians)
{
	//Set Axis points to the corresponding cos/sin functions needed
	axis[0] = { cosf(radians) };
	axis[1] = { sinf(radians) };
	axis[2] = { 0.0f };
	axis[3] = { 0.0f };
	axis[4] = { -sinf(radians) };
	axis[5] = { cosf(radians) };
	axis[6] = { 0.0f };
	axis[7] = { 0.0f };
	axis[8] = { 0.0f };
	axis[9] = { 0.0f };
	axis[10] = { 1.0f };
	axis[11] = { 0.0f };
	axis[12] = { 0.0f };
	axis[13] = { 0.0f };
	axis[14] = { 0.0f };
	axis[15] = { 1.0f };
}

//Rotates Point X to the position entered
void Matrix4::rotateX(float radians)
{
	//Uses the SetRotate Function to rotate x
	Matrix4 mX;
	mX.setRotateX(radians);
	//Returns X
	*this * mX;
}

//Rotates Point Y to the position entered
void Matrix4::rotateY(float radians)
{
	//Uses the SetRotate Function to rotate y
	Matrix4 mY;
	mY.setRotateY(radians);
	//Returns Y
	*this * mY;
}

//Rotates Point Z to the position entered
void Matrix4::rotateZ(float radians)
{
	//Uses the SetRotate Function to rotate z
	Matrix4 mZ;
	mZ.setRotateZ(radians);
	//Returns Z
	*this * mZ;
}
