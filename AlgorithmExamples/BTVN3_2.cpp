#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int n, x, value;
	long long sum = 0;
	cin >> n >> x;
	vector<int> f;
	for (int i = 0; i <n; i++)
	{
		cin >> value;
		f.push_back(value);
	}
	sort(f.begin(), f.end());
	for (int i=0;i<n;i++)
	{
		if (x < 1)
			x = 1;
		sum += (long long)f[i] * x;
		x--;
	}
	cout << sum;
	system("pause");
	return 0;
}