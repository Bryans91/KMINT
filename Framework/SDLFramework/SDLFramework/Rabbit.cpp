#include "Rabbit.h"
#include "Utilities.h"

Rabbit::Rabbit()
{
}

Rabbit::Rabbit(int x, int y, float cohesion, float seperation, float alignment, float m_Mass, float m_MaxSpeed, float m_MaxTurnrate)
{
	this->position = Vector2(x, y);
	this->cohesion = cohesion;
	this->seperation = seperation;
	this->alignment = alignment;
	this->m_Mass = m_Mass;
	this->m_MaxSpeed = m_MaxSpeed;
	this->m_MaxTurnrate = m_MaxTurnrate;

	IGameObject::mWidth = this->mWidth;
	IGameObject::mHeight = this->mHeight;


	this->viewRange = 35;

	
}


Rabbit::~Rabbit()
{
}

void Rabbit::draw(FWApplication* application)
{
	application->SetColor(Color(255, 255, 255, 255));
	application->DrawRect(this->position.getX(), this->position.getY(), this->mWidth, this->mHeight, true);
}


void Rabbit::randomForce()
{
	this->acceleration = Vector2(Utilities::randomFloat(-5,4), Utilities::randomFloat(-5,4));
}

void Rabbit::Update(float deltaTime)
{	
	Vector2 sep = applySeperation();   // Separation
	Vector2 ali = applyAlignment();      // Alignment
	Vector2 coh = applyCohesion();   // Cohesion


	//edit vectors based on properties
	sep *= this->seperation;
	ali *= this->alignment;
	coh *= this->cohesion;


//	std::cout << sep << " - " << ali << " - " << coh << "\n";

	//add vectors to acceleration
	this->acceleration += sep;
	this->acceleration += ali;
	this->acceleration += coh;

	//std::cout<< " Pre " << this->acceleration << "\n";

	if (this->leader) {
		this->randomForce();
	}
	
	this->position += this->acceleration.normalized();

	

	
	IGameObject::mX = this->position.getX();
	IGameObject::mY = this->position.getY();
}

Vector2 Rabbit::applySeperation()
{
	float desiredseparation = this->viewRange;
	Vector2 steer;
	int count = 0;
	// For every boid in the system, check if it's too close
	for (Rabbit* other : *this->rabbits) {
		float d = this->position.distanceTo(other->position);
		// If the distance is greater than 0 and less than an arbitrary amount (0 when you are yourself)
		if ((d > 0) && (d < desiredseparation)) {
			
			// Calculate vector pointing away from neighbor
			Vector2 diff = position - other->position;
			diff = diff.normalized();
			diff = diff / d;        // Weight by distance
			steer+= diff;
			count++;            // Keep track of how many
		}
	}
	// Average -- divide by how many
	if (count > 0) {
		steer = steer / count;
	}

	// As long as the vector is greater than 0
	if (steer.getLength() > 0) {
	
		steer = steer.normalized();
		steer *= this->m_MaxSpeed;
		steer -= this->velocity;
		steer.truncate(this->m_MaxSpeed);
	}
	return steer;
}

Vector2 Rabbit::applyCohesion()
{
	float neighbordist = this->viewRange;
	Vector2 sum =  Vector2(0, 0);   // Start with empty vector to accumulate all positions
	int count = 0;
	for (Rabbit* other : *this->rabbits) {
		float d = position.distanceTo(other->position);

	//	std::cout << "required distance: " << neighbordist << " - Distance: " << d << " \n";
		if ((d > 0) && (d < neighbordist)) {
			sum+= other->position; // Add position
			count++;
		}
	}



	if (count > 0) {
		sum = sum / count;
	
		return seek(sum);  // Steer towards the position
	}
	else {
		return Vector2(0,0);
	}
}

Vector2 Rabbit::applyAlignment()
{
	float neighbordist = this->viewRange;
	Vector2 sum = Vector2(0, 0);
	int count = 0;
	for (Rabbit* other : *this->rabbits) {
		float d = position.distanceTo(other->position);
		if ((d > 0) && (d < neighbordist)) {
			sum += other->velocity;
			count++;
		}
		
	}
	if (count > 0) {
		sum = sum / (float)count;
		
		sum = sum.normalized();
		sum *= this->m_MaxSpeed;
		Vector2 steer = sum - this->velocity;
		steer.truncate(this->m_MaxForce);

		return steer;
	}
	else {
		return Vector2(0, 0);
	}
}

Vector2 Rabbit::seek(Vector2 target )
{
	Vector2 desired =  target - this->position;  // A vector pointing from the position to the target
	// Scale to maximum speed
	desired = desired.normalized();
	desired *= this->m_MaxSpeed;

	// Steering = Desired minus Velocity
	Vector2 steer = desired - this->velocity;
	
	// Limit to maximum steering force
	steer.truncate(this->m_MaxTurnrate);  
	return steer;
}
