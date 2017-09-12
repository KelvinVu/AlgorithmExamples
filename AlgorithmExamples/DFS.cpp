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

struct Graph
{
	int ne;
	int nv;
	bool disgraph;
	Vertex *adj;
};

void DFS_Visit(Graph &g, int i, int &time)
{
	time = time + 1;
	g.adj[i].d = time;
	g.adj[i].color = GRAY;
	list<int>::iterator ptr;
	for (ptr = g.adj[i].neighbor.begin(); ptr != g.adj[i].neighbor.end(); ptr++)
	{
		int v = *ptr;
		if (g.adj[v].color == WHITE)
		{
			g.adj[v].pi = i;
			DFS_Visit(g, v, time);
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
	time = time + 1;
	g.adj[i].f = time;
}

void DFS(Graph &g)
{
	int time = 0;
	for (int i = 0; i < g.nv; i++)
	{
		g.adj[i].color = WHITE;
		g.adj[i].pi = NIL;
	}
	for (int i = 0; i < g.nv; i++)
	{
		if (g.adj[i].color == WHITE)
			DFS_Visit(g, i, time);
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
		for (int i = 0; i<g.nv; i++)
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
	for (int i = 0; i < g.nv; i++)
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
	for (int i = 0; i < g.nv; i++)
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
	for (int i = 0; i < g.nv; i++)
	{
		out[i] = 0;
		in[i] = 0;
	}
	if (!g.disgraph)
	{
		for (int u = 0; u < g.nv; u++)
		{
			for (ptr = g.adj[u].neighbor.begin(); ptr != g.adj[u].neighbor.end(); ptr++)
			{
				out[u]++;
			}
		}
		cout << endl;
		cout << "\nBac cua cac dinh: ";
		for (int u = 0; u < g.nv; u++)
			cout << setw(4) << out[u];
	}
	else
	{
		for (int u = 0; u < g.nv; u++)
		{
			for (ptr = g.adj[u].neighbor.begin(); ptr != g.adj[u].neighbor.end(); ptr++)
			{
				out[u]++;
			}
		}

		for (int u = 0; u < g.nv; u++)
		{
			for (ptr = g.adj[u].neighbor.begin(); ptr != g.adj[u].neighbor.end(); ptr++)
			{
				out[*ptr]++;
			}
		}

		for (int u = 0; u < g.nv; u++)
		{
			deg[u] = in[u] + out[u];
		}
		cout << endl;
		cout << "\nBac cua cac dinh: ";
		for (int u = 0; u < g.nv; u++)
			cout << setw(4) << deg[u];
	}
}

void write()
{
	ofstream myfile;
	myfile.open("D:\\myfile.txt");
	cout << "\nMo dk file.";
	cout << "\nNhap vao noi dung: ";
	myfile << 6;
	myfile << "\n";
	myfile << 1;
	myfile << "\n";
	myfile << "0 1";
	myfile << "\n";
	myfile << "0 3";
	myfile << "\n";
	myfile << "1 4";
	myfile << "\n";
	myfile << "2 4";
	myfile << "\n";
	myfile << "2 5";
	myfile << "\n";
	myfile << "3 1";
	myfile << "\n";
	myfile << "4 3";
	myfile << "\n";
	myfile << "5 5";

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
	}
	else
		cout << "\nKhong mo dk file";
	cout << endl;
}
