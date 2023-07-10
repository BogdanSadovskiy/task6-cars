using namespace std;
#include <iostream>
#include "Edit.h"
void cars_view(cars* car, int size);
void wrong();
void add_carr(cars*& car, int& size);
void searchNumber(cars* car, int size);
void deleteCar(cars*& car, int& size);

int menu(bool& num,cars*& car, int& size) {
	char q;
	num = true;
	cout << "\nAdd car -------------- 1\n";
	cout << "Edit information ----- 2\n";
	cout << "View all cars -------- 3\n";
	cout << "Search car by number - 4\n";
	cout << "Delete car ----------- 5\n";
	cout << "__________ Exit ------ 0\n";
	cin >> q;
	if (q == '0') {
		cout << "\nBye\n";
		num = false;
		return num;
	}
	else if (q == '1' ) {
		add_carr(car, size);
	}
	
	else if (q == '2') {
		if (size > 0) {
			editcar(car, size);
		}
		else {
			cout << "\nNo any cars\n";
		}
	}

	else if (q == '3') {
		if (size > 0) {
			cars_view(car, size);
		}
		else {
			cout << "\nNo any cars\n";
		}
	}

	else if (q == '4') {
		if (size > 0) {
			searchNumber(car, size);
		}
		else {
			cout << "\nNo any cars\n";
		}
	}
	else if (q == '5') {
		if (size > 0) {
			deleteCar(car, size);
		}
		else {
			cout << "\nNothing to delete\n";
		}
	}
	else {
		wrong();
	}
	
}