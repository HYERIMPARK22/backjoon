#include <iostream>
#define MAX 1000000
using namespace std;
int numAry[MAX+1];

int main() {
	int start, end;
	cin >> start >> end;
	numAry[1] = 1;

	for (int i = 2; i <= end; i++) {
		for (int j = 2; i*j <= end; j++) {
			numAry[i*j] = 1;
		}
	}

	for (int i = start; i <= end; i++) {
		if (numAry[i] == 0) cout << i << '\n';
	}

	return 0;
}

//#include <stdio.h>
//#define MAX 1000000
//int numAry[MAX + 1];
//
//int main() {
//	int m, n;
//	scanf("%d %d", &m, &n);
//	numAry[1] = 1;
//
//	for (int i = 2; i <= n; i++) {
//		for (int j = 2; i*j <= n; j++) {
//			numAry[i*j] = 1;
//		}
//	}
//
//	for (int i = m; i <= n; i++) {
//		if (numAry[i]==0) printf("%d\n", i);
//	}
//
//	return 0;
//}