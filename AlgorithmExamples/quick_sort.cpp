#include<iostream>
#include<iomanip>
using namespace std;
#define max 100
int a[max];

int quick_partition(int a[], int p, int r)
{
	int x = a[r];
	int i = p - 1;
	int j = p;
	for (j = p; j < r; j++)
	{
		if (a[j] <= x)
		{
			i++;
			swap(a[j], a[i]);
		}
	}
	i++;
	swap(a[i], a[r]);
	return i;
}

void quick_sort(int a[], int p, int r)
{
	if (p < r)
	{
		int q = quick_partition(a, p, r);
		quick_sort(a, p, q - 1);
		quick_sort(a, q + 1, r);
	}
}

void random_quick_sort(int a[], int p, int r)
{
	if (p < r)
	{
		int i = rand() % (r + 1);
		swap(a[i], a[r]);
		int q = quick_partition(a, p, r);
		random_quick_sort(a, p, q - 1);
		random_quick_sort(a, q + 1, r);
	}
}

void main()
{
	int n, chon = -1;
	cout << "\nSo luong phan tu trong day: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "\nPhan tu thu: " << i + 1 << ": ";
		cin >> a[i];
	}
	cout << "\nDay truoc khi sap xep co dang la: ";
	for (int i = 0; i < n; i++)
		cout << setw(4) << a[i];
	while (chon != 0)
	{
		cout << "\nChon 1: Sap xep quick sort: ";
		cout << "\nChon 2: Sap xep random quick sort: ";
		cout << "\nChon 0: Thoat.";
		cout << "\nChon: ";
		cin >> chon;
		switch (chon)
		{
		case 1:
		{
				  quick_sort(a, 0, n - 1);
				  cout << "\nDay sau khi da sap xep quick sort co dang la: ";
				  for (int i = 0; i < n; i++)
					  cout << setw(4) << a[i];
				  cout << endl;
				  break;
		}

		case 2:
		{
				  random_quick_sort(a, 0, n - 1);
				  cout << "\nDay sau khi da sap xep random quick sort co dang la: ";
				  for (int i = 0; i < n; i++)
					  cout << setw(4) << a[i];
				  cout << endl;
				  break;
		}
		}
	}
	cout << endl;
}