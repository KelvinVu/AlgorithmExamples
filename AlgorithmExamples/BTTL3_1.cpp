#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n, a, b,value;
	int count = 0;
	cin >> n >> a >> b;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		cin >> value;
		v.push_back(value);
	}
	sort(v.begin(), v.end());
	cout << v[n - a] - v[b-1];
	return 0;
}