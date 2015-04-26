#include "Graph.h"

Vertex::Vertex(vector<Car> cars) {
	this->cars = cars;
	full = false;
	incomplete = false;
	entrance = false;
}

Vertex::~Vertex() {
}

vector<Edge> Vertex::getEdges() {
	return edges;
}

void Vertex::addEdge(Vertex* dest, int weight) {
	Edge newEdge(dest, weight);
	edges.push_back(newEdge);
}

bool Vertex::isEntrance() const {
	return entrance;
}

void Vertex::setEntrance(bool entrance) {
	this->entrance = entrance;
}

bool Vertex::isFull() const {
	return full;
}

void Vertex::setFull(bool full) {
	this->full = full;
}

bool Vertex::isIncomplete() const {
	return incomplete;
}

void Vertex::setIncomplete(bool incomplete) {
	this->incomplete = incomplete;
}

bool Vertex::isVisited() const {
	return visited;
}

void Vertex::setVisited(bool visited) {
	this->visited = visited;
}

int Vertex::removeEdgeTo(Vertex* d) {
	typename vector<Edge>::iterator it = edges.begin();
	//typename vector<Edge<T> >::iterator it2 = edges.end();

	while (it != edges.end()) {
		if (it->dest == d) {
			edges.erase(it);

			return it->weight;
		} else
			it++;
	}
	return 0;
}

Edge::Edge(Vertex* d, int weight) {
	this->dest = d;
	this->weight = weight;
}

Vertex* Edge::getDest() {
	return dest;
}

int Edge::getWeight() {
	return weight;
}


