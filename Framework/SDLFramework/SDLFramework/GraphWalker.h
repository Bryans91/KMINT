#include <memory>
#include <iostream>

class Vertex;
#pragma once
class GraphWalker :
	public std::enable_shared_from_this<GraphWalker>
{
public:
	GraphWalker();
	virtual ~GraphWalker();


	char getType() const { return this->type; }
	void setType(char t) { this->type = t; }

	std::shared_ptr<Vertex> getPosition() const { return this->position; }
	virtual void setPosition(std::shared_ptr<Vertex> position);
	virtual void update(int frame) {};

private:
	char type;  //D = dog H = human
	std::shared_ptr<Vertex> position;
};