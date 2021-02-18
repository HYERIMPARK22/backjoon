#include <iostream>
using namespace std;
int a[20][20];
int dice[7];
//int dx[] = { 1,-1,0,0 };
//int dy[] = { 0,0,-1,1 };
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0, 0 };

int main() {
	int n, m, x, y, k;
	cin >> n >> m >> x >> y >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}

	while (k--) {
		int dir;
		cin >> dir;
		dir--;
		int nx, ny;
		nx = x + dx[dir];
		ny = y + dy[dir];
		if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
			continue;
		}
		if (dir == 0) {
			int temp = dice[1];
			dice[1] = dice[4];
			dice[4] = dice[6];
			dice[6] = dice[3];
			dice[3] = temp;
		}

		else if (dir == 1) {
			int temp = dice[1];
			dice[1] = dice[3];
			dice[3] = dice[6];
			dice[6] = dice[4];
			dice[4] = temp;
		}

		else if (dir == 2) {
			int temp = dice[1];
			dice[1] = dice[5];
			dice[5] = dice[6];
			dice[6] = dice[2];
			dice[2] = temp;
		}
		else {
			int temp = dice[1];
			dice[1] = dice[2];
			dice[2] = dice[6];
			dice[6] = dice[5];
			dice[5] = temp;
		}

		x = nx;
		y = ny;

		if (a[x][y] == 0) {
			a[x][y] = dice[6];
		}

		else {
			dice[6] = a[x][y];
			a[x][y] = 0;
		}

		cout << dice[1] << '\n';
	}
	return 0;
}