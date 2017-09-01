#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int main()
{
	string s, t,k;
	cin >> s,t;
	for (int i = s.size(); i >0 ; i--)
	{
		if (s[i] < t[i])
			cout << s[i];
	}
	system("pause");
	return 0;
}