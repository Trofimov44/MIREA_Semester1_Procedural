#include <iostream>
#include <cmath>

using namespace std;
void dssd(int a, int b) {
	if (a != 0 and b != 0) {
		if (a > b) {
			a = a % b;
			dssd(a, b);
		}
		else {
			b = b % a;
			dssd(a, b);
		}
	}
	else {
		cout << "делением " << a + b << endl;
	}
}

void fdso(int a, int b) {
	if (a != b) {
		if (a > b) {
			a = a - b;
			fdso(a, b);
		}
		else {
			b = b - a;
			fdso(a, b);
		}
	}
	else {
		cout << "вычитанием " << a << endl;
	}
}

int main() {
	setlocale(LC_ALL, "RUS");
	cout << "Введите два числа ";
	int a, b;
	if (!(cin >> a >> b) or a < 0 or b < 0) {
		cout << "Ошибка";
		return 0;
	}
	dssd(a, b);
	fdso(a, b);
	return 0;
}
