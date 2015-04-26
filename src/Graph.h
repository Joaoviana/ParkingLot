#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string>
#include "Car.h"
#include "ParkingLot.h"

using namespace std;

class Edge;
class Graph;

//Lot
class Vertex {
public:
	Vertex(vector<Car> cars, string id);
	Vertex(string id);
	~Vertex();
	vector<Edge> getEdges();
	bool isEntrance() const;
	void setEntrance(bool entrance);
	bool isFull() const;
	void setFull(bool full);
	bool isIncomplete() const;
	void setIncomplete(bool incomplete);
	bool isVisited() const;
	void setVisited(bool visited);
	void loadVertex();
	friend class Graph;
private:
	vector<Edge> edges;
	bool visited;
	bool full, incomplete;
	bool entrance;
	vector<Car> cars;
	string id;
	void addEdge(Vertex *dest, int weight);
	int removeEdgeTo(Vertex *d);
};

class Edge {
	Vertex * dest;
	int weight;
public:
	Edge(Vertex *d, int weight);
	Vertex * getDest();
	int getWeight();
	friend class Graph;
	friend class Vertex;
	bool operator<(const Edge& e1) const;
};

class Graph {
	vector<Vertex *> vertexSet;
	int totalweight;

public:
	Graph();
	~Graph();
	int getTotalWeight();
	void setTotalWeight(int w);
	bool addVertex(vector<Car> cars);
	bool addEdge(const Vertex &source, const Vertex &dest, int w);
	bool removeVertex(const Vertex &in);
	bool removeEdge(const Vertex &source, const Vertex &dest);
};

