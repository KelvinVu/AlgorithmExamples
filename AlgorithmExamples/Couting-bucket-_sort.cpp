#include<iomanip>
#include<iostream>
using namespace std;
#define max 100

struct node
{
	float info;
	node *link;
};
 
int maximum(int a[], int n)
{
	int largest;
	largest = a[0];
	for (int i = 1; i < n; i++)
	{
		if (largest < a[i])
			largest = a[i];
	}
	return largest;
}

void couting_sort(int a[], int b[], int c[], int k, int n)
{
	for (int i = 0; i <= k; i++)
		c[i] = 0;
	for (int i = 1; i <= n; i++)
		c[a[i]] = c[a[i]] + 1;
	for (int i = 1; i <= k; i++)
		c[i] = c[i] + c[i - 1];
	for (int i = n; i >0; i--)
	{
		b[c[a[i]]] = a[i];
		c[a[i]]--;
	}
}

void bucking_sort(float a[], int n)
{
	node *d[10], *z, *p, *x, *q;
	q = new node;
	x = new node;
	z = new node;
	z->link = z;
	for (int i = 0; i < 10; i++)
	{
		d[i] = new node;
		d[i]->link = z;
	}
	for (int i = 1; i <= n; i++)
	{
		z->info = a[i];
		x->info = a[i];
		int k = n*a[i];
		cout << "\nGia tri cua k la: " << k;
		p = d[k];
		cout << "\nGia tri dia chi cua p: " << p;
		q = p;
		p = p->link;
		while (p!=z && p->info<a[i])
		{
			q = p;
			p = p->link;
		}
		x->link = p;
		q->link = x;
		cout << "\nGia tri phan tu trong z la: " << z->info;
		cout << "\nDay phan tu trong d[" << k << "] la:";
		p = d[k];
		p = p->link;
		if (p != z)
		{
			cout << "\t" << p->info;
			p = p->link;
		}
	}
	cout << "\nSap xep day theo bucking_sort: ";
	for (int i = 0; i <10; i++)
	{
		cout << "\nHang thu: " << i << " co cac phan tu: ";
		p = d[i];
		p = p->link;
		if (p!=z)
		{
			cout << "\t" << p->info;
			p = p->link;
		}
	}
}

void main()
{
	int n, k, chon =-1;
	cout << "\nSo luong phan tu trong day A: ";
	cin >> n;
	do
	{
		cout << "\nChon 1: Sap xep day theo couting_sort: ";
		cout << "\nChon 2: Sap xep day thap bucking_sort: ";
		cout << "\nChon 0: Thoat.";
		cout << "\nChon: ";
		cin >> chon;
		switch (chon)
		{
			case 1:
			{
					  int a[max], b[max], c[max];
					  for (int i = 1; i <= n; i++)
					  {
						  cout << "\nPhan tu thu " << i << " co gia tri la: ";
						  cin >> a[i];
					  }
					  cout << "\nDay truoc kh dk sap xep co dang la: ";
					  for (int i = 1; i <= n; i++)
						  cout << setw(4) << a[i];
					  k = maximum(a, n);
					  cout << "\nGia tri lon nhat trong day la: " << k;
					  couting_sort(a, b, c, k, n);
					  cout << "\nDay sau khi da dk sap xep theo couting sort: ";
					  for (int i = 1; i <= n; i++)
						  cout << setw(4) << b[i];
					  break;
			}
			case 2:
			{
					  float a[max];
					  for (int i = 1; i <= n; i++)
					  {
						  cout << "\nPhan tu thu " << i << " co gia tri la: ";
						  cin >> a[i];
					  }
					  cout << "\nDay truoc khi dk sap xep co dang la: ";
					  for (int i = 1; i <= n; i++)
						  cout << "\t"<< a[i];
					  bucking_sort(a, n);
					  break;
			}
		}
	} while (chon != 0);
	cout << endl;
}