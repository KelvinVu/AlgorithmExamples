#include<iomanip>
#include<iostream>
#include<list>
#include<fstream>
#include<string>
#include<cassert>
#define NIL -1
#define WHITE 1
#define GRAY 2
#define BLACK 3
using namespace std;

list<int> Back;

struct Vertex
{
	int id;
	list<int> neighbor;
	int pi;
	int d;
	int f;
	int color;
};

list<Vertex> Topo_sort;
struct Graph
{
	int ne;
	int nv;
	bool disgraph;
	Vertex *adj;
	int time;
};

void DFS_Visit(Graph &g, int i)
{
	g.time++;
	g.adj[i].d = g.time;
	g.adj[i].color = GRAY;
	list<int>::iterator ptr;
	for (ptr = g.adj[i].neighbor.begin(); ptr != g.adj[i].neighbor.end(); ptr++)
	{
		int v = *ptr;
		if (g.adj[v].color == WHITE)
		{
			g.adj[v].pi = i;
			DFS_Visit(g, v);
		}
		else
		{
			if (g.adj[v].color == GRAY)
			{
				Back.push_back(i);
				Back.push_back(v);
			}
		}
	}
	g.adj[i].color = BLACK;
	g.time++;
	g.adj[i].f = g.time;
	Topo_sort.push_back(g.adj[i]);
}

void DFS(Graph &g)
{
	g.time=0;
	for (int i = 1; i <= g.nv; i++)
	{
		g.adj[i].color = WHITE;
		g.adj[i].pi = NIL;
	}
	for (int i = 1; i <= g.nv; i++)
	{
		if (g.adj[i].color == WHITE)
			DFS_Visit(g, i);
	}
}

void add_edge(Graph &g, int u, int v)
{
	g.adj[u].neighbor.push_back(v);
	if (!g.disgraph)
	{
		g.adj[v].neighbor.push_back(u);
	}
	g.ne++;
}

int init_from_file(Graph &g, char *myfile)
{
	int x, y;
	ifstream f(myfile, ios::out);
	if (!f)
		return 0;

	else
	{
		f >> g.nv;
		assert(g.nv>0);
		f >> g.disgraph;
		g.ne = 0;
		g.adj = new Vertex[g.nv + 1];
		for (int i = 1; i <= g.nv; i++)
			g.adj[i].id = i;
		while (f >> x >> y)
		{
			add_edge(g, x, y);
		}
		f.close();
		return 1;
	}
}

void print(Graph &g)
{
	cout << "\nG(" << g.nv << "," << g.ne << ")";
	if (g.disgraph == 0)
		cout << "  " << "vo huong";
	else
		cout << "  " << "co huong";
	for (int i = 1; i <= g.nv; i++)
	{
		cout << "\nDinh " << i << ": ";
		list<int>::iterator ptr;
		for (ptr = g.adj[i].neighbor.begin(); ptr != g.adj[i].neighbor.end(); ptr++)
		{
			cout << *ptr << "\t";
		}
		cout << endl;
	}
	cout << "\nKet thuc thuc hien DFS... ";
	for (int i = 1; i <= g.nv; i++)
	{
		cout << "\nDinh " << i << " (" << g.adj[i].d << ";" << g.adj[i].f << ")";
		if (g.adj[i].pi == NIL)
			cout << " ---> goc";
	}
	cout << endl;
	cout << "\nCac cap dinh quay dau: ";
	while (!Back.empty())
	{
		cout << "\n(" << Back.front();
		Back.pop_front();
		cout << "," << Back.front() << ")";
		Back.pop_front();
	}
}

void dem_bac_Graph(Graph &g)
{
	int *out, *in, *deg;
	list<int>::iterator ptr;
	out = new int[g.nv];
	in = new int[g.nv];
	deg = new int[g.nv];
	for (int i = 1; i <= g.nv; i++)
	{
		out[i] = 0;
		in[i] = 0;
	}
	if (!g.disgraph)
	{
		for (int u = 1; u <= g.nv; u++)
		{
			for (ptr = g.adj[u].neighbor.begin(); ptr != g.adj[u].neighbor.end(); ptr++)
			{
				out[u]++;
			}
		}
		cout << endl;
		cout << "\nBac cua cac dinh: ";
		for (int u = 1; u <= g.nv; u++)
			cout << setw(4) << out[u];
	}
	else
	{
		for (int u = 0; u <= g.nv; u++)
		{
			for (ptr = g.adj[u].neighbor.begin(); ptr != g.adj[u].neighbor.end(); ptr++)
			{
				out[u]++;
			}
		}

		for (int u = 0; u <= g.nv; u++)
		{
			for (ptr = g.adj[u].neighbor.begin(); ptr != g.adj[u].neighbor.end(); ptr++)
			{
				out[*ptr]++;
			}
		}

		for (int u = 0; u <= g.nv; u++)
		{
			deg[u] = in[u] + out[u];
		}
		cout << endl;
		cout << "\nBac cua cac dinh: ";
		for (int u = 1; u <= g.nv; u++)
			cout << setw(4) << deg[u];
	}
}

void write()
{
	ofstream myfile;
	myfile.open("D:\\myfile.txt");
	cout << "\nMo dk file.";
	cout << "\nNhap vao noi dung: ";
	myfile << 14;
	myfile << "\n";
	myfile << 1;
	myfile << "\n";
	myfile << "1 12";
	myfile << "\n";
	myfile << "1 5";
	myfile << "\n";
	myfile << "1 6";
	myfile << "\n";
	myfile << "2 3";
	myfile << "\n";
	myfile << "2 5";
	myfile << "\n";
	myfile << "2 9";
	myfile << "\n";
	myfile << "3 6";
	myfile << "\n";
	myfile << "3 7";
	myfile << "\n";
	myfile << "3 10";
	myfile << "\n";
	myfile << "4 3";
	myfile << "\n";
	myfile << "4 7";
	myfile << "\n";
	myfile << "4 14";
	myfile << "\n";
	myfile << "5 8";
	myfile << "\n";
	myfile << "6 9";
	myfile << "\n";
	myfile << "6 13";
	myfile << "\n";
	myfile << "7 6";
	myfile << "\n";
	myfile << "9 8";
	myfile << "\n";
	myfile << "10 11";
	myfile << "\n";
	myfile << "10 12";
	myfile << "\n";
	myfile << "11 14";
	myfile << "\n";
	myfile << "13 10";
	myfile.close();

}

void main()
{
	Graph g;
	int  u, v;
	int i;
	write();
	i = init_from_file(g, "D:\\myfile.txt");
	if (i != 0)
	{
		cout << "\nDo thi danh sach ke co dang la: ";
		DFS(g);
		print(g);
		dem_bac_Graph(g);
		cout<<"\nTopo sort: ";
		list<Vertex>::iterator ptr;
		for(ptr=Topo_sort.begin(); ptr!=Topo_sort.end(); ptr++)
		{
			Vertex v=*ptr;
			cout<<"\n"<<v.id<<":"<<"("<<v.d<<","<<v.f<<")";
		}
	}
	else
		cout << "\nKhong mo dk file";
	cout << endl;
}
