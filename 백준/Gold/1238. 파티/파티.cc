#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#define INF 98765432

using namespace std;

int n, x, m;
vector<pair<int, int>> v[1002];
int dst[1002];
int result;

void fc(int a, int d){
    memset(dst, INF, sizeof(dst));
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, a});
    dst[a] = 0;
    while (!pq.empty())
    {
        int cx = pq.top().second;
        int cdst = pq.top().first;
        pq.pop();

        if (cx == d)
        {
            result = dst[cx];
            break;
        }
        for (int i = 0; i < v[cx].size(); i++)
        {
            int nx = v[cx][i].first;
            int ndst = v[cx][i].second + cdst;
            if (dst[nx] > ndst)
            {
                dst[nx] = ndst;
                pq.push({ndst, nx});
            }
        } 
    }
    
}

int main()
{
    cin >> n >> m >> x;
    int ans1, ans2, ans;
    ans = 0;
    int a, b, t;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> t;
        v[a].push_back({b, t});
    }
    for (int i = 1; i <= n; i++)
    {
        fc(i, x);
        ans1 = result;
        fc(x, i);
        ans2 = result;
        if (ans < ans1 + ans2)
        {
            ans = ans1 + ans2;
        }
    }

    cout << ans << '\n';
    return 0;
}