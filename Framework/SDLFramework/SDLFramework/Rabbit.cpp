#include "Rabbit.h"
#include "Utilities.h"

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

	this->setHeading(Utilities::randomFloat(-1, 1));

}


Rabbit::~Rabbit()
{
}

void Rabbit::draw(FWApplication* application)
{
	application->SetColor(Color(255, 255, 255, 255));
	application->DrawRect(this->mX, this->mY, this->mWidth, this->mHeight, true);
}

void Rabbit::applyWander()
{
	//first, add a small random vector to the targets position (RandomClamped
	////returns a value between -1 and 1)
	//m_wanderTarget += Vector2D(GenerateRandom(-1, 1) * m_wanderJitter,
	//	GenerateRandom(-1, 1) * m_wanderJitter);

	////reproject this new vector back onto a unit circle
	//m_wanderTarget.normalized();

	////increase the length of the vector to the same as the radius
	////of the wander circle
	//m_wanderTarget *= m_wanderRadius;

	////move the target into a position WanderDist in front of the agent
	//Vector2D targetLocal = m_wanderTarget + Vector2D(m_wanderDistance, 0);

	
}

//setting angle UNUSED
void Rabbit::setHeading(float radian)
{
	this->m_Heading.setX(cos(radian));
	this->m_Heading.setY(sin(radian));
}

Vector2 Rabbit::set_acceleration(Vector2 force)
{
	//check for max speed
	return force / this->m_Mass;
}

void Rabbit::set_velocity(Vector2 acceleration, float dt)
{	
	this->m_Velocity = this->m_Velocity + acceleration * dt;
}

void Rabbit::set_position(Vector2 velocity, float dt)
{
	// std::cout << velocity << "\n";
	this->mX = this->mX + velocity.getX() * dt;
	this->mY = this->mY + velocity.getY() * dt;
}

void Rabbit::Update(float deltaTime)
{	
	//acceleration
	Vector2 force(Utilities::randomFloat(-800, 800), Utilities::randomFloat(-800, 800));
	//std::cout << "Force: " << force << "\n";
	Vector2 acceleration = set_acceleration(force);
	//std::cout << "Acceleration: " << acceleration << "\n";
	set_velocity(acceleration, deltaTime);
	//std::cout << "Velocity: " << this->m_Velocity << "\n";
	set_position(this->m_Velocity, deltaTime);
	//std::cout << "X/Y: " << this->mX << " / " << this->mY << "\n";
	//std::cout << "\n\n";


	IGameObject::mX = this->mX;
	IGameObject::mY = this->mY;
}
