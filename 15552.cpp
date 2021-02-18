#include <iostream>
#include <ios>
using namespace std;


int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int testCase;
	int a, b;
	cin >> testCase;
	int *p = new int[testCase];
	for (int i = 0; i < testCase; i++) {
		cin >> a >> b;
		p[i] = a + b;
	}

	for (int i = 0; i < testCase; i++) {
		cout << p[i] << '\n';
	}

	return 0;
}