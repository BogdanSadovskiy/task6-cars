using namespace std;
#include <iostream>
#include<Windows.h>
#include "CarNumber.h"

void wrong();
int number(char q);

void preview(cars* car, int size) {    // previewing of new car
	cout << "\nMark - " << car[size].mark << endl;
	cout << "Model - " << car[size].model << endl;
	cout << "Year - " << car[size].year << endl;
	cout << "Type of body - " << car[size].type_of_body << endl;
	cout << "Color - " << car[size].color << endl;
	cout << "Engine type - " << car[size].type_of_eng << endl;
	if (car[size].type_of_eng != "Electric") {
		cout << "Engine capacity - " << car[size].eng_cap << endl;
	}
	cout << "Power - " << car[size].h_power << " hp" << endl;
	cout << "Torque - " << car[size].torque << " Hm\n";
	cout << car[size].type_of_drive << " drive\n";
	cout << "Numbers - \"" << car[size].car_number << "\"\n\n";

}
void colors(string& color,bool& num) {		// selection of car's color 
	start_color:
	cout << "\nColor:\n";
	cout << "White -- 1;\n";
	cout << "Black -- 2;\n";
	cout << "Gray --- 3;\n";
	cout << "Yellow - 4;\n";
	cout << "Blue --- 5;\n";
	cout << "Green -- 6;\n";
	cout << "Red ---- 7;\n";
	cout << "Other -- 8;\n";
	cout << "_ Back - 0\n\n";
	char q; cin >> q;
	if ((int)q < 48 || (int)q>56) {
		wrong();
		goto start_color;
	}
	int nums = number(q);
	switch (nums)
	{
	case 0:
		num = false;
		return;
	case 1:
		color = "White";
		break;
	case 2:
		color = "Black";
		break;
	case 3:
		color = "Grey";
		break;
	case 4:
		color = "Yellow";
		break;
	case 5:
		color = "Blue";
		break;
	case 6:
		color = "Green";
		break;
	case 7:
		color = "Red";
		break;
	case 8:
		color = "Other";
		break;
	default:
		break;
	}
	num = true;
	
}

void body_type(string& body,bool& num) {		//selection of bodytype of car
	start_body:
	cout << "\nType of body:\n";
	cout << "Sedan ----- 1;\n";
	cout << "Hatchback - 2;\n";
	cout << "Universal - 3;\n";
	cout << "Cabriolet - 4;\n";
	cout << "Pickup ---- 5;\n";
	cout << "SUV ------- 6;\n";
	cout << "Other ----- 7;\n";
	cout << "____ Back - 0\n\n";
	char q; cin >> q;
	if ((int)q < 48 || (int)q>55) {
		wrong();
		goto start_body;
	};
	int nums = number(q);
	if (nums == 1) {
		body = "Sedan";
	}
	else if (nums == 2) {
		body = "Hatchback";
	}
	else if (nums == 3) {
		body = "Universal";
	}
	else if (nums == 4) {
		body = "Cabriolet";
	}
	else if (nums == 5) {
		body = "Pickup";
	}
	else if (nums == 6) {
		body = "SUV";
	}
	else if (nums == 7) {
		body = "Other";
	}
	else if (nums == 0) {
		num = false;
		return;
	}
	num = true;
}

void drive_type(string& drive, bool& num) {
	
	start_drive:
	cout << "\nType of drive:\n";
	cout << "Front wheels - 1;\n";
	cout << "Rear wheels -- 2;\n";
	cout << "All wheels --- 3;\n";
	cout << "_______ Back - 0\n\n";
	char q; cin >> q;
	if (q == '1') {
		drive = "Front wheels";
	}
	else if (q == '2') {
		drive = "Rear wheels";
	}
	else if (q == '3') {
		drive = "All wheels";
	}
	else if (q == '0') {
		num = false;
		return;
	}
	else {
		wrong();
		goto start_drive;
	}
	num = true;
}

void eng_type(string& type_of_eng,bool&num) {

start_eng_type:
	cout << "\nType of engine:\n";
	cout << "Diesel ------ 1;\n";
	cout << "Petrol ------ 2;\n";
	cout << "Petrol/Gas; - 3;\n";
	cout << "Electric ---- 4;\n";
	cout << "_______Back - 0\n\n";
	char q; cin >> q;

	if (q == '0') {
		num = false;
		return;
	}
	else if (q == '1') {
		type_of_eng = "Diesel";
	}
	else if (q == '2') {

		type_of_eng = "Petrol";
	}
	else if (q == '3') {
		type_of_eng = "Petrol/Gas";
	}
	else if (q == '4') {
		type_of_eng = "Electric";
	}
	else {
		wrong();
		goto start_eng_type;
	}
	num = true;
}

void add_carr(cars*& car, int& size) { //func that adding the new car
	bool num = true;
	cars* car2 = new cars[size + 1];
	for (int i = 0; i < size; i++) {
		car2[i] = car[i];
	}

	mark:
		cout << "\nInput mark of car\n";
		cout << "          Exit - 0\n";
		cin >> car2[size].mark;
		if (car2[size].mark == "0"){
			return;
		}
	model:
		cout << "Input model\n";
		cout << "   Back - 0\n";
		cin >> car2[size].model;
		if (car2[size].model == "0") {
			goto mark;
		}
	year:
		cout << "Year:\n";
		cout << "Back - 0\n";
		cin >> car2[size].year;
		if (car2[size].year == 0) {
			goto model;
		}
		if (car2[size].year > 0 && car2[size].year < 1900) {
			wrong();
			cout << "Input real year\n\n";
			goto year;
		}
	body:
		body_type(car2[size].type_of_body,num);
		if (num == false) {
			goto year;
		}
	color:
		colors(car2[size].color,num);
		if (num == false) {
			goto body;
		}
	engine:
		eng_type(car2[size].type_of_eng,num);
		if (num == false) {
			goto color;
		}
		if (car2[size].type_of_eng != "Electric") {
			cout << car2[size].type_of_eng << endl;
			cout << "\nEngine capacity L:\n";
			cout << "   Back ----- 0\n";
			cin >> car2[size].eng_cap;
			if (car2[size].eng_cap == 0) {
				goto engine;
			}
		}
	power:
		cout << "\nPower HP:\n";
		cout << "Back - 0\n";
		cin >> car2[size].h_power;
		if (car2[size].h_power == 0) {
			goto engine;
		}
	torque:
		cout << "\nEngine torque Hm:\n";
		cout << "      Back - 0\n";
		cin >> car2[size].torque;
		if (car2[size].torque == 0) {
			goto power;
		}
	drive:
		drive_type(car2[size].type_of_drive,num);
		if (num == false) {
			goto torque;
		}
	carnumb:
		CarNumbers(car2[size].car_number,num);
		if (num == false) {
			goto drive;
		}
		preview(car2, size);
		correct:
		cout << "Are this all correct?\n";
		cout << "YES ---------------------------- 1\n";
		cout << "No. Go input information again - 2\n";
		cout << "______________ Exit ------------ 0\n";
		char q; cin >> q;
		if (q == '2') {
			goto mark;
		}
		else if (q == '0') {
			cout << "Exiting\n";
			Sleep(2000);
			return;
		}
		else if (q == '1') {
			cout << "Added new car\n";
			size++;
			delete[] car;
			car = car2;
		}
		else {
			wrong();
			goto correct;
		}

}
