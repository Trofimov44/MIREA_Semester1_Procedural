#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;


int Chisla(char romanNumeral) {
    switch (romanNumeral) {
    case 'I':
        return 1;
    case 'V':
        return 5;
    case 'X':
        return 10;
    case 'L':
        return 50;
    case 'C':
        return 100;
    case 'D':
        return 500;
    case 'M':
        return 1000;
    default:
        return 0;
    }
}

int main() {
    setlocale(LC_ALL, "rus");
    string romanNumeral;
    cout << "Введите римское число: ";
    cin >> romanNumeral;
    string numbers[] = { "IM", "ID", "IC","IL", "VX", "VL", "VC","VD", "VM", "XD", "XM", "LC","LD", "LM", "DM", "VV","LL", "DD", "IIII", "XXXX",
        "CCCC", "MMMM" };
    auto it = find(begin(numbers), end(numbers), romanNumeral);

    bool found = false;

    for (const string& syllable : numbers) {
        size_t position = romanNumeral.find(syllable);
        if (position != string::npos) {
            found = true;
            break;
        }
    }
    if (found) {
        cout << "Такого числа не существует" << endl;
    }
    else {
        int decimalNum = 0;
        for (int i = 0; i < romanNumeral.length(); i++) {
            if (Chisla(romanNumeral[i]) == 0) {
                cout << "Ошибка";
                exit(0);
            }
            int currentNum = Chisla(romanNumeral[i]);
            int nextNum = (i + 1 < romanNumeral.length()) ? Chisla(romanNumeral[i + 1]) : 0;

            if (currentNum >= nextNum) {
                decimalNum += currentNum;
            }
            else {
                decimalNum -= currentNum;
            }
        }
        cout << "Десятичное представление: " << decimalNum << endl;
    }

    return 0;
}
