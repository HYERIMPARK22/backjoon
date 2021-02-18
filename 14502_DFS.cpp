#include <iostream>
#include <queue>

#define MAX 9
using namespace std;
int ary[9][9];
int tmpAry[9][9];
void DFS(int x, int y);
int nDepth = 0;
int n, m;
int dirX[] = { 0,0,-1,1};
int dirY[] = { 1,-1,0,0 };
int maxCnt = -5;
void DFS(int x, int y);
void countSafeArea();


struct node {
	int x;
	int y;
};

int main()
{
	int tmp;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> tmp;
			ary[j][i] = tmp;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (ary[j][i] == 0) {
				ary[j][i] = 1;
				nDepth++;
				DFS(j, i);
				nDepth--;
				ary[j][i] = 0;
			}
		}
	}

	cout << maxCnt << endl;

}

void DFS(int x, int y)
{
	if (nDepth == 3) {
		countSafeArea();
		return;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (ary[j][i] == 0) {
				ary[j][i] = 1;
				nDepth++;
				DFS(j, i);
				nDepth--;
				ary[j][i] = 0;
			}
		}
	}

}

void countSafeArea() {
	queue<node> q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			tmpAry[j][i] = ary[j][i];
			if (tmpAry[j][i] == 2)
				q.push({ j,i });
		}
	}

	while (!q.empty()) {
		node tmp = q.front();
		q.pop();
		int tmpX, tmpY;
		for (int i = 0; i < 4; i++) {
			tmpX = tmp.x + dirX[i];
			tmpY = tmp.y + dirY[i];
			if (tmpX >= 0 && tmpY >= 0 && tmpX < m && tmpY < n) {
				if (tmpAry[tmpX][tmpY] == 0) {
					tmpAry[tmpX][tmpY] = 3;
					q.push({ tmpX,tmpY });
				}
			}
		}
	}

	int tmpCnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (tmpAry[j][i] == 0)
				tmpCnt++;
		}
	}

	if (tmpCnt > maxCnt)
		maxCnt = tmpCnt;
	
}

