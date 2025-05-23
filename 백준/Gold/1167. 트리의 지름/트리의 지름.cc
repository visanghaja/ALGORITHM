#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

struct Node
{
    int index;
    int dist;
};

vector<Node> tree[1000001];
bool visited[1000001];
int maxDist, maxNode;

void DFS(int node, int dist){
    if (visited[node])
    {
        return;
    }
    if (maxDist < dist)
    {
        maxDist = dist;
        maxNode = node;
    }
    visited[node] = true;
    for (int i = 0; i < tree[node].size(); i++)
    {
        int nextInd = tree[node][i].index;
        int nextDist = tree[node][i].dist;
        DFS(nextInd, dist + nextDist);
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int v; cin >> v;
    for (int i = 1; i < v + 1; i++)
    {
        int v_n; cin >> v_n;
        while (true)
        {
            int link_v; int d; cin >> link_v;
            if (link_v == -1)
            {
                break;
            }
            cin >> d;
            tree[v_n].push_back({link_v, d});
            tree[link_v].push_back({v_n, d});
        }
    }

    DFS(1, 0);
    memset(visited, 0, sizeof(visited)); // visited 0으로 초기화
    DFS(maxNode, 0);

    cout << maxDist;

    return 0;
}