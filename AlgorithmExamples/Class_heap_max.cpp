#include <iostream>
#include<iomanip>
using namespace std;

int left(int i)
{
	return 2 * i + 1;
}

int right(int i)
{
	return 2 * i + 2;
}

int parent(int i)
{
	return (i - 1) / 2;
}

class heap
{
	private:
		int heapsize;
		int heaplength;
		int *item;
	public:
		void max_heapify(heap& a, int i);
		void build_max_heap(heap& a, int arr[], int n);
		void heap_sort(int arr[], int n);
		int heap_maximum(heap a);
		int heap_extract_max(heap &a);
		void heap_increase_key(heap &a, int key, int i);
		void heap_insert(heap&a, int key);
		void printf(heap &a);
};

void heap::max_heapify(heap& a, int i)
{
	int l = left(i), r = right(i), largest;
	if (l<a.heapsize && a.item[l] > a.item[i])
		largest = l;
	else
		largest = i;
	if (r<a.heapsize && a.item[r] > a.item[largest])
		largest = r;
	if (i != largest)
	{
		swap(a.item[i], a.item[largest]);
		max_heapify(a, largest);
	}
}

void heap::build_max_heap(heap& a, int arr[], int n)
{
	a.item = arr;
	a.heaplength = n;
	a.heapsize = n;
	for (int i = a.heaplength / 2 - 1; i >= 0; i--)
		max_heapify(a, i);
}

void heap::heap_sort(int arr[], int n)
{
	heap a;
	build_max_heap(a, arr, n);
	for (int i = a.heaplength - 1; i > 0; i--)
	{
		swap(a.item[0], a.item[i]);
		a.heapsize = a.heapsize - 1;
		max_heapify(a, 0);
	}
}

int heap::heap_maximum(heap a)
{
	return a.item[0];
}

int heap::heap_extract_max(heap &a)
{
	if (a.heapsize >= 0)
	{
		int max;
		max = a.item[0];
		swap(a.item[0], a.item[a.heapsize - 1]);
		a.heapsize = a.heapsize - 1;
		a.heaplength--;
		max_heapify(a, 0);
		return max;
	}
	return 0;
}

void heap::heap_increase_key(heap &a, int key, int i)
{
	if (key > a.item[i])
	{
		a.item[i] = key;
		while (i > 0 && a.item[i] > a.item[parent(i)])
		{
			swap(a.item[i], a.item[parent(i)]);
			i = parent(i);
		}
	}
	else
		cout << "\nGia tri moi nho hon gia tri hien thoi. ";
}

void heap::heap_insert(heap & a, int key)
{
	a.heapsize = a.heapsize + 1;
	a.heaplength++;
	a.item[a.heapsize - 1] = INT_MIN;
	heap_increase_key(a, key, a.heapsize - 1);
}

void heap::printf(heap &a)
{
	for (int i = 0; i < a.heaplength; i++)
		cout << setw(4) << a.item[i];
}

void xuat(int arr[], int n)
{
	for (int i = 0; i<n; i++)
		cout << arr[i] << "  ";
}

void main()
{
	heap h;
	int n = 10, chon, key;
	int m, b[100];
	cout << "\nNhap so phan tu: ";
	cin >> m;
	cout << "\nNhap vao gai tri cac phan tu: ";
	for (int i = 0; i < m; i++)
	{
		cout << "\nPhan tu thu: " << i + 1<<": ";
		cin >> b[i];
	}
	do
	{
		cout << "\nThao tac tren heap"
			<< "\nChon 1: tao heap"
			<< "\nChon 2: sap xep"
			<< "\nChon 3: tra ve gia tri lon nhat"
			<< "\nChon 4: xoa gia tri lon nhat"
			<< "\nChon 5: tang chi so"
			<< "\nChon 6: them nut"
			<< "\nChon 0: Thoat "
			<< "\nChon: ";
		cin >> chon;
		switch (chon)
		{
			case 1:
			{
				  h.build_max_heap(h, b, m);
				  xuat(b, m);
				  break;
			}

			case 2:
			{
				  h.heap_sort(b, m);
				  xuat(b, m);
				  break;
			}
			case 3:
			{
				  h.build_max_heap(h, b, m);
				  cout << h.heap_maximum(h);
				  break;
			}
			case 4:
			{
				  h.build_max_heap(h, b, m);
				  cout << h.heap_extract_max(h);
				  cout << endl;
				  h.printf(h);
				  break;
			}
			case 5:
			{
				  int i;
				  cout << "\nNhap vi tri  muon tang: ";
				  cin >> i;
				  cout << "\nNhap gia tri: ";
				  cin >> key;
				  h.heap_increase_key(h, key, i);
				  h.printf(h);
				  break;
			}
			case 6:
			{
				  cout << "\nNhap gia tri: ";
				  cin >> key;
				  h.heap_insert(h, key);
				  h.printf(h);
				  break;
			}
		}
	} while (chon != 0);
		cout << endl;
}
