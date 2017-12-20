#include "Rabbit.h"



Rabbit::Rabbit()
{
}

Rabbit::Rabbit(int x, int y, float cohesion, float seperation, float alignment, float m_Mass, float m_MaxSpeed, float m_MaxTurnrate)
{
	this->posX = x;
	this->posY = y;
	this->cohesion = cohesion;
	this->seperation = seperation;
	this->alignment = alignment;
	this->m_Mass = m_Mass;
	this->m_MaxSpeed = m_MaxSpeed;
	this->m_MaxTurnrate = m_MaxTurnrate;
}


Rabbit::~Rabbit()
{
}

void Rabbit::draw(FWApplication* application)
{
	application->SetColor(Color(255, 255, 255, 255));
	application->DrawRect(this->posX, this->posY, this->width, this->height, true);

}

void Rabbit::wander()
{

}
