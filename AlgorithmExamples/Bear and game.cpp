#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n,value,sum=0;
	vector<int> v;
	v.push_back(0);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> value;
		v.push_back(value);
	}
	v.push_back(90);
	for (int j = 1; j < v.size(); j++)
	{
		if ((v[j] - v[j - 1]) > 15)
		{
			sum = 15 + v[j - 1];
			break;
		}
		else
			sum = v[j];
	}
	cout << sum;
	system("pause");
	return 0;
}
