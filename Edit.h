using namespace std;
#include <iostream>
void preview(cars* car, int size);
void wrong();
void body_type(string& body, bool& num);
void colors(string& color, bool& num);
void eng_type(string& type_of_eng, bool& num);
void drive_type(string& drive, bool& num);
void CarNumbers(string& carnumber, bool& num);

int whatisq(string q) {		//determining of numbers
	int size = q.length();	// for ex: you inputted "14" in string;
	int number = 0;			// now we have "14" as an int
	int m = 1;
	for (int i = size-1; i >=0; i--) {
		if ((int)q[i] < 48 || (int)q[i] > 57) {
			return -1;
		}
		number += ((int)q[i] - 48) * m;
		m = m*10;
	}
	return number;
}
void editMark(cars* car, int i) {
	cout <<endl<< car[i].mark << "\n";
	cout << "Input new name of mark\n";
	cout << "  Back -- 0\n";
	string q; cin >> q;
	if (q.length() == 1) {
		int num = whatisq(q);
		if (num == 0) {
			return;
		}
	}
	car[i].mark = q;
	cout << "Edited\n\n";
}
void editModel(cars* car, int i) {
	cout << endl << car[i].model << "\n";
	cout << "Input new name of model\n";
	cout << "  Back -- 0\n";
	string q; cin >> q;
	if (q.length() == 1) {
		int num = whatisq(q);
		if (num == 0) {
			return;
		}
	}
	car[i].model = q;
	cout << "Edited\n\n";
}
void editYear(cars* car, int i) {
	edityear:
	cout << endl << car[i].year << "\n";
	cout << "Input new name of year\n";
	cout << "  Back -- 0\n";
	string q; cin >> q;
	int num = whatisq(q);
	if (q.length() == 1) {
		if (num == 0) {
			return;
		}
	}
	if (num == -1) {
		wrong();
		goto edityear;
	}
	if (num < 1900 || num > 2023) {
		wrong();
		cout << "Input real year\n";
		goto edityear;
	}
	car[i].year = num;
	cout << "Edited\n\n";
}
void editBodytype(cars* car, int i) {
	cout << endl << car[i].type_of_body << "\n";
	string q;
	bool num = true;
	body_type(q ,num);
	if (num == true) {
		car[i].type_of_body = q;
		cout << "Edited\n\n";
	}
}
void editColor(cars* car, int i) {
	cout << endl << car[i].color << "\n";
	string q;
	bool num = true;
	colors(q, num);
	if (num == true) {
		car[i].color = q;
		cout << "Edited\n\n";
	}
}
void editEngine(cars* car, int i) {
	cout << endl << car[i].type_of_eng << "\n";
	string q;
	bool num = true;
	eng_type(q, num);
	if (num == true) {
		if (car[i].type_of_eng == "Electric" && q != "Electric") {
// if you had an electric eng and now you have other one, you must to input the capacity of new engine
			cout << "\nEngine capacity L:\n";
			cin >> car[i].eng_cap;
		}
		car[i].type_of_eng = q;
		cout << "Edited\n\n";
	}
}
void editEngCap(cars* car, int i) {
	cout << endl << car[i].eng_cap << "\n";
	cout << "Input engine capacity:\n";
	cout << "  back - 0\n";
	float cap = 0;
	cin >> cap;
	if (cap == 0) {
		return;
	}
	car[i].eng_cap = cap;
	cout << "Edited\n";
}
void editPower(cars* car, int i) {
	editpow:
	cout << endl << car[i].eng_cap << "\n";
	cout << "Input Power hp:\n";
	cout << "  back - 0\n";
	string q; cin >> q;
	int num = whatisq(q);
	if (q.length() == 1) {
		if (num == 0) {
			return;
		}
	}
	if (num == -1) {
		wrong();
		goto editpow;
	}
	car[i].eng_cap = num;
	cout << "Edited\n";
}
void editTorque(cars* car, int i) {
edittor:
	cout << endl << car[i].torque << "\n";
	cout << "Input Torque Hm:\n";
	cout << "  back - 0\n";
	string q; cin >> q;
	int num = whatisq(q);
	if (q.length() == 1) {
		if (num == 0) {
			return;
		}
	}
	if (num == -1) {
		wrong();
		goto edittor;
	}
	car[i].torque = num;
	cout << "Edited\n";
}
void editTypeDrive(cars* car, int i) {
	cout << endl << car[i].type_of_drive << "\n";
	string q;
	bool num = true;
	body_type(q, num);
	if (num == true) {
		car[i].type_of_drive = q;
		cout << "Edited\n\n";
	}
}
void editNumber(cars* car, int i) {
	cout << endl << car[i].car_number << "\n";
	bool num = true;
	string q;
	CarNumbers(q, num);
	if (num == true) {
		car[i].car_number = q;
		cout << "Edited\n\n";
	}
}
void editing(cars* car, int i) {
	menuEdit:
	int k = 1;
	cout << "What do you want to edit?\n";
	cout << "Name of mark ---- "<< k++<<"\n";	//1
	cout << "Name of model --- " << k++ << "\n";//2
	cout << "Year ------------ " << k++ << "\n";//3
	cout << "Bodytype -------- " << k++ << "\n";//4
	cout << "Color ----------- " << k++ << "\n";//5
	cout << "Engine ---------- " << k++ << "\n";//6
	if (car[i].type_of_eng != "Electric") {
		cout << "Engine capacity - " << k++ << "\n";//7
	}
	cout << "Power HP -------- " << k++ << "\n";//8
	cout << "Torque Nm ------- " << k++ << "\n";//9
	cout << "Type of drive --- " << k++ << "\n";//10
	cout << "Car number ------ " << k << "\n";
	cout << "Exit ------------ 0\n";
	string q; cin >> q;
	int num = whatisq(q);
	if (num == -1 || num > k) {
		wrong();
		goto menuEdit;
	}
	
	if (num == 0) {
		return;
	}
	else if (num == 1) {
		editMark(car, i);
		goto menuEdit;
	}
	else if (num == 2) {
		editModel(car, i);
		goto menuEdit;
	}
	else if (num == 3) {
		editYear(car, i);
		goto menuEdit;
	}
	else if (num == 4) {
		editBodytype(car, i);
		goto menuEdit;
	}
	else if (num == 5) {
		editColor(car, i);
		goto menuEdit;
	}
	else if (num == 6) {
		editEngine(car, i);
		goto menuEdit;
	}

	if (car[i].type_of_eng == "Electric" && num > 6) {
		num++;
	}
	
	if (num == 7) {
		editEngCap(car, i);
		goto menuEdit;
	}
	else if (num == 8) {
		editPower(car, i);
		goto menuEdit;
	}
	else if (num == 9) {
		editTorque(car, i);
		goto menuEdit;
	}
	else if (num == 10) {
		editTypeDrive(car, i);
		goto menuEdit;
	}
	else if (num == 11) {
		editNumber(car, i);
		goto menuEdit;
	}
}

void editcar(cars* car, int size) {
	string q;
	start_edit:
	if (size > 1) {
		cout << "\nWhat car you want to edit? ";
		cout << "(1 - " << size << endl;
		cout << "   Back --- 0\n";
		cin >> q;
	}
	else {
		cout << "\nYou have only one car. Continue - 1\n";
		cout << "   Back --- 0\n";
		cin >> q;
	}
	
	int num = whatisq(q);
	cout << num;
	if (num == -1 || num > size) {
		wrong();
		goto start_edit;
	}
	else if (num == 0) {
		return;
	}
	
	choose_car:
	cout << endl;
	preview(car, num - 1);
	cout << "\nWant to edit info about car #" << num << "? (yes - 1)\n";
	cout << "       Back ----- 0\n";
	cin >> q;
	num = whatisq(q);
	if (num == -1 || num > 1) {
		wrong();
		goto choose_car;
	}
	else if (num == 0) {
		goto start_edit;
	}
	editing(car, num -1);
	

	

}