#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
bool option(int a, int b)
{
	return (a>b);
}
int main()
{
	int k, value;
	int sum = 0;
	int count = 0;
	cin >> k;
	vector<int> f;
	for (int i = 0; i < 12; i++)
	{
		cin >> value;
		f.push_back(value);
	}
	sort(f.begin(), f.end(),option);
	for (int i=0;i<12;i++)
	{
		if (sum >= k)
		{
			cout << count++;
			return 0;
		}
		sum += f[i];
		count++;
		if (sum >= k)
		{
			cout << count++;
			return 0;
		}
	}
	cout << "-1";
	return 0;
}