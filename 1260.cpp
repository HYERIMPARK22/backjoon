#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int MAX = 1001;

bool visit[MAX];
vector<int> adj[MAX];
queue<int> Q;

void DFS(int x)
{
	visit[x] = true;
	printf("%d ", x);
	for (int y : adj[x]) {
		if (!visit[y]) {
			DFS(y);
		}
	 }
}

void BFS(int sx)
{
	Q.push(sx);
	visit[sx] = true;
	while (!Q.empty()) {
		int x = Q.front();
		Q.pop();
		printf("%d ", x);
		for (int y : adj[x]) {
			if (!visit[y]) {
				Q.push(y);
				visit[y] = true;
			}
		}
	}
}

int main()
{
	int n, m, v;
	
	//n: 정점의 개수, m:간선의 개수, v:탐색을 시작할 정점의 번호
	scanf("%d %d %d", &n, &m, &v);

	for (int i = 0; i < m; i++) {
		int s, e;
		scanf("%d %d", &s, &e);
		adj[s].push_back(e);
		adj[e].push_back(s);

	}

	for (int i = 1; i <= n; i++) {
		sort(adj[i].begin(), adj[i].end());
	}

	DFS(v);
	puts("");
	memset(visit, 0, sizeof(visit));
	BFS(v);
	puts("");

}