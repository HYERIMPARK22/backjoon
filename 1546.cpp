#include <iostream>
#define MAX 1000
using namespace std;

int main()
{
	double max = 0;
	int n;
	double sum = 0;
	double avg;

	cin >> n;
	double scoreOrignal[MAX], scoreChanged[MAX];
	for (int i = 0; i < n; i++) {
		cin >> scoreOrignal[i];
	}

	for (int i = 0; i < n; i++) {
		if (scoreOrignal[i] > max)
			max = scoreOrignal[i];
	}

	for (int i = 0; i < n; i++) {
		scoreChanged[i] = scoreOrignal[i] / max * 100;
		sum += scoreChanged[i];
	}

	avg = sum / n;
	cout << avg << endl;

	return 0;
}