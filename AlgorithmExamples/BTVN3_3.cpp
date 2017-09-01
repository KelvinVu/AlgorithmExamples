#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>

using namespace std;

bool option(int a, int b)
{
	return a < b;
}
int main()
{
	int n, w, value;
	double sum = 0;
	int count = 0;
	cin >> n>>w;
	vector<int> f;
	for (int i = 0; i < 2*n; i++)
	{
		cin >> value;
		f.push_back(value);
	}
	sort(f.begin(), f.end(),option);
	int minA = f[0];
	int minB = f[n];
	double x = (double)w / (3.0 * n);
	// so sánh lượng nước tối đa trong mỗi trường hợp nữ, nam, đổ hết bình.
	sum = min(min((((double)minB / 2) * 3.0 * n), (minA * 3.0 * n)), 3.0 * x * n);
	//if ((2 * minA >= 2 * x) && (minB <= 2 * x))
	//	sum = ((double)minB / 2) * 3.0 * n;
	//else if ((2 * minA <= 2 * x) && (minB >= 2 * x))
	//{
	//	sum = minA * 3.0 * n;
	//}
	//else if((x<minA) && (2*x<minB))
	//{
	//	sum = 3.0 * x * n;
	//}
	//else if((x>minA) && (2 * x>minB))
	//{
	//	if (2 * minA >= minB)
	//		sum = ((double)minB / 2) * 3.0 * n;
	//	else if(2 * minA <= minB)
	//		sum = minA * 3.0 * n;
	//}
	cout << fixed << setprecision(6) << sum;
	system("pause");
	return 0;
}
