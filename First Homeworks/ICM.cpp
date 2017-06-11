#include <iostream>
#include <math.h>

using namespace std;

void Min_Overall_Multiple(int a, int b) {
	int max;
	for (int i = b; i <= a * b; i = i + b) {
		if (fmod(i, b) == 0 & fmod(i, a) == 0) {
			cout << "НОК " << a << " и " << b << ": " << i << endl;
		}
	}

}

int main() {
	setlocale(0, "Russian");
	int a, b = 0;
	cout << "Введите первое число" << endl;
	cin >> a;
	cout << "Введите второе число" << endl;
	cin >> b;
	Min_Overall_Multiple(a, b);

	system("pause");
	return 0;
}
