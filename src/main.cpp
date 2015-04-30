#include <iostream>
#include <string>
#include <cstdlib>
#include "ParkingLot.h"
#include "Car.h"
#include "Graph.h"

using namespace std;

int main() {

	ParkingLot p = ParkingLot();
	Car c = Car();
	Graph g = Graph();
	p.getCars();
	p.getEntrance();
	p.getParkingPlace();
	p.getNrOfCars();

	if (p.checkIfRectangle() || !p.checkIfEnoughParkingPlaces()) {
		cout
				<< "parking lot configuration is not a rectangle or theres not enough parking places";
		exit(0);
	}
	cout << "Number of cars: " << p.getNrOfCars() << endl;
	cout << "Number of parking places: " << p.getParkingPlace() << endl;
	p.loadCars();
	g.createVertexes(p);
	g.connectVertexes();
	g.parkCars(p);
//	cout << "parking time" << p.getParkingTime();

	return 0;
}

