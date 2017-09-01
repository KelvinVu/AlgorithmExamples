#include <iostream>
#include <vector>
#include <stack>
using namespace std;
#define MAX 100
int V;
bool visited[MAX];
int path[MAX];
vector<int> graph[MAX];

void printPathRecursion(int u, int v, int path[])
{
	if (u == v)
		cout << v << " ";
	else
		if (path[v] == -1)
			cout << "No path" << endl;
		else
		{
			printPathRecursion(u, path[v], path);
			cout << v << " ";
		}
}
void printPath(int s, int f, int path[])
{
	int b[MAX];
	int m = 0;
	while (1)
	{
		b[m++] = f;
		f = path[f];
		if (f == s)
		{
			b[m++] = s;
			break;
		}
	}
	for (int i = m - 1; i >= 0; i--)
	{
		cout << b[i] << " ";
	}
}
void DFS(int src)
{
	for (int i = 0; i < V; i++)
	{
		visited[i] == false;
		path[i] = -1;
	}
	stack<int> s;
	visited[src] = true;
	s.push(src);
	vector<int>::iterator i;
	while (!s.empty())
	{
		src = s.top();
		s.pop();
		for (i = graph[src].begin(); i != graph[src].end(); i++)
		{
			if (! visited[*i])
			{
				visited[*i] = true;
				s.push(*i);
				path[*i] = src;
			}
		}
	}
}
int main()
{
	int countries, u, v;
	cin >>countries;
	for (int i = 0; i < countries; i++)
	{
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	int girls,value;
	vector<int> girl;
	cin >> girls;
	for (int i = 0; i < girls; i++)
	{
		cin >> value;
		girl.push_back(value);
	}
	int s = 1;
	int d = 5;
	DFS(s);
	printPath(s, d, path);
	return 0;
}