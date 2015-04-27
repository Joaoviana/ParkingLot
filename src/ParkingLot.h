#ifndef SRC_PARKINGLOT_H_
#define SRC_PARKINGLOT_H_

#include "Car.h"
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>

class ParkingLot {

	int nCars;
	int nEntrance;
	int nParkingPlace;
	vector<Car> cars;

public:
	ParkingLot();
	ParkingLot(int nCars, int nEntrance, int nParkingPlace);

	void loadParkingLot();
	void loadCars();

	int getParkingPlace() const;
	int getEntrance() const;
	int getNrOfCars() const;
	bool checkIfRectangle();
	bool checkIfEnoughParkingPlaces();
	const vector<Car>& getCars() const;
	void setCars(const vector<Car>& cars);
	int getParkingTime();
};

#endif /* SRC_PARKINGLOT_H_ */
