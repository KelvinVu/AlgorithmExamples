#include<iostream>
#include<fstream>
#include<iomanip>
#include<list>
#include<cassert>
#include<vector>
#include<algorithm>
using namespace std;
struct Edge
{
	int form;
	int to;
	double weight;
	Edge(int u, int v, double w) : form(u), to(v), weight(w){}
};

struct Graph
{
	int nv;
	int ne;
	list<Edge> *adj;
	vector<Edge> edges;
};

struct Disjoin_set
{
	int *item;
	int n;

};

void init(Disjoin_set &S, int n)
{
	S.item = new int[n];
	S.n = n;
	for (int i = 0; i<n; i++)
		S.item[i] = i;
}

int find(Disjoin_set &S, int x)
{
	while (S.item[x] != x)
	{
		x = S.item[x];
	}
	return x;
}

void join(Disjoin_set &S, int x, int y)
{
	int rep1 = find(S, x);
	int rep2 = find(S, y);
	if (rep1 != rep2)
		S.item[rep1] = rep2;
}

void print(Disjoin_set &S)
{
	for (int i = 0; i<S.n; i++)
		cout << setw(4) << S.item[i];
}

void add_edge(Graph &g, Edge e)
{
	g.adj[e.form].push_back(e);
	g.adj[e.to].push_back(e);
	g.edges.push_back(e);
}

int init_from_file(Graph &g, char *myfile)
{
	int x, y, z;
	ifstream f(myfile, ios::out);
	if (!f)
		return 0;

	else
	{
		f >> g.nv;
		g.adj = new list<Edge>[g.nv];
		assert(g.nv>0);
		f >> g.ne;
		while (!f.eof())
		{
			f >> x;
			f >> y;
			f >> z;
			cout << endl;
			add_edge(g, Edge(x, y, z));
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
		cout << i << ": ";
		list<Edge>::iterator ptr;
		for (ptr = g.adj[i].begin(); ptr != g.adj[i].end(); ptr++)
		{
			Edge u = *ptr;
			cout << setw(5) << u.form << " " << u.to << " " << u.weight;
		}
		cout << endl;
	}
}

bool my_compare(Edge e1, Edge e2)
{
	return(e1.weight < e2.weight);
}

vector<Edge> Kruskal(Graph& g)
{
	vector<Edge> A;
	Disjoin_set S;
	init(S, g.nv);
	sort(g.edges.begin(), g.edges.end(), my_compare);
	cout << "\nCac canh trong do thi sau khi sap xep: ";
	cout << endl;
	vector<Edge>::iterator ptr;
	for (ptr = g.edges.begin(); ptr != g.edges.end(); ptr++)
	{
		Edge e = *ptr;
		std::cout << setw(5) << e.form << " " << e.to << " " << e.weight;
		cout << endl;
	}
	for (int i = 0; i < g.edges.size(); i++)
	{
		Edge e = g.edges[i];
		int u = e.form;
		int v = e.to;
		if (find(S, u) != find(S, v))
		{
			A.push_back(e);
			join(S, u, v);
		}
	}
	return A;
}

void main()
{
	Graph g;
	vector<Edge> MST;
	int count_weight_MTS = 0;
	init_from_file(g, "D:\\myfile.txt");
	print(g);
	MST = Kruskal(g);
	cout << "\nCac canh trong MST: ";
	cout << endl;
	vector<Edge>::iterator ptr;
	for (ptr = MST.begin(); ptr != MST.end(); ptr++)
	{
		Edge e = *ptr;
		std::cout << setw(5) << e.form << " " << e.to << " " << e.weight;
		count_weight_MTS = count_weight_MTS + e.weight;
		cout << endl;
	}
	cout << "\nTong trong so: " << count_weight_MTS;
	cout << endl;
}
