#pragma once
#include "Vector2.h"
#include "FWApplication.h"
#include "IGameObject.h"
#include <vector>
#include <memory>

//FORCE DRIVEN ENTITY
class Rabbit : public IGameObject
{
public:
	Rabbit();
	Rabbit(int x, int y, float cohesion,float seperation,float alignment,float m_Mass,float m_MaxSpeed,float m_MaxTurnrate);
	~Rabbit();

	bool leader = false;

	void draw(FWApplication* application);
	
	void setRabbits(std::shared_ptr<std::vector<Rabbit*>> rabbits) { this->rabbits = rabbits; }
	
	void randomForce();

	// Inherited via IGameObject
	virtual void Update(float deltaTime) override;

private:
	//functions

	Vector2 applySeperation();
	Vector2 applyCohesion();
	Vector2 applyAlignment();

	Vector2 seek(Vector2 target);


	float viewRange;

	//Properties
	float cohesion; //Bij de groep blijven 0 tot 1.0 
	float seperation; //Uit de buurt van anderen blijven 0 tot 1.0
	float alignment; //Zelfde kant als zijn buren 0 tot 1.0

	float dogAttract; //Aantrekking tot dog -1.0 tot 1.0
	float waterAttract; //Aantrekking tot water -1.0 tot 1.0


	//Forces
	Vector2 position;
	Vector2 velocity;
	Vector2 acceleration;
	
	float m_Mass;
	float m_MaxSpeed;
	float m_MaxForce;
	float m_MaxTurnrate;
	
	//rabbits collection
	std::shared_ptr<std::vector<Rabbit*>> rabbits;

	//for drawing
	bool mActive = true;
	int mWidth = 5;
	int mHeight = 5;
	
	int mX;
	int mY;
};

