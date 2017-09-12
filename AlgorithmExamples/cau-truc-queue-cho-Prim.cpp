#include<iostream>
#include<iomanip>
using namespace std;
typedef int Itemtype;

struct PQueue
{
	Itemtype *items;
	int size;
	int max_size;
};

int parent(int i)
{
	return (i - 1) / 2;
}

int left(int i)
{
	return i * 2 + 1;
}

int right(int i)
{
	return i * 2 + 2;
}

void Max_queue(PQueue &q, int i)
{
	int smallest;
	Itemtype l = left(i);
	Itemtype r = right(i);
	if (l <= q.size && q.items[l]<q.items[i])
		smallest = l;
	else
		smallest = i;
	if (r <= q.size && q.items[r]<q.items[smallest])
		smallest = r;
	if (smallest != i)
	{
		swap(q.items[i], q.items[smallest]);
		Max_queue(q, smallest);
	}
}

void init(PQueue &q, int max_size)
{
	q.max_size = max_size;
	q.size = 0;
	q.items = new Itemtype[max_size];
}

void queue_increase(PQueue &q, int i, Itemtype key)
{
	q.items[i] = key;
	while (i>0 && q.items[parent(i)]>q.items[i])
	{
		swap(q.items[i], q.items[parent(i)]);
		i = parent(i);
	}
}

void enqueue(PQueue &q, Itemtype new_item)
{
	q.size = q.size + 1;
	q.items[q.size - 1] = INT_MAX;
	queue_increase(q, q.size - 1, new_item);
}

Itemtype dequeue(PQueue &q)
{
	if (q.size<0)
		return 0;
	else
	{
		Itemtype max;
		max = q.items[0];
		q.items[0] = q.items[q.size - 1];
		q.size--;
		Max_queue(q, 0);
		return max;
	}
}

void print(const PQueue q)
{
	for (int i = 0; i<q.size; i++)
		cout << setw(4) << q.items[i];
}

void main()
{
	PQueue q;
	int  n, key, kt;
	cout << "\nSo luong phan tu toi da trong queue: ";
	cin >> n;
	init(q, n);
	cout << "\nNhap phan tu them vao hang:";
	cout << endl;
	while (q.size<q.max_size)
	{
		cin >> key;
		enqueue(q, key);
	}
	cout << "\nSo phan tu hien co trong queue: " << q.size << endl;
	cout << "\nQueue co dang la: ";
	print(q);
	cout << "\nDequeue: ";
	kt = dequeue(q);
	if (kt == 0)
		cout << "\nQueue rong.";
	else
		cout << "\nGia tri lon nhat tra ve la: " << kt;
	cout << "\nQueue sau khi dequeue co dang la: ";
	print(q);
	cout << "\nEnqueue: ";
	cout << "\nNhap vao gia tri muon them vao queue: ";
	cin >> key;
	enqueue(q, key);
	print(q);
	cout << endl;
}





