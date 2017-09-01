#include <iostream>
#include <list>
#include <queue>

using namespace std;

#define MAX 100
int V, E;
bool visited[MAX];
int path[MAX];

list<int> graph[MAX];
int main()
{
	int u, v;
	cin >> V >> E;
	for (int i = 0; i < E; i++)
	{
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);

	}
	int s = 0;
	int d = 5;
	BFS(s);
	printPath(s, d, path);
	return 0;
}
void BFS(int s)
{
	for (int i = 0; i < V; i++)
	{
		visited[i] = false;
		path[i]=-1;
	}
	queue<int> q;
	visited[s] = true;
	q.push(s);
	list<int>::iterator i;
	while (!q.empty())
	{
		s = q.front();
		q.pop();
		for (i = graph[s].begin(); i != graph[s].end(); i++)
		{
			if (! visited[*i])
			{
				visited[*i] = true;
				q.push(*i);
				path[*i] = s;
			}
		}
	}
}
void printPath(int s, int f, int back[])
{
	int b[MAX];
	int m = 0;
	while (true)
	{
		b[m++] = f;
		f = back[f];
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
//void printPathRecursion(int u, int v, int back[])
//{
//	if (u == v)
//		cout << v << " ";
//	else
//	{
//		if (back[v] == -1)
//			cout << "Khong co duong di \n";
//		else
//		{
//			printPathRecursion(u, back[v], back);
//			cout << v << " ";
//		}
//	}
//}
