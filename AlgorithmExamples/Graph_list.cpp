#include<iostream>
#include<iomanip>
#include<list>
using namespace std;

struct Graph
{
	int ne;
	int nv;
	bool disgraph;
	list<int> *adj;
};

void init(Graph &g, int nv, bool disgraph)
{
	g.nv = nv;
	g.ne = 0;
	g.disgraph = disgraph;
	g.adj = new list<int>[nv + 1];
}

void add_edge(Graph &g, int u, int v)
{
	g.adj[u].push_back(v);
	if (!g.disgraph)
	{
		if (u!=v)
			g.adj[v].push_back(u);
	}
	g.ne++;
}

void print(Graph &g)
{
	for (int i = 1; i <= g.nv; i++)
	{
		cout << "\nDinh " << i << ": ";
		list<int>::iterator ptr;
		for (ptr = g.adj[i].begin(); ptr != g.adj[i].end(); ptr++)
		{
			cout << *ptr << "\t";
		}
		cout << endl;
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
			for (ptr = g.adj[u].begin(); ptr != g.adj[u].end(); ptr++)
			{
				out[u]++;
			}
		}
		cout << "\nBac cua cac dinh: ";
		for (int u = 1; u <= g.nv; u++)
			cout << setw(4) << out[u];
	}
	else
	{
		for (int u = 1; u <= g.nv; u++)
		{
			for (ptr = g.adj[u].begin(); ptr != g.adj[u].end(); ptr++)
			{
				out[u]++;
			}
		}
		
		for (int u = 1; u <= g.nv; u++)
		{
			for (ptr = g.adj[u].begin(); ptr != g.adj[u].end(); ptr++)
			{
				in[*ptr]++;
			}
		}

		for (int u = 1; u <= g.nv; u++)
		{
			deg[u] = in[u] + out[u];
		}

		cout << "\nBac cua cac dinh: ";
		for (int u = 1; u <= g.nv; u++)
			cout << setw(4) << deg[u];
	}
}

void delete_edge(Graph &g, int u, int v)
{
	list<int> c;
	while (!g.adj[u].empty())
	{
		if (g.adj[u].front() != v)
		{
			c.push_back(g.adj[u].front());
			g.adj[u].pop_front();
		}
		else
			g.adj[u].pop_front();
	}
	while (!c.empty())
	{
		g.adj[u].push_back(c.front());
		c.pop_front();
	}
	if (!g.disgraph)
	{
		while (!g.adj[v].empty())
		{
			if (g.adj[v].front() != u)
			{
				c.push_back(g.adj[v].front());
				g.adj[v].pop_front();
			}
			else
				g.adj[v].pop_front();
		}
		while (!c.empty())
		{
			g.adj[v].push_back(c.front());
			c.pop_front();
		}
	}
}

void main()
{
	Graph g;
	int nv, u, v;
	bool disgraph;
	cout << "\nSo luong dinh cau do thi: ";
	cin >> nv;
	cout << "\nDo thi co huong hay vo huong: ";
	cin >> disgraph;
	init(g, nv, disgraph);
	add_edge(g, 1, 2);
	add_edge(g, 1, 4);
	add_edge(g, 2, 5);
	add_edge(g, 3, 5);
	add_edge(g, 3, 6);
	add_edge(g, 4, 2);
	add_edge(g, 5, 4);
	add_edge(g, 6, 6);
	cout << "\nDo thi danh sach ke co dang la: ";
	print(g);
	cout << "\nBan muon xoa canh tu dinh: ";
	cin >> u;
	cout << " Toi dinh: ";
	cin >> v;
	delete_edge(g, u, v);
	cout << "\nDo thi danh sach ke sau khi xoa co dang la: ";
	print(g);
	dem_bac_Graph(g);
	cout << endl;
}
