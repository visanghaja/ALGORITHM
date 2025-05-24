#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int idx;     
    int dist;     
};

const int INF = 1'000'000'000;  
vector<vector<Node>> graph;      
vector<int> D;                  
vector<Node> heap;              
vector<char> visited;            


void HeapInsert(Node n) {
    heap.push_back(n);
    int i = (int)heap.size() - 1;
    while (i > 0) {
        int p = (i - 1) / 2;
        if (heap[p].dist <= heap[i].dist) break;
        swap(heap[p], heap[i]);
        i = p;
    }
}

Node HeapPop() {                 
    Node top = heap.front();
    heap[0] = heap.back();
    heap.pop_back();
    int n = (int)heap.size(), i = 0;
    while (true) {
        int l = 2 * i + 1, r = 2 * i + 2;
        if (l >= n) break;
        int c = (r < n && heap[r].dist < heap[l].dist) ? r : l;
        if (heap[i].dist <= heap[c].dist) break;
        swap(heap[i], heap[c]);
        i = c;
    }
    return top;
}

void Dijkstra(int start) {
    HeapInsert({start, 0});
    while (!heap.empty()) {
        Node cur = HeapPop();
        int u = cur.idx;
        if (visited[u]) continue; 
        visited[u] = 1;

        for (auto [v, w] : graph[u]) {
            if (D[v] > D[u] + w) {
                D[v] = D[u] + w;
                HeapInsert({v, D[v]});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int V, E; cin >> V >> E;
    int K; cin >> K;

    graph.assign(V + 1, {});
    D.assign(V + 1, INF);
    visited.assign(V + 1, 0);
    heap.reserve(E + 1);

    for (int i = 0; i < E; ++i) {
        int u, v, w;    cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }

    D[K] = 0;
    Dijkstra(K);

    for (int i = 1; i <= V; ++i) {
        if (D[i] == INF)  cout << "INF\n";
        else              cout << D[i] << '\n';
    }
    return 0;
}
