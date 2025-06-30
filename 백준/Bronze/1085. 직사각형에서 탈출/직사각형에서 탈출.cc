#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int x, y, w, h; cin >> x >> y >> w >> h;

  int minDist = min({x, y, w - x, h - y});

  cout << minDist << "\n";

  return 0;
}