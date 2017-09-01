#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n, k,value;
	int sum = 0,count=0;
	cin >> n >> k;
	vector<int> v1;
	for (int i = 0; i < n; i++)
	{
		cin >> value;
		v1.push_back(value);
	}
	int j = 0;
	for (int i = 0; i < n; i++) {
		sum += v1[i];
		if (sum <= k)
			count++;
		while (sum<=k) {

		}
	}
	return 0;
}