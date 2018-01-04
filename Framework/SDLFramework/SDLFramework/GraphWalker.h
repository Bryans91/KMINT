#include <memory>
#include <iostream>

class Vertex;
#pragma once
class GraphWalker
{
public:
	GraphWalker();
	virtual ~GraphWalker();


	char getType() const { return this->type; }
	void setType(char t) { this->type = t; }

	std::shared_ptr<Vertex> getPosition() const { return this->position; }
	void setPosition(std::shared_ptr<Vertex> position) { this->position = position; }

private:
	char type;  //D = dog H = human
	std::shared_ptr<Vertex> position;
};

