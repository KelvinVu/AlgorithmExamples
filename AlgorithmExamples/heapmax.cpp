#include <iostream>
using namespace std;

struct heap
{
	int *item;
	int length;
	int heapsize;
};

int left(int i)
{
	return 2*i+1;
}

int right(int i)
{
	return 2*i+2;
}

int parent(int i)
{
	return (i-1)/2;
}


void xuat(int arr[], int n)
{
	for(int i=0;i<n;i++)
		cout<<arr[i]<<"  ";
}

void maxheapify(heap& a, int i)
{
	int l=left(i), r=right(i), largest;
	if(l<a.heapsize && a.item[l] > a.item[i])
		largest=l;
	else
		largest=i;
	if(r<a.heapsize && a.item[r] > a.item[largest])
		largest=r;
	if( i != largest)
	{
		swap(a.item[i], a.item[largest]);
		maxheapify(a,largest);
	}
}

void buildmaxheap(heap& a, int arr[], int n)
{
	a.item = arr;
	a.length = n;
	a.heapsize = n;
	for( int i = a.length/2-1; i >= 0; i--)
		maxheapify(a,i);
}

void heapsort( int arr[], int n)
{
	heap a;
	buildmaxheap(a,arr,n);
	for( int i= a.length-1 ; i > 0; i--)
	{
		swap(a.item[0],a.item[i]);
		a.heapsize = a.heapsize-1;
		maxheapify(a,0);
	}
}

int heapmaximum(heap &a)
{
	return a.item[0];
}

int heapextractmax (heap &a)
{
	if(a.heapsize >= 0)
	{
		int max;
		max = a.item[0];
		swap( a.item[0], a.item[a.heapsize-1]);
		a.heapsize = a.heapsize-1;
		maxheapify(a,0);
		return max;
	}
	return 0;
}

void heapincreasekey (heap &a, int key, int i)
{	
	if(key > a.item[i])
	{
		a.item[i] = key;
		while(i>0 && a.item[i] > a.item[parent(i)])
		{
			swap(a.item[i] , a.item[parent(i)]);
			i=parent(i);
		}
	}
}

void heapinsert( heap&a, int key)
{
	a.heapsize=a.heapsize+1;
	a.item[a.heapsize-1]=INT_MIN;
	heapincreasekey(a,key,a.heapsize-1);
}

void main()
{
	heap c;
	int arr[]={4,1,3,2,16,9,10,14,8,7};
	int n=10,chon,key;
	xuat(arr,n);
	cout<<endl;
	heapsort(arr,n);
	xuat(arr,n);
	do
	{
		cout<<"\nThao thac tren heap"
			<<"\n1 tao heap"
			<<"\n2 sap xep"
			<<"\n3 tra ve gia tri lon nhat"
			<<"\n4 xoa gia tri lon nhat"
			<<"\n5 tang chi so"
			<<"\n6 them nut";
		cin>>chon;
		switch(chon)
		{
		case 1:
			int m,b[100];
			cout<<"\nNhap so phan tu";
			cin>>m;
			for(int i=0 ; i<m ; i++)
			{
				b[i]=rand()%9;
				cout<<b[i]<<"  ";
			}
			cout<<endl;
			buildmaxheap(c,b,m);
			xuat(b,m);
			break;
		case 2:
			heapsort(b,m);
			xuat(b,m);
			break;
		case 3:
			cout<<heapmaximum(c);
			break;
		case 4:
			cout<<heapextractmax(c);
			cout<<endl;
			xuat(c.item,c.heapsize);
			break;
		case 5:
			int i;
			cout<<"\nNhap vi tri  muon tang";
			cin>>i;
			cout<<"\nNhap gia tri";
			cin>>key;
			heapincreasekey(c,key,i);
			xuat(c.item,c.heapsize);
			break;
		case 6:
			cout<<"\nNhap gia tri";
			cin>>key;
			heapinsert(c,key);
			xuat(c.item,c.heapsize);
			break;
		default:
			chon=0;
		}
	}while(chon !=0);
	cout<<endl;
}