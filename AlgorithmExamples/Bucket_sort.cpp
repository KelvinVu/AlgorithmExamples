#include<iostream>
#include<list>
using namespace std;

void insertion_sort(list <double> &b)
{
	int n = b.size(), pos;
	double *c; 
	c = new double[n];
	for (int i = 0; i < n; i++)
	{
		c[i] = b.front();
		b.pop_front();
	}
	for (int i = 1; i < n; i++)
	{
		double x = c[i];
		pos = i - 1;
		while ((pos >= 0) && (c[pos]>x))
		{
			c[pos + 1] = c[pos];
			pos--;
		}
		c[pos + 1] = x;
	}
	for (int i = 0; i < n; i++)
	{
		b.push_back(c[i]);
	}
}

void bucket_sort(list<double> &a)
{
	int n = a.size();
	list<double> *b;
	b = new list<double>[n];
	list<double>::iterator ptr;
	for (ptr = a.begin(); ptr!=a.end(); ptr++)
	{
		int k = n*(*ptr);
		b[k].push_back(*ptr);
	}
	for (int i = 0; i < n; i++)
	{
		insertion_sort(b[i]);
	}
	cout << "\nDanh sach sau khi dk sap xep co dang la: ";
	for (int i = 0; i < n; i++)
	{
		for (ptr = b[i].begin(); ptr != b[i].end(); ptr++)
			cout << *ptr << "  ";
	}
	cout << endl;
}

void main()
{
	list<double> a;
	list<double>::iterator prt;
	double x;
	int n;
	cout << "\nSo luong phan tu trong day: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "\nPhan tu thu: " << i + 1 << " co gia tri la: ";
		cin >> x;
		a.push_back(x);
	}
	cout << "\nDanh sach truoc khi sap xep co dang la: ";
	for (prt = a.begin(); prt != a.end(); prt++)
		cout << *prt << "  ";
	bucket_sort(a);
	cout << endl;
}