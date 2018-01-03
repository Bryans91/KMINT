#pragma once
#include "Vector2.h"
#include "FWApplication.h"
#include "IGameObject.h"
//FORCE DRIVEN ENTITY
class Rabbit : public IGameObject
{
public:
	Rabbit();
	Rabbit(int x, int y, float cohesion,float seperation,float alignment,float m_Mass,float m_MaxSpeed,float m_MaxTurnrate);
	~Rabbit();

	void draw(FWApplication* application);
	// Inherited via IGameObject
	virtual void Update(float deltaTime) override;

	float RandomFloat(float a, float b) {
		float random = ((float)rand()) / (float)RAND_MAX;
		float diff = b - a;
		float r = random * diff;
		return a + r;
	}
private:
	//functions
	void wander();

	void setHeading(float radian);

	//Properties
	float cohesion; //Bij de groep blijven 0 tot 1.0
	float seperation; //Uit de buurt van anderen blijven 0 tot 1.0
	float alignment; //Zelfde kant als zijn buren 0 tot 1.0

	float dogAttract; //Aantrekking tot dog -1.0 tot 1.0
	float waterAttract; //Aantrekking tot water -1.0 tot 1.0


	//Forces
	Vector2 m_Velocity;
	Vector2 m_Heading;
	Vector2 m_Side;
	
	float m_Mass;
	float m_MaxSpeed;
	float m_MaxForce;
	float m_MaxTurnrate;

	//for drawing
	bool mActive = true;
	int mWidth = 5;
	int mHeight = 5;
	
	int mX;
	int mY;

	/*set_acceleration(force() / mass());
	set_velocity(velocity() + acceleration * dt);
	set_position(position() + velocity() * dt);*/
};

