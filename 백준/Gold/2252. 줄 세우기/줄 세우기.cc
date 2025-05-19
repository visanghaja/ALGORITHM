// 위상정렬 (queue)

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> result;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> student(n + 1, 0);
    queue<int> q;
    vector<vector<int>> g(n + 1);
    
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        student[b]++;
        g[a].push_back(b);
    }

    for (int i = 0; i <= n; i++)
    {
        if (student[i] == 0)
        {
            q.push(i);
        }
        
    }

    while (!q.empty())
    {
        int ind = q.front();
        result.push_back(ind);
        q.pop();
        for (int nxt : g[ind]){
            if (--student[nxt] == 0)
            {
                q.push(nxt);
            }
            
        }
        
    }

    for (int i = 1; i < result.size(); ++i) {
        cout << result[i];
        if (i + 1 != result.size()) cout << ' ';
    }

    return 0;
}