#include <iostream>
#include <vector>
#include <queue>

using namespace std;

queue<int> q;
int ans = 0;

int main()
{
    int n, m; cin >> n >> m;

    vector<int> g[n + 1];
    vector<bool> check(n + 1, false);  
    
    for (int i = 0; i < m; i++)
    {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for (int i = 1; i <= n; i++)  
    {
        if (!check[i])
        {
            q.push(i);
            check[i] = true;
            while (!q.empty())
            {
                int temp = q.front();
                q.pop();

                for (int j = 0; j < g[temp].size(); j++)
                {
                    int nxt = g[temp][j];
                    if (!check[nxt])
                    {
                        q.push(nxt);
                        check[nxt] = true;
                    }
                } 
            }
            ans++;
        }
    }

    cout << ans;
    return 0;
}
