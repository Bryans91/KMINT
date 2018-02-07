#pragma once
#include <iostream>

class Vector2
{
public:
	Vector2();
	Vector2(float x, float y);

	void setX(float x);
	float getX() const;

	void setY(float y);
	float getY() const;
	
	void truncate(float maxValue);

	float getLength();
	float distanceTo(const Vector2&);

	Vector2 normalized();
	Vector2 opposite();
	

	//Operators
	Vector2& operator+=(const Vector2&);
	Vector2 operator+(const Vector2&);
	Vector2 operator-(const Vector2&);
	Vector2 operator-=(const Vector2&);
	Vector2 operator/(const float);
	Vector2 operator*(const float);
	Vector2& operator*=(const float);
	//print operators
	friend std::ostream& operator<<(std::ostream& os, const Vector2& vector);
	std::ostream& operator<<(std::ostream&);
private:
	float x, y;
};