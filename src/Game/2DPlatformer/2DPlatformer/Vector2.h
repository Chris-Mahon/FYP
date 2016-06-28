#pragma once
#include "stdafx.h"
class Vector2
{
public:
	double x, y;
	Vector2(double tX, double tY);
	Vector2();
	~Vector2();
	double Distance(Vector2);
	double DiffX(Vector2);
	double DiffY(Vector2);

	Vector2 operator+(Vector2);
	Vector2 operator+(int);
	Vector2 operator+(float);

	void operator+=(Vector2);
	void operator+=(int);
	void operator+=(float); 

	Vector2 operator-(Vector2);
	Vector2 operator-(int);
	Vector2 operator-(float);

	Vector2 operator*(Vector2);
	Vector2 operator*(int);
	Vector2 operator*(float);

	Vector2 operator/(Vector2);
	Vector2 operator/(int);
	Vector2 operator/(float);

	Vector2 SetValues(double x, double y);
	Vector2 SetValues(Vector2);
};

