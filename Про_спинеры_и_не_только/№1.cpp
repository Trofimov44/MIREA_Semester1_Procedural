#include <iostream>
using namespace std;

int main() {
	setlocale(0, "");
	cout << "Введите три числа - стоимость основания спиннера, стоимость одной лопасти и максимальная стоимость всего спиннера:" << endl;
	
	int a, b, c;
	if ((cin >> a && cin >> b && cin >> c) and(a!='.' && b != '.'&& c != '.'&& a!= ',' && b != ',' && c != ','))
	{
		if (a <= c) {
			cout << (c - a) / b;
		}
		else {
			cout << "Максимальная стоимость всего спинера не может быть меньше стоисмости основания спинера" << endl;
		}
		
	}
	else
	{
		cout << "Введите положительные целые числа";
	}
	return 0;
}
