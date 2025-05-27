#include <iostream>
#include <vector>
#include <queue>

using namespace std;


int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    for (int i = 0; i < t; i++)
    {
        int m, n, k; cin >> m >> n >> k;
        vector<vector<int>> field(n, vector<int>(m, 0));
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        queue<pair<int, int>> q;
        int result = 0;

        for (int j = 0; j < k; j++)
        {
            int a, b; cin >> a >> b;
            field[b][a] = 1;
        }

        for (int y = 0; y < n; y++)
        {
            for (int x = 0; x < m; x++)
            {
                if (field[y][x] && !visited[y][x])
                {
                    result++;
                    visited[y][x] = true;
                    q.push({x, y});

                    while (!q.empty())
                    {
                        int x, y;
                        x = q.front().first;
                        y = q.front().second;
                        q.pop();

                        for (int i = 0; i < 4; i++)
                        {
                            int nx, ny;
                            nx = x + dx[i];
                            ny = y + dy[i];

                            if (0 <= nx && nx < m && 0 <= ny && ny < n && visited[ny][nx] == false && field[ny][nx])
                            {
                                visited[ny][nx] = true;
                                q.push({nx, ny});
                            }
                            
                        }
                        
                    }
                    
                }
                
            }
   
        }

        cout << result << "\n";

    }
    

    return 0;
}