#pragma once
class GraphWalker
{
public:
	GraphWalker();
	virtual ~GraphWalker();


	char getType() const { return this->type; }
	void setType(char t) { this->type = t; }
private:
	char type;  //D = dog H = human
};

