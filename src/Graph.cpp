#include "Graph.h"

Vertex::Vertex(vector<Car> cars, string id) {
	this->cars = cars;
	this->id = id;
}

Vertex::Vertex(string id) {
	this->id = id;
}

Vertex::~Vertex() {
}

vector<Edge> Vertex::getEdges() {
	return edges;
}

void Vertex::loadVertex() {

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

Graph::Graph() {
}

Graph::~Graph() {
}

int Graph::getTotalWeight() {
	return totalweight;
}

void Graph::setTotalWeight(int w) {
	this->totalweight = w;
}

bool Graph::addVertex(vector<Car> cars) {
	typename vector<Vertex*>::iterator it = vertexSet.begin();
	//typename std::vector<Vertex<T>*>::iterator ite = vertexSet.end();

	for (; it != vertexSet.end(); it++)
		if ((*it)->cars == cars)
			return false;

	Vertex *v = new Vertex(cars);
	vertexSet.push_back(v);

	return false;
}

bool Graph::addEdge(const Vertex& source, const Vertex& dest, int w) {
	typename vector<Vertex*>::iterator it = vertexSet.begin();
	//typename std::vector<Vertex<T>*>::iterator ite = vertexSet.end();

	int found = 0;
	Vertex *vS, *vD;
	while (found != 2 && it != vertexSet.end()) {
		if ((*it)->info == source) {
			vS = *it;
			found++;
		}

		if ((*it)->info == dest) {
			vD = *it;
			found++;
		}

		it++;
	}

	if (found != 2)
		return false;

	vS->addEdge(vD, w);
	int currentweight = this->getTotalWeight();
	int newweight = currentweight + w;
	this->setTotalWeight(newweight);

	return true;
}

bool Graph::removeVertex(const Vertex& in) {
	typename vector<Vertex*>::iterator it = vertexSet.begin();
	typename vector<Vertex*>::iterator ite = vertexSet.end();

	for (; it != ite; it++) {
		// if found
		if ((*it)->info == in) {
			// temporarily save
			Vertex * v = *it;

			// delete
			vertexSet.erase(it);

			typename std::vector<Vertex*>::iterator it1 = vertexSet.begin();
			typename std::vector<Vertex*>::iterator it1e = vertexSet.end();

			for (; it1 != it1e; it1++)
				(*it1)->removeEdgeTo(v);

			delete v;
			return true;
		}
	}

	return false;
}

bool Graph::removeEdge(const Vertex& source, const Vertex& dest) {
	typename vector<Vertex*>::iterator it = vertexSet.begin();
	typename vector<Vertex*>::iterator ite = vertexSet.end();

	int found = 0;
	Vertex *vS, *vD;
	while (found != 2 && it != ite) {
		if ((*it)->info == source) {
			vS = *it;
			found++;
		}

		if ((*it)->info == dest) {
			vD = *it;
			found++;
		}

		it++;
	}

	if (found != 2)
		return false;

	int weight = vS->removeEdgeTo(vD);
	int currentweight = this->getTotalWeight();
	int newweight = currentweight + weight;
	this->setTotalWeight(newweight);
	return (weight == 0);
}
