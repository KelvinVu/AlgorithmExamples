#include <iostream>
#include <queue>
#include <functional>
using namespace std;

int main()
{
	//dùng 1 heap để lưu 1 heap để xóa
	priority_queue<long long,vector<int>, greater<int>> pq;
	priority_queue<long long, vector<int>, greater<int>> pq2;
	int n, temp;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		switch (temp)
		{
			case 1:
			{
				cin >> temp;
				pq.push(temp);
			}
			case 2:
			{
				cin >> temp;
				while (!pq.empty())
				{
					if (pq.top == temp)
					{
						pq.pop();
					}
					else
					{
						pq2.push(pq.top());
						pq.pop();
					}
				}

			}
			case 3:
			{
				cout << pq2.top();
			}
		}
	}
	return 0;
}