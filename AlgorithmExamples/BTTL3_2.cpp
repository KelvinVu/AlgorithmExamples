#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main()
{
	int n,value,l,r;
	cin >> n;
	vector<int> v,v2;
	for (int i = 0; i < n; i++)
	{
		cin >> value;
		v.push_back(value);
	}
	v2 = v;
	sort(v2.begin(), v2.end());
	int j = n-1;
	for (int i = 0; i <= n; i++)
	{
		if (v[i] != v2[i])
			l = i;
		for (; j < i; j--)
		{
			if (v[j] != v2[j])
				r = j;
		}
	}
}