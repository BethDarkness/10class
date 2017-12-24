#include <iostream>
using namespace std;

void outer_points(int n, int m);

int main() {
	int n, m;
	cin >> n >> m;
	outer_points(n, m);
    return 0;
}

void outer_points(int n, int m) {
	int *prinadlegnost = new int[m];
	int *tochka = new int[m];
	int *a = new int[n];
	int *b = new int[n];
	for (int i = 0; i <n; i++){
		cin >> a[i] >> b[i];
	}

	for (int i = 0; i < m; i++) {
		cin >> tochka[i];
		prinadlegnost[i] = 0;
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (tochka[i] >= a[j] && tochka[i] <= b[j])	
			prinadlegnost[i] ++;
		}
	}
	for (int i = 0; i < m; i++) {
		cout << n - prinadlegnost[i] << " ";
	}
}
