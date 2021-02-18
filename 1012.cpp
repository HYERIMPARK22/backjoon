#include <stdio.h>
#include <queue>
#define MAX 51

using namespace std;

int t; //테스트 개수
int m, n, k;
int ary[MAX][MAX];
int dirX[] = { -1, 1, 0, 0 };
int dirY[] = { 0, 0, 1, -1 };
int cnt = 0;
void DFS(int x, int y);

int main()
{
	scanf("%d", &t);
	for (int l = 0; l < t; l++)
	{
		scanf("%d %d %d", &m, &n, &k);
		for (int i = 0; i < k; i++) {
			int tmpX, tmpY;
			scanf("%d %d", &tmpX, &tmpY);
			ary[tmpX][tmpY] = 1;
		}

		for (int j = 0; j < m; j++)
		{
			for (int k = 0; k < n; k++)
			{
				if (ary[j][k] == 1)
				{
					cnt++;
					ary[j][k] = 0;
					DFS(j, k);
				}
			}
		}

		printf("%d\n", cnt);
		cnt = 0;

	}


}

void DFS(int x, int y)
{
	for (int i = 0; i < 4; i++) {
			int tmpX = x + dirX[i];
			int tmpY = y + dirY[i];
			if(tmpX>=0 && tmpY>=0 && tmpX<m && tmpY<n)
				if (ary[tmpX][tmpY] == 1)
				{
					ary[tmpX][tmpY] = 0;
					DFS(tmpX, tmpY);
				}
	}
}