#include "stdafx.h"
#include "Vector2.h"
#include <math.h>


Vector2::Vector2(double tX, double tY)
{
	x = tX;
	y = tY;
}

Vector2::Vector2()
{
	x = y = 0;
}

Vector2::~Vector2()
{

}

double Vector2::Distance(Vector2 vect2)
{
	float totalX, totalY, combination;
	totalX = pow(vect2.x - this->x, 2);
	totalY = pow(vect2.y - this->y, 2);
	combination = totalX + totalY;
	double dist = sqrt(combination);
	return dist;
}

double Vector2::DiffX(Vector2 vect2)
{
	double difference;
	difference = this->x - vect2.x; 
	return difference;
}

double Vector2::DiffY(Vector2 vect2)
{
	double difference;
	difference = this->y - vect2.y;
	return difference;
}

Vector2 Vector2::operator+(Vector2 other)
{
	double totX = this->x + other.x;
	double totY = this->y + other.y;
	return Vector2(totX, totY);
}

Vector2 Vector2::operator+(int adder)
{
	double totX = this->x + adder;
	double totY = this->y + adder;
	return Vector2(totX, totY);
}

Vector2 Vector2::operator+(float adder)
{
	double totX = this->x + adder;
	double totY = this->y + adder;
	return Vector2(totX, totY);
}

void Vector2::operator+=(Vector2 other)
{
	this->x = this->x + other.x;
	this->y = this->y + other.y;
}

void Vector2::operator+=(int adder)
{
	this->x = this->x + adder;
	this->y = this->y + adder;
}

void Vector2::operator+=(float adder)
{
	this->x = this->x + adder;
	this->y = this->y + adder;
}

Vector2 Vector2::operator-(Vector2 other)
{
	double totX = this->x - other.x;
	double totY = this->y - other.y;
	return Vector2(totX, totY);
}

Vector2 Vector2::operator-(int adder)
{
	double totX = this->x - adder;
	double totY = this->y - adder;
	return Vector2(totX, totY);
}

Vector2 Vector2::operator-(float adder)
{
	double totX = this->x - adder;
	double totY = this->y - adder;
	return Vector2(totX, totY);
}

Vector2 Vector2::operator*(Vector2 other)
{
	double totX = this->x * other.x;
	double totY = this->y * other.y;
	return Vector2(totX, totY);
}

Vector2 Vector2::operator*(int adder)
{
	double totX = this->x * adder;
	double totY = this->y * adder;
	return Vector2(totX, totY);
}

Vector2 Vector2::operator*(float adder)
{
	double totX = this->x * adder;
	double totY = this->y * adder;
	return Vector2(totX, totY);
}

Vector2 Vector2::operator/(Vector2 other)
{
	double totX = this->x / other.x;
	double totY = this->y / other.y;
	return Vector2(totX, totY);
}

Vector2 Vector2::operator/(int adder)
{
	double totX = this->x / adder;
	double totY = this->y / adder;
	return Vector2(totX, totY);
}

Vector2 Vector2::operator/(float adder)
{
	double totX = this->x / adder;
	double totY = this->y / adder;
	return Vector2(totX, totY);
}


Vector2 Vector2::SetValues(double x, double y)
{
	return Vector2(x, y);
}

Vector2 Vector2::SetValues(Vector2 newVals)
{
	return newVals;
}