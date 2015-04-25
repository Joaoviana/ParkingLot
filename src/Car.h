#ifndef SRC_CAR_H_
#define SRC_CAR_H_

#include <string>

using namespace std;

class Car {
	int dimension;
	string plate;
	int carWidth, carHeight;

public:
	Car();
	Car(string plate, int dimension);
	//string getPlate() const;
	//int getCarWidth();
	//int getCarHeight();
	string getCarInfo();
};

#endif /* SRC_CAR_H_ */
