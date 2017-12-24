#include <iostream>
using namespace std;

int strange_multiply(int &a, int &b) {
	int c = b;
	for (int i = 1; i < a; i++) {
		b = b + c;
	}
	return a, b;
}

int main() {
	setlocale(0, "Russian");
	int a, b;
	cout << "Ââåäèòå 2 ÷èñëà" << endl;
	cin >> a >> b;
	strange_multiply(a, b);
	cout << "Ðåçóëüòàò: " << b << endl;
	system("pause");
	return 0;
}
