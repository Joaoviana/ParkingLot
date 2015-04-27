#include <sstream>
#include <fstream>
#include <iostream>
#include "Car.h"



Car::Car() {
}

Car::Car(string plate, int carWidth, int carHeight, string entrance) {
	this->plate = plate;
	this->carHeight = carHeight;
	this->carWidth = carWidth;
	this->entrance = entrance;
	this->distanceToEntrance=0;
}


int Car::getCarWidth()
{
	return carWidth;
}

const string Car::getPlate() const {
	return plate;
}

const string Car::getEntrance() const {
	return entrance;
}

void Car::setEntrance(const string& entrance) {
	this->entrance = entrance;
}

void Car::setPlate(const string& plate) {
	this->plate = plate;
}

int Car::getCarHeight() {
	return carHeight;
}
