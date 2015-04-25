#include "ParkingLot.h"

ParkingLot::ParkingLot() {
}

ParkingLot::ParkingLot(int nCars, int nGates, int nParkingPlace) {
	this->nCars = nCars;
	this->nGates = nGates;
	this->nParkingPlace = nParkingPlace;
}

int ParkingLot::getGates() const {
	return nGates;
}

int ParkingLot::getParkingPlace() const {
	string line;
	ifstream infile;
	int nrOfParkingPlaces = 0;
	infile.open("parkinglotConf.txt");
	while (!infile.eof()) {
		getline(infile, line);
		for (int i = 0; i < line.size(); i++) {
			if (line[i] == 'L') {
				nrOfParkingPlaces++;
			}
		}
	}
	return nrOfParkingPlaces;
}

void ParkingLot::loadParkingLot() {
}

void ParkingLot::loadCars() {
}

bool ParkingLot::checkIfRectangle() {
	string line;
	string firstline;
	ifstream infile;
	infile.open("parkinglotConf.txt");
	int width, height;
	height = 0;

	getline(infile, firstline);
	width = firstline.length();

	while (!infile.eof()) {
		getline(infile, line);
		height++;
	}

	if (width == height) {
		return true;
	}

	return false;
}

int ParkingLot::getNrOfCars() const {
	string line;
	int nrOfCars = 0;
	ifstream infile;
	infile.open("cars.txt");
	while (!infile.eof()) {
		getline(infile, line);
		nrOfCars++;
	}
	return nrOfCars;
}

bool ParkingLot::checkIfEnoughParkingPlaces() {
	if (getNrOfCars() > getParkingPlace()) {
		return false;
	}
	return true;
}
