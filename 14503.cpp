#include <iostream>
using namespace std;
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
int a[55][55];
int main() {
	int n, m;
	cin >> n >> m;
	int x, y, dir;
	cin >> x >> y >> dir;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	int cnt = 0;
	while (1) {
		if (a[x][y] == 0) {
			a[x][y] = 2;
		}
		//청소할 공간 없음
		if (a[x + 1][y] != 0 && a[x - 1][y] != 0 && a[x][y - 1] != 0 && a[x][y + 1] != 0) {
			//뒤쪽 방향이 벽
			if (a[x - dx[dir]][y - dy[dir]] == 1) {
				break;
			}
			//후진
			else {
				x -= dx[dir];
				y -= dy[dir];
			}
		}
		//청소할 공간 있음
		else {
			//회전
			dir = (dir + 3) % 4;
			if (a[x + dx[dir]][y + dy[dir]] == 0) {
				x += dx[dir];
				y += dy[dir];
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 2) {
				cnt += 1;
			}
		}
	}
	cout << cnt << '\n';

}