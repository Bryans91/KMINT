#include "Vector2.h"
#include <Math.h>


Vector2::Vector2()
{
	this->x = 0;
	this->y = 0;
}

Vector2::Vector2(float x, float y)
{
	this->x = x;
	this->y = y;
}

float Vector2::getX() const
{
	return x;
}

float Vector2::getY() const
{
	return y;
}

void Vector2::setX(float x)
{
	this->x = x;
}

void Vector2::setY(float y)
{
	this->y = y;
}

void Vector2::truncate(float maxValue)
{
	if (getLength() > maxValue)
	{
		Vector2 normalized = this->normalized();
		Vector2 scaled = normalized * maxValue;
		this->x = scaled.getX();
		this->y = scaled.getY();
	}
}

Vector2 Vector2::normalized()
{
	return Vector2(this->x, this->y) / getLength();
}

Vector2 Vector2::opposite()
{
	return Vector2(-x, -y);
}

float Vector2::getLength()
{
	return sqrt(this->x * this->x + this->y * this->y);
}

float Vector2::distanceTo(const Vector2 & destination)
{
	float differenceX = this->x - destination.getX();
	float differenceY = this->y - destination.getY();
	if (isnan(x) || isnan(y))
	{
		std::cout << "Vector2 contains value which is not a number";
	}
	int i = abs(differenceX*differenceX + differenceY * differenceY);
	float distance = sqrt(i);
	return fabs(distance);
}

Vector2& Vector2::operator+=(const Vector2& toAdd)
{
	x += toAdd.getX();
	y += toAdd.getY();
	if (isnan(x) || isnan(y))
	{
		std::cout << "Vector2 contains value which is not a number";
	}
	return *this;
}

Vector2 Vector2::operator+(const Vector2 & toAdd)
{
	int x = this->x + toAdd.getX();
	int y = this->y + toAdd.getY();
	return Vector2(x, y);
}

Vector2 Vector2::operator-(const Vector2 & toSubstract)
{
	int x = this->x - toSubstract.getX();
	int y = this->y - toSubstract.getY();
	return Vector2(x, y);
}

Vector2 Vector2::operator-=(const Vector2 & toSubstract)
{
	this->x -= toSubstract.getX();
	this->y -= toSubstract.getY();
	if (isnan(x) || isnan(y))
	{
		std::cout << "Vector2 contains value which is not a number";
	}
	return *this;
}

Vector2 Vector2::operator/(const float scalar)
{
	if (scalar == 0)
	{
		return Vector2(this->x, this->y);
	}

	float x = this->x / scalar;
	float y = this->y / scalar;

	if (isnan(x) || isnan(y))
	{
		std::cout << "Vector2 contains value which is not a number";
	}
	return Vector2(this->x, this->y);
}

Vector2 Vector2::operator*(const float scalar)
{
	float x = this->x * scalar;
	float y = this->y * scalar;

	if (isnan(x) || isnan(y))
	{
		std::cout << "Vector2 contains value which is not a number";
	}
	return Vector2(x, y);
}


Vector2 & Vector2::operator*=(const float scalar)
{
	x = this->x * scalar;
	y = this->y * scalar;
	if (isnan(x) || isnan(y))
	{
		std::cout << "Vector2 contains value which is not a number";
	}
	return *this;
}

std::ostream & Vector2::operator<<(std::ostream & os)
{
	os.put(x);
	os.put(',');
	os.put(y);
	os.flush();
	return os;
}

std::ostream & operator<<(std::ostream & os, const Vector2 & vector)
{
	if (isnan(vector.x) || isnan(vector.y))
	{
		os << "Vector2 contains value which is not a number";
	}
	os << vector.x << " , " << vector.y;
	return os;
}