#include <iostream>
#include <queue>
using namespace std;

int main()
{
	priority_queue<long long> pq;
	int n,temp;
	int max1, max2, max3;
	vector<int> h;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		h.push_back(temp);
	}
	for (int i = 0; i < n; i++)
	{
		pq.push(h[i]);
		if (pq.size() < 3)
			cout << -1<<endl;
		else
		{
			max1 = pq.top();
			pq.pop();
			max2 = pq.top();
			pq.pop();
			max3 = pq.top();
			pq.pop();
			cout << max1*max2*max3<<endl;
			pq.push(max1);
			pq.push(max2);
			pq.push(max3);
		}
	}
	return 0;
}