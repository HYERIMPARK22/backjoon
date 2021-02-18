#include <iostream>
using namespace std;

int main()
{
	int n;
	char num;
	int sum = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		sum += num - '0';
	}
	cout << sum << endl;
	return 0;
}