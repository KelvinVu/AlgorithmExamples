#include<iostream>    
#include<iomanip>
using namespace std;
#define max 100
int a[max], p, r;
void merge(int a[], int p, int q, int r)
{
	int n1 = q - p + 1, n2 = r - q, *left, *right;
	left = new int[n1 + 1];
	right = new int[n2 + 1];
	for (int i = 0; i < n1; i++)
	{
		left[i] = a[p + i];
	}
	for (int j = 0; j < n2; j++)
	{
		right[j] = a[q + j + 1];
	}
	left[n1] = INT_MAX;
	right[n2] = INT_MAX;
	int i = 0, j = 0, k = p;
	for (int k = p; k <= r; k++)
	{
			if (left[i] <= right[j])
			{
				a[k] = left[i];
				i++;
			}
			else
			{
				a[k] = right[j];
				j++;
			}
	}
}
void merge_sort(int a[], int p, int r)
{
	int q;
	if (p < r)
	{
		q = (p + r) / 2;
		merge_sort(a, p, q);
		merge_sort(a, q + 1, r);
		merge(a, p, q, r);
	}
}
void main()
{
	int  p = 0, r;
	cout << "\nSo luong phan tu: ";
	cin >> r;
	cout << "\nNhap vao gia tri cua cac phan tu ";
	for (int i = 0; i < r; i++)
	{
		cout << "\nNhap vao gia tri cua phan tu thu:  " << i + 1 << ": ";
		cin >> a[i];
	}
	merge_sort(a, p, r);
	cout << "\nDay cac phan tu da dk sap xep la: ";
	for (int i = 1; i <= r; i++)
	{
		cout << setw(4) << a[i];
	}
	cout << endl;
}