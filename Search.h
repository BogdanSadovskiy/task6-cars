using namespace std;
#include <iostream>
void CarNumbers(string& carnumber, bool& num);
void preview(cars* car, int size);
int number(char q);
int whatisq(string q);
void wrong();

void searchNumber( cars* car, int size) {
find:
	string q;
	bool num = true;
	cout << "\n";
	CarNumbers(q, num);
	if (num == false) {
		return;
	}
	int iter = 0;
	for (int i = 0; i < size; i++) {
		if (q == car[i].car_number) {
			cout<<"\nFound\n";
			iter = i;
		}
		else { 
			cout << "\nNot found\n"; 
			goto find;
		}
	}
	preview(car, iter);
	findend:
	cout << "\nSearch again? - 1\n";
	cout << "Exit --- 0\n";
	cin >> q;
	if (whatisq(q) == 1) {
		goto find;
	}
	else if (whatisq == 0) {
		return;
	}
	else {
		wrong();
		goto findend;
	}
}
