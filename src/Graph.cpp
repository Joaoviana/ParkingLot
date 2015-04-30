#include "Graph.h"

Vertex::Vertex(vector<Car> cars, string id) {
	this->cars = cars;
	this->id = id;
	full = false;
	incomplete = false;
	visited = false;
}

Vertex::Vertex(string id) {
	this->id = id;
}

Vertex::~Vertex() {
}

vector<string> splitString(string input, string delimiter) {
	vector<string> output;
	size_t start = 0;
	size_t end = 0;

	while (start != string::npos && end != string::npos) {
		start = input.find_first_not_of(delimiter, end);

		if (start != string::npos) {
			end = input.find_first_of(delimiter, start);

			if (end != string::npos) {
				output.push_back(input.substr(start, end - start));
			} else {
				output.push_back(input.substr(start));
			}
		}
	}
	return output;
}
vector<Edge> Vertex::getEdges() {
	return edges;
}

void Graph::createVertexes(ParkingLot p) {
	string l = "L";
	string e = "E";
	for (int i = 0; i < p.getParkingPlace(); i++) {
		string finalID = l.append(to_string(i + 1));
		Vertex* v = new Vertex(finalID);
		vertexSet.push_back(v);
		l = "L";
	}
	for (int j = 0; j < p.getEntrance(); j++) {
		string finalID = e.append(to_string(j + 1));
		Vertex* v = new Vertex(finalID);
		v->setEntrance(true);
		vertexSet.push_back(v);
		e = "E";
	}
}

void Graph::connectVertexes() {
	ParkingLot p;
	ifstream file("parkingTest.txt");
	string line, nrOfEntraces, nrOfLots, ent, lot, src, dest, weight;
	vector<string> s, s1;
	while (!file.eof()) {
		getline(file, nrOfEntraces);
		int entrances = atoi(nrOfEntraces.c_str());
		for (int i = 0; i < entrances; i++) {
			getline(file, ent);
			Vertex* v = new Vertex(ent);
			//vertexSet.push_back(v);
		}
		getline(file, nrOfLots);
		int lots = atoi(nrOfLots.c_str());
		for (int i = 0; i < lots; i++) {
			getline(file, line);
			s = splitString(line, ",");
			src = s[0];
			cout << src << "  " << s.size() << endl;
			for (int i = 1; i < s.size(); i++) {
				s1 = splitString(s[i], "-");
				dest = s1[0];
				weight = s1[1];
				int weigthInt = atoi(weight.c_str());
				Vertex* vertexSrc = findVertex(src);
				Vertex* vertexDest = findVertex(dest);
				addEdge(vertexSrc, vertexDest, weigthInt);

			}
			Vertex* vertexSrc = findVertex(src);
			cout << src << "  " << vertexSrc->getEdges().size() << endl;
		}
	}
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

Vertex::Vertex() {
}

int Vertex::getDistanceToSource() const {
	return distanceToSource;
}

void Vertex::setDistanceToSource(int distanceToSource) {
	this->distanceToSource = distanceToSource;
}

void Vertex::addCar(Car car) {
	cars.push_back(car);
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

string Vertex::getID() {
	return id;
}

bool Graph::addEdge(Vertex* src, Vertex* dest, int w) {
	typename vector<Vertex*>::iterator it = vertexSet.begin();
	//typename std::vector<Vertex<T>*>::iterator ite = vertexSet.end();

	int found = 0;
	Vertex *vS, *vD;
	while (found != 2 && it != vertexSet.end()) {
		if ((*it)->getID() == src->getID()) {
			vS = *it;
			found++;
		}
		if ((*it)->getID() == dest->getID()) {
			vD = *it;
			found++;
		}
		it++;
	}
	if (found != 2)
		return false;
	vS->addEdge(vD, w);
	vD->addEdge(vS,w);
	return true;
}

Vertex* Graph::findVertex(string id) {
	for (int i = 0; i < vertexSet.size(); i++) {
		if (id == vertexSet[i]->getID()) {
			return vertexSet[i];
		}
	}
}

void Graph::carsInPosition(ParkingLot pl, Vertex* entrance, vector<Car> cars) {

	vector<Vertex*> vertices = dijkstra(entrance);
	int carIndex = 0;

						int distance = 0;
	cout << "cars number " << cars.size() << endl;
	while (!cars.empty()) {
		int dist = 1000;
		int lotIndex;
		for (int i = 0; i < vertices.size(); i++) {
			if (vertices[i]->getDistanceToSource() < dist
					&& (!vertices[i]->isFull()) && (!vertices[i]->isEntrance())) {
				dist = vertices[i]->getDistanceToSource();
				lotIndex = i;
			}
		}
		Vertex* lot = vertices[lotIndex];
		for (int i = 0; i < vertexSet.size(); i++) {
			if (vertexSet[i]->getID() == lot->getID()) {
				Car c = cars[carIndex];
				vertexSet[i]->addCar(c);
				vertexSet[i]->setFull(true);
				vector<Car> plCars = pl.getCars();
				for (int i = 0; i < plCars.size(); i++) {
					Car plCar = plCars[i];
					if (plCar.getPlate() == c.getPlate()) {
						plCar.setDistanceToEntrance(dist);
						distance += plCar.getDistanceToEntrance();
						cout << "car distance: " << plCar.getDistanceToEntrance() << endl;
					}
					plCars[i] = plCar;
					pl.setCars(plCars);
				}

			}
		}
		cars.erase(cars.begin() + carIndex);
	}
	int time = distance/120;
	cout << "Parking Time: "<< time << " mins" << endl;
}

vector<Vertex*> Graph::dijkstra(Vertex* source) {
	vector<Vertex*> unvisited;
	vector<int> dist;
	for (int i = 0; i < vertexSet.size(); i++) {
		if (vertexSet[i]->getID() == source->getID()) {
			cout << i << endl;
			vertexSet[i]->setDistanceToSource(0);
		}
	}
	for (int i = 0; i < vertexSet.size(); i++) {
		if (vertexSet[i]->getID() != source->getID()) {
			vertexSet[i]->setDistanceToSource(1000);
		}
		unvisited.push_back(vertexSet[i]);
	}

	cout << unvisited.size() << endl;
	while (!unvisited.empty()) {
		int uIndex;
		uIndex = 0;
		for (int i = 0; i < unvisited.size(); i++) {
			if (unvisited[uIndex]->getDistanceToSource()
					> unvisited[i]->getDistanceToSource()) {
				uIndex = i;
			}
		}
		Vertex u = (*unvisited[uIndex]);
		for (int i = 0; i < unvisited.size(); i++) {
				cout <<unvisited[i]->getID() << endl;
			if (unvisited[i]->getID() == u.getID()) {
				cout << "11" << endl;
		cout << u.getEdges().size() << endl;
				unvisited.erase(unvisited.begin() + i);
				cout << unvisited.size() << endl;
				break;
			}
		}

		vector<Edge> edges = u.getEdges();
		for (int i = 0; i < edges.size(); i++) {
			if (!edges[i].getDest()->isEntrance()) {
				Vertex* v = edges[i].getDest();
				int vIndex = 0;
				for (int i = 0; i < vertexSet.size(); i++) {
					if (vertexSet[i]->getID() == v->getID()) {
						vIndex = i;
					}
				}
				int weight = edges[i].getWeight();
				int alt = vertexSet[uIndex]->getDistanceToSource() + weight;
				if (alt < vertexSet[vIndex]->getDistanceToSource()) {
					vertexSet[vIndex]->setDistanceToSource(alt);
				}
			}
		}
	}

	return vertexSet;

}

void Graph::parkCars(ParkingLot pl) {
	int ents = pl.getEntrance();
	for (int i = 0; i < ents; i++) {
		string ent = "E";
		int intnum = i + 1;
		string num = to_string(intnum);
		ent.append(num);
		vector<Car> cars = pl.getCars();
		vector<Car> entCars;
		for (int j = 0; j < cars.size(); j++) {
			Car car = cars[j];

			if (car.getEntrance() == ent)
				entCars.push_back(car);
		}
		for (int j = 0; j < vertexSet.size(); j++) {
			if (vertexSet[j]->getID() == ent) {
				carsInPosition(pl, vertexSet[j], entCars);
				break;
			}
		}
		ent = "E";
	}
}
