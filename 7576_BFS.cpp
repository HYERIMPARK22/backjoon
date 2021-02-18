#include <stdio.h>
#include <queue>
#define MAX 1001

using namespace std;
int m, n;
int ary[1001][1001];
int dirX[] = { 0,0,-1,1 };
int dirY[] = { 1,-1,0,0 };
int cnt = 0;

struct node {
	int x;
	int y;
};

int main()
{
	queue<node> q1;
	queue<node> q2;

	int tmp;
	node tmpN;
	scanf("%d %d", &m, &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &tmp);
			ary[j][i] = tmp;
			if (ary[j][i] == 1) {
				tmpN.x = j;
				tmpN.y = i;
				q1.push(tmpN);
			}

		}
	}

	while (1) {
		while (!q1.empty()) {

			tmpN = q1.front();
			q1.pop();
			for (int i = 0; i < 4; i++) {
				int tmpX = tmpN.x - dirX[i];
				int tmpY = tmpN.y - dirY[i];
				if (tmpX >= 0 && tmpY >= 0 && tmpX < m && tmpY < n) {
					if (ary[tmpX][tmpY] == 0)
					{
						q2.push({ tmpX,tmpY });
						ary[tmpX][tmpY] = 1;
					}
				}
			}

		}

		if (q2.size() == 0) {

			for (int i = 0; i < m; i++) {
				for (int j = 0; j < n; j++) {
					if (ary[i][j] == 0) {
						printf("-1\n");
						return 0;
					}
				}
			}

			printf("%d\n", cnt);
			return 0;

		}

		cnt++;
		q1 = q2;
		
		while (q2.size() != 0) {
			q2.pop();
		}

	}

}

