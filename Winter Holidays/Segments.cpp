#include <iostream>

using namespace std;

void Segments(int m);

int main()
{
	int m;
	for (;;)
	{
		cin >> m;
		if (m > 0 && m < 500) break;
	}
	Segments(m);
    return 0;
}

void Segments(int m)
{
	int *a = new int[m];									
	int *b = new int[m];
	int *Order = new int[m];								
	int *Lenght = new int[m];
	int c, buff = 0, min = 0, s=0;
	int *save_Order = new int[m];						
	int *save_p = new int[m];								
	int p;												
	for (int i = 0; i < m; i++)								
	{
		cin >> a[i] >> b[i];
		Order[i] = i+1;
		Lenght[i] = b[i] - a[i];
	}
	for (int i = 0; i < m; i++)							
	{
		min = Lenght[i];
		c = i;
		for (int j = i + 1; j < m; j++)
		{
			if (Lenght[j] < min)
			{
				min = Lenght[j];
				c = j;
			}
		}
		buff = a[c];
		a[c] = a[i];
		a[i] = buff;
		buff = b[c];
		b[c] = b[i];
		b[i] = buff;
		buff = Order[c];
		Order[c] = Order[i];
		Order[i] = buff;
		buff = Lenght[c];
		Lenght[c] = Lenght[i];
		Lenght[i] = buff;
	}
	*save_p = 0;
	*save_Order = *Order;
	p = 0;
	for (int i = 0; i < m; i++)								
	{
		s = 0;
		save_p[s] = Order[i];
		for (int j = i; j < m; j++)								
		{																
			if (Lenght[j] > Lenght[i] && a[j] < a[i] && b[j] > b[i])
			{
				s++;
				save_p[s] = Order[j];
			}
		}
		if (s > p)
		{
			p = s;
			for (int k = 0; k <= p; k++)
			{
				save_Order[k] = save_p[k];
			}
		}
	}
	cout <<  p+1 << endl;
	for (int i = 0; i <= p; i++)	cout << " " << save_Order[i] << " ";
	delete[] a;
	delete[] b;
	delete[] Order;
	delete[] Lenght;
	delete[] save_p;
	delete[] save_Order;
}
