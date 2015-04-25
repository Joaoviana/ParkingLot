#ifndef SRC_PARKINGLOT_H_
#define SRC_PARKINGLOT_H_

#include "Car.h"
#include <fstream>
#include <string>
#include <algorithm>

class ParkingLot {

	int nCars;
	int nGates;
	int nParkingPlace;

public:
	ParkingLot();
	ParkingLot(int nCars, int nGates, int nParkingPlace);

	void loadParkingLot();
	void loadCars();

	int getNrOfCars() const;
	int getGates() const;
	int getParkingPlace() const;

	bool checkIfRectangle();
	bool checkIfEnoughParkingPlaces();
};

#endif /* SRC_PARKINGLOT_H_ */
