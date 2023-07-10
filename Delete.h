using namespace std;
#include <iostream>
int whatisq(string q);
void wrong();
void preview(cars* car, int size);
void deleting(cars*& car, int& size, int iter) {
	int k = 0;
	cars* car2 = new cars[size - 1];
	for (int i = 0; i < size; i++) {
		if (i != iter) {
			car2[k] = car[i];
			preview(car2, k);
			k++;
		}
	}
	size --;
	delete[] car;
	car = car2;
}

void deleteCar(cars*& car, int& size) {
	startdel:
	cout << "\nInput car you want to delete (you have " << size << " cars)\n";
	cout << "Exit -- 0\n";
	string q; cin >> q;
	if (whatisq(q) == 0) {
		return;
	}
	else if (whatisq(q) == -1 || whatisq(q) > size) {
		wrong();
		goto startdel;
	}
	int iter = whatisq(q) - 1;
	preview(car, iter);
	del:
	cout << "Delete - 1\n";
	cout << "Back --- 0\n";
	cin >> q;
	if (whatisq(q) == 0) {
		goto startdel;
	}
	else if (whatisq(q) == -1 || whatisq(q) > size) {
		wrong();
		goto del;
	}
	deleting(car, size, iter);
	cout << "Deleted\n";

}