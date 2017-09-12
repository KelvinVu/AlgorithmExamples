#include<iostream>
#include<fstream>
#include<iomanip>
#include<list>
#include<cassert>
#include<vector>
#include<algorithm>
#define NIL -1
using namespace std;

struct Neighbor
{
	int id;
	double weight;    //key trong queue
	Neighbor() {}
	Neighbor(int v, double w) : id(v), weight(w){}
};

struct Vertex
{
	int id;
	int pi;
	vector<Neighbor> neighbor;
	Vertex(int i) : id(i){}
};

struct Graph
{
	int nv;
	int ne;
	vector<Vertex> Ver;
};

typedef Neighbor Itemtype;

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
	int l = left(i);
	int r = right(i);
	if (l < q.size && q.items[l].weight < q.items[i].weight)
		smallest = l;
	else
		smallest = i;
	if (r < q.size && q.items[r].weight<q.items[smallest].weight)
		smallest = r;
	if (smallest != i)
	{
		swap(q.items[i], q.items[smallest]);
		Max_queue(q, smallest);
	}
}

void init(PQueue &q, vector<Vertex> vex)
{
	q.max_size = vex.size();
	q.size = 0;
	q.items = new Neighbor[q.max_size];
}

void queue_increase(PQueue &q, int i, double key)
{
	q.items[i].weight = key;
	while (i>0 && q.items[parent(i)].weight> q.items[i].weight)
	{
		swap(q.items[i], q.items[parent(i)]);
		i = parent(i);
	}
}

void enqueue(PQueue &q, Itemtype new_item)
{
	q.size = q.size + 1;
	q.items[q.size - 1] = new_item;
	queue_increase(q, q.size - 1, new_item.weight);
}

Itemtype dequeue(PQueue &q)
{
	Itemtype min;
	min = q.items[0];
	q.items[0] = q.items[q.size - 1];
	q.size--;
	Max_queue(q, 0);
	return min;
}

void print(const PQueue q)
{
	for (int i = 0; i<q.size; i++)
		cout << q.items[i].id << "  ";
}

void add_edge(Graph &g, int from, int to, double w)
{
	g.Ver[from].neighbor.push_back(Itemtype(to, w));
	g.Ver[to].neighbor.push_back(Itemtype(from, w));
}

int init_from_file(Graph &g, char *myfile)
{
	int x, y;
	double z;
	ifstream f(myfile, ios::out);
	if (!f)
		return 0;

	else
	{
		f >> g.nv;
		assert(g.nv>0);
		for (int i = 0; i < g.nv; i++)
		{
			Vertex u(i);
			g.Ver.push_back(u);
		}
		f >> g.ne;
		while (!f.eof())
		{
			f >> x;
			f >> y;
			f >> z;
			add_edge(g, x, y, z);
		}
		f.close();
		return 1;
	}
}

void print(Graph &g)
{
	cout << "G(" << g.nv << "," << g.ne << ")";
	cout << endl;
	for (int i = 0; i<g.nv; i++)
	{
		cout << g.Ver[i].id << ": ";
		int u = g.Ver[i].neighbor.size();
		for (int j = 0; j < u; j++)
			cout << "(" << g.Ver[i].neighbor[j].id << "," << g.Ver[i].neighbor[j].weight << ")" << "  ";
		cout << endl;
	}
}

int search_queue(PQueue &q, int id)
{
	for (int i = 0; i < q.size; i++)
	{
		if (q.items[i].id == id)
			return i;
	}
	return -1;
}

void print(PQueue q)
{
	cout << "\nDanh sach queue: ";
	for (int i = 0; i<q.max_size; i++)
		cout << "\n(" << q.items[i].to << "," << q.items[i].weight << ")" << "  ";
}

void Prim(Graph& g, int r)
{
	double count = 0;
	PQueue q;
	for (int i = 0; i < g.nv; i++)
	{
		g.Ver[i].pi = NIL;
	}

	init(q, g.Ver);
	for (int i = 0; i < g.nv; i++)
	{
		Itemtype item;
		item.id = g.Ver[i].id;
		item.weight = INT_MAX;
		enqueue(q, item);
	}

	queue_increase(q, r, 0);
	cout << "\nCac canh trong MST: ";
	while (q.size > 0)
	{
		Itemtype u = dequeue(q);
		if (g.Ver[u.id].pi != NIL) //Khong tinh dinh goc
		{
			cout << "\n(" << g.Ver[u.id].pi << "," << g.Ver[u.id].id << ")";
		}
		count = count + u.weight; //Tong trong so
		/*cout << "\nDinh dang dk xet: " << char(u.id + 'a');  //Kiem tra cac dinh dang xet
		cout << endl;*/
		int k = g.Ver[u.id].neighbor.size();
		for (int i = 0; i < k; i++)  //duyet ds ke cua u 
		{
			Neighbor v = g.Ver[u.id].neighbor[i];
			int find = search_queue(q, v.id);
			if (find != -1 && (g.Ver[u.id].neighbor[i].weight < q.items[find].weight))
			{
				g.Ver[v.id].pi = u.id;
				queue_increase(q, find, g.Ver[u.id].neighbor[i].weight);
			}
		}
	}
	print(q);
	cout << "\nTong trong so la: " << count;
}

void main()
{
	Graph g;
	int r, i;
	i = init_from_file(g, "D:\\myfile.txt");
	if (i == 1)
	{
		print(g);
		cout << "\nXuat phat tu dinh: ";
		cin >> r;
		Prim(g, r);
		cout << endl;
	}
	else
		cout << "\nKhong mo dk file";
}
