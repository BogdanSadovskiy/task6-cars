using namespace std;
#include <iostream>
struct cars {
	string mark;
	string model;
	int year;
	string type_of_body;
	string color;
	string type_of_eng;
	float eng_cap;
	int h_power;
	int torque;
	string type_of_drive;
	string car_number;
};

#include "Menu.h"
#include "AddCar.h"
#include "Search.h"
#include "Delete.h"


void wrong() {
	cout << "Wrong inputting\n";
}
int number(char q) {   // func that converting char(number)  to number
	int num;
	num = (int)q - 48;
	return num;
}
void cars_view(cars* car, int size) {
	cout << endl;
	for (int i = 0; i < size; i++) {
		cout << i + 1 << " car ------------------------------\n";
		cout << "\nMark - " << car[i].mark << endl;
		cout << "Model - " << car[i].model << endl;
		cout << "Year - " << car[i].year << endl;
		cout << "Type of body - " << car[i].type_of_body << endl;
		cout << "Color - " << car[i].color << endl;
		cout << "Engine type - " << car[i].type_of_eng << endl;
		if (car[i].type_of_eng != "Electric") {
			cout << "Engine capacity - " << car[i].eng_cap << endl;
		}
		cout << "Power - " << car[i].h_power << " hp" << endl;
		cout << "Torque - " << car[i].torque << " Hm\n";
		cout << car[i].type_of_drive << " drive\n";
		cout << "Numbers - \"" << car[i].car_number << "\"\n";
		cout << "----------------------------------------\n\n";
	}
}

int main()
{
	bool num = 0;
	int size = 0;
	cars* car = new cars[size];
	start:
	menu(num,car, size);
	if (num == false) {
		return 0;
	}
	else if (num == true) {
		goto start;
	}
}

