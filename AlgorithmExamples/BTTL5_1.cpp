#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int main()
{
	string name;
	int sum=0;
	cin >> name;
	name.insert(0, "a");
	for (int i = 0; i < name.size()-1; i++)
	{
		if (abs(name[i] - name[i + 1]) < 13)
			sum += (int)abs(name[i] - name[i + 1]);
		else
		{
			sum += 26-(int)abs(name[i] - name[i + 1]);
		}
	}
	cout << sum;
	system("pause");
	return 0;
}