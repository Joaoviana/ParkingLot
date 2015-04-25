#include <sstream>
#include <fstream>
#include "Car.h"

Car::Car(string plate, int dimension) {
	this->plate = plate;
	this->dimension = dimension;
}
#include <fstream>

Car::Car() {
}

string Car::getCarInfo() {
	ifstream file("cars.txt");
	string plate, width, height, result;
	if (!file.eof()) {
		stringstream iss;
		getline(iss, plate, ',');
		getline(iss, width, ',');
		getline(iss, height, ',');
	}
	result = plate + width + height;
}
