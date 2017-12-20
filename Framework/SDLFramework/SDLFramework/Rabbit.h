#pragma once
#include "Vector2.h"
#include "FWApplication.h"
//FORCE DRIVEN ENTITY
class Rabbit
{
public:
	Rabbit();
	Rabbit(int x, int y, float cohesion,float seperation,float alignment,float m_Mass,float m_MaxSpeed,float m_MaxTurnrate);
	~Rabbit();

	void draw(FWApplication* application);

private:
	//functions
	void wander();


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
	int width = 5;
	int height = 5;
	
	int posX;
	int posY;
};

