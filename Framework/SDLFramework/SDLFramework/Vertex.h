#pragma once
#ifndef VERTEX_H
#define VERTEX_H

#include "GraphWalker.h"
#include <vector>
#include <memory>
#include "Edge.h"

class Edge;

class Vertex
{
public:
	Vertex();
	~Vertex();

	//normal var operator
	bool operator==(const Vertex& rhs) const {
		return (this->x == rhs.x && this->y == rhs.y);
	}
	//std::shared_ptr<Vertex>
	//shared pointer operator
	bool operator==(const std::shared_ptr<Vertex>& rhs) {
		return (this->x == rhs->getX() && this->y == rhs->getY());
	};


	std::vector<std::shared_ptr<Edge>> getNeighbors() { return this->neighbors; }
	void addNeighbor(std::shared_ptr<Edge> e);
	
	std::shared_ptr<GraphWalker> walker = nullptr;

	//getters/setters
	void setGrass(bool w) { this->grass = w; }
	bool isGrass() const { return this->grass; }

	void setCave(const bool w) { this->cave = w; }
	bool isCave() const { return this->cave; }

	void setWater(bool w) { this->water = w; }
	bool isWater() const { return this->water; }

	void setX(int x) { this->x = x; }
	int getX() const { return this->x; }

	void setY(int y) { this->y = y; }
	int getY() const { return this->y; }

	std::shared_ptr<Vertex> next = nullptr;

private:
	std::vector<std::shared_ptr<Edge>> neighbors;
	int x;
	int y;

	bool water = false;
	bool cave = false;
	bool grass = false;
};

#endif