#include <iostream>
#include <queue>	
#define MAX 101
using namespace std;
int n, m, tmp;
int ary[MAX][MAX];
int visited[MAX][MAX];
int dirX[] = { 0,0,-1,1 };
int dirY[] = { 1,-1,0,0 };


struct node
{
	int x;
	int y;
	int length;
};

int main()
{
	cin >> m >> n;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%1d",&tmp);
			ary[j][i] = tmp;
		}
	}

	queue<node> q;
	node tmpNode;
	q.push({1,1,1});
	

	while (1) {

		while (!q.empty()) {
			tmpNode = q.front();
			q.pop();
			

			for (int i = 0; i < 4; i++) {

				int tmpX = tmpNode.x + dirX[i];
				int tmpY = tmpNode.y + dirY[i];

				if (ary[tmpX][tmpY] == 1 && visited[tmpX][tmpY]==0) {
					visited[tmpX][tmpY] = 1;
					q.push({ tmpX, tmpY, tmpNode.length+1});
					if (tmpX == n && tmpY == m) {
						cout << tmpNode.length+1 << endl;
						return 0;
					}
				}

			}

		}


	}



}