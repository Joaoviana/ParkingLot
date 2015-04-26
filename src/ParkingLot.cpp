#include "ParkingLot.h"
#include <sstream>
#include <vector>
#include <fstream>

ParkingLot::ParkingLot() {
}

ParkingLot::ParkingLot(int nCars, int nEntrace, int nParkingPlace) {
	this->nCars = nCars;
	this->nEntrance = nEntrance;
	this->nParkingPlace = nParkingPlace;
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

	ifstream file("cars.txt");
	string plate, width, height, line;
	int widthint, heightint;
	while (getline(file, line)) {
		stringstream iss(line);
		getline(iss, plate, ',');
		getline(iss, width, ',');
		getline(iss, height, ',');
		widthint = atoi(width.c_str());
		heightint = atoi(height.c_str());
		Car c = Car(plate, widthint, heightint);
		cars.push_back(c);
	}

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

int ParkingLot::getEntrance() const {
	string line;
	ifstream infile;
	int nrOfEntrances = 0;
	infile.open("parkinglotConf.txt");
	while (!infile.eof()) {
		getline(infile, line);
		for (int i = 0; i < line.size(); i++) {
			if (line[i] == 'E') {
				nrOfEntrances++;
			}
		}
	}
	return nrOfEntrances;

}
