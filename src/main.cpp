#include <iostream>
#include <string>
#include <cstdlib>
#include "ParkingLot.h"
#include "Car.h"

using namespace std;

int main() {

	ParkingLot f = ParkingLot();
	Car c = Car();
	if(f.checkIfRectangle() || !f.checkIfEnoughParkingPlaces()) {
		cout << "parking lot configuration is not a rectangle or theres not enough parking places";
		exit(0);
	}
	cout << "Number of cars: " << f.getNrOfCars() << endl;
	cout << "Number of parking places: " << f.getParkingPlace() << endl;
	cout << c.getCarInfo();
	//create inside of load objects: ParkingLot e Car
	f.loadParkingLot();
	f.loadCars();

	return 0;
}

