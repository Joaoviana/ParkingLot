#ifndef SRC_CAR_H_
#define SRC_CAR_H_

#include <string>

using namespace std;

class Car {
	string plate;
	int carWidth, carHeight;
	int distanceToEntrance;
	string entrance;
public:
	Car();
	Car(string plate, int carWidth, int carHeight, string entrance);
	int getCarWidth();
	int getCarHeight();
	const string getPlate() const;
	void setPlate(const string& plate);

	int getDistanceToEntrance() const {
		return distanceToEntrance;
	}

	void setDistanceToEntrance(int distanceToEntrance) {
		this->distanceToEntrance = distanceToEntrance;
	}

	const string getEntrance() const;
	void setEntrance(const string& entrance);
};

#endif /* SRC_CAR_H_ */
