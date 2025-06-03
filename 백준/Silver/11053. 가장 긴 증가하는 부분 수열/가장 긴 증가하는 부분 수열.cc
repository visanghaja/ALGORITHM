#include <iostream>
#include <vector>
using namespace std;

vector<int> s;
vector<int> a;

void binary(int nxt, vector<int>& a) {
    int start = 0;
    int end = a.size();
    while (start < end) {
        int mid = (start + end) / 2;
        if (a[mid] < nxt)
            start = mid + 1;
        else
            end = mid;
    }
    a[start] = nxt;
}

int main() {
    int n; cin >> n;
    s.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    a.push_back(s[0]);

    for (int i = 1; i < n; i++) {
        if (s[i] > a.back()) {
            a.push_back(s[i]);
        } else {
            binary(s[i], a);  
        }
    }

    cout << a.size();  
    return 0;
}