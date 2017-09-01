#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n, k, j=-1 , value, count=0;
	vector<int> v1,v2;
	v2.resize(1000);
	
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> value;
		v1.push_back(value);
	}
	for (int i = 0; i < n; i++)
	{
		v2[v1[i]]++;
		if (v2[v1[i]]==1)
			count++;
		while (count==k)
		{
			j++;
			v2[v1[j]]--;
			if (v2[v1[j]] == 0)
			{
				cout << j+1 << " " << i+1;
				return 0;
			}
		}
	}
	cout << "-1 -1";
	return 0;
}