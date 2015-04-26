#ifndef SRC_CAR_H_
#define SRC_CAR_H_

#include <string>

using namespace std;

class Car {
	string plate;
	int carWidth, carHeight;

public:
	Car();
	Car(string plate, int carWidth, int carHeight);
};

#endif /* SRC_CAR_H_ */
