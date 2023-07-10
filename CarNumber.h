using namespace std;
#include <iostream>


void CarNumbers(string& carnumber, bool& num) {
number:
	cout << "Input car number (LLnnnnLL)\n";
	cout << "(L - letter, n - Number)\n";
	cout << "________________ Back ----- 0\n";
	cin >> carnumber;
	if (carnumber == "0") {
		num = false;
		return;
	}
	if (carnumber.length() < 8) {
		cerr << "Number is too short\n";
		goto number;
	}
	else if (carnumber.length() > 8) {
		cerr << "Number is too long\n";
		goto number;
	}
	
	for (int i = 0; carnumber[i] != '\0'; i++) {
		if (i == 0 || i == 1 || i == 6 || i == 7) {
			if (((int)carnumber[i] < 65 || (int)carnumber[i]> 90) && ((int)carnumber[i] < 97 || (int)carnumber[i] > 122)) {
				cerr << "Wrong type of number\n";  // якщо не букви - виведе помилку
				Sleep(1000);
				goto number;
			}
			else {
				if ((int)carnumber[i] > 96 || (int)carnumber[i] < 123){ // якщо літери малі - робить їх великими
					carnumber[i] = (int)carnumber[i] - 32;
				}
			}
		}
		else {
			if ((int)carnumber[i] < 48 || (int)carnumber[i] > 57) {
				cerr << "Wrong type of number\n";  // якщо не цифри - виведе помилку
				Sleep(1000);
				goto number;
			}
		}
	}
	num = true;
}