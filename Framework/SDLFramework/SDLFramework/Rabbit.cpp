#include "Rabbit.h"

Rabbit::Rabbit()
{
}

Rabbit::Rabbit(int x, int y, float cohesion, float seperation, float alignment, float m_Mass, float m_MaxSpeed, float m_MaxTurnrate)
{
	this->mX = x;
	this->mY = y;
	this->cohesion = cohesion;
	this->seperation = seperation;
	this->alignment = alignment;
	this->m_Mass = m_Mass;
	this->m_MaxSpeed = m_MaxSpeed;
	this->m_MaxTurnrate = m_MaxTurnrate;

	IGameObject::mWidth = this->mWidth;
	IGameObject::mHeight = this->mHeight;

}


Rabbit::~Rabbit()
{
}

void Rabbit::draw(FWApplication* application)
{
	application->SetColor(Color(255, 255, 255, 255));
	application->DrawRect(this->mX, this->mY, this->mWidth, this->mHeight, true);
}

void Rabbit::wander()
{
	


	
}

//setting angle
void Rabbit::setHeading(float radian)
{

	this->m_Heading.setX(cos(radian));
	this->m_Heading.setY(sin(radian));
}

void Rabbit::Update(float deltaTime)
{	
	
	//testupdate
	this->mX = this->mX - 1;
	this->mY = this->mY - 1;

	IGameObject::mX = this->mX;
	IGameObject::mY = this->mY;
}
