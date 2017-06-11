#include <iostream>

using namespace std;

struct item // opisanie odnogo predmeta
{
	int W; // obem
	int c; //zena odnogo predmeta
	double price; //ydelnaia zena
	int number; // nomer po poriadky, dlia vivoda
	double part; // chast, kotoryu we polochili v rukzak
};
item *allitems;

void quickSort_price(int l, int r) {// sortirovka po zene
int x = allitems[l + (r - l) / 2].price;
int i = l;
int j = r;
while (i <= j)
{
	while (allitems[i].price < x) i++;
	while (allitems[j].price > x) j--;
	if (i <= j)
	{
		swap(allitems[i], allitems[j]);
		i++;
		j--;
	}
}
if (i<r)
	quickSort_price(i, r);

if (l<j)
	quickSort_price(l, j);
}

void quickSort_number(int l, int r)// sortirovka po nomery/poriadky
{
	int x = allitems[l + (r - l) / 2].number;
	int i = l;
	int j = r;
	while (i <= j)
	{
		while (allitems[i].number < x) i++;
		while (allitems[j].number > x) j--;
		if (i <= j)
		{
			swap(allitems[i], allitems[j]);
			i++;
			j--;
		}
	}
	if (i<r)
		quickSort_number(i, r);

	if (l<j)
		quickSort_number(l, j);
}

void Continuous_knapsack(int W, int n) // vvod zaiavok
{
	allitems = new item[n];
	double sum = 0;
	for (int i = 0; i<n; i++)
	{
		cin >> allitems[i].W >> allitems[i].c;
		allitems[i].price = allitems[i].c / allitems[i].W;
		allitems[i].number = i + 1;
		allitems[i].part = 0;
	}
	cout << endl;
	quickSort_price(0, n - 1);//otsortirovali po zene and vozrostaniu
	for (int i = n - 1; i >= 0; i--) {
		//ïîäáîð
		if (W >= allitems[i].W) {   //if pomechaetsia-berem
			allitems[i].part = 1;
			sum += allitems[i].c;
			W -= allitems[i].W;
		}
		else {// else berem skolko mojno and vixodim
			allitems[i].part += W / (allitems[i].W*1.0);
			sum += W / (allitems[i].W*1.0) * allitems[i].c;
			break;
		}
	}

	quickSort_number(0, n - 1); //otsortirovali po poriadky vvoda

	cout << sum << endl;
	for (int i = 0; i<n; i++)

		cout << allitems[i].part << " "; //vivod rezultata


	delete[]allitems;
}

int main()
{
	int W, n;
	cin >> W >> n;

	Continuous_knapsack(W, n);
	return 0;
}