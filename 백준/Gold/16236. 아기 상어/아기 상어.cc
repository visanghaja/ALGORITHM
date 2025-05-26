#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n;
vector<vector<int>> ocean;
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};

struct Shark {
    int x, y, size = 2, eaten = 0;
};

int bfs(Shark& shark) {
    vector<vector<int>> dist(n, vector<int>(n, -1));
    queue<pair<int, int>> q;
    q.push({shark.x, shark.y});
    dist[shark.y][shark.x] = 0;

    vector<tuple<int, int, int>> fishList;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if (dist[ny][nx] != -1) continue;
            if (ocean[ny][nx] > shark.size) continue;

            dist[ny][nx] = dist[y][x] + 1;

            if (ocean[ny][nx] != 0 && ocean[ny][nx] < shark.size) {
                fishList.push_back({dist[ny][nx], ny, nx});
            }

            q.push({nx, ny});
        }
    }

    if (fishList.empty()) return 0;

    sort(fishList.begin(), fishList.end());

    int d, fy, fx;
    tie(d, fy, fx) = fishList[0];

    shark.x = fx;
    shark.y = fy;
    shark.eaten++;
    if (shark.eaten == shark.size) {
        shark.size++;
        shark.eaten = 0;
    }

    ocean[fy][fx] = 0;
    return d;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    ocean.assign(n, vector<int>(n));

    Shark shark;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> ocean[i][j];
            if (ocean[i][j] == 9) {
                shark.x = j;
                shark.y = i;
                ocean[i][j] = 0;
            }
        }
    }

    int totalTime = 0;
    while (true) {
        int time = bfs(shark);
        if (time == 0) break;
        totalTime += time;
    }

    cout << totalTime << "\n";
    return 0;
}
