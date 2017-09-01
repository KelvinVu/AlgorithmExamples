#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	int n,value;
	cin >> n;
	queue<int> q;
	stack<int> s;
	do 
	{
		cin >> value;
		q.push(value);
	} while (value != 0);
	int a=1;
	while(a==value)
	{
		if (q.front() != a)
		{
			s.push(q.front());
			q.pop();
		}
		else
		{
			if (s.top() != (a + 1) && s.empty() == 1)
			{
				cout << "no";
				system("pause");
				return 0;
			}
			else
			{
				a++;
				if(s.empty==0)
					s.pop();
			}

		}
	}
	cout << "yes";
	system("pause");
	return 0;
}