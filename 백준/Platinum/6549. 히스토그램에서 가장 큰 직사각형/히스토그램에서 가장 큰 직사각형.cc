#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;
using ll = long long;

ll largestRect(const vector<ll>& h);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<ll> result;
    while (true) {
        int n; 
        cin >> n;
        if(n == 0) {break;}
        vector<ll> h(n);
        for (int i = 0; i < n; ++i) cin >> h[i];
        result.push_back(largestRect(h));
    }
    for(ll n : result){
        cout << n << "\n";
    }
    return 0;
}

ll largestRect(const vector<ll>& h) {
    vector<ll> a(h);
    a.push_back(0); 
    stack<int> st;
    ll best = 0;

    for (int i = 0; i < (int)a.size(); ++i) {
        while (!st.empty() && a[st.top()] > a[i]) {
            ll height = a[st.top()];  st.pop();
            int left = st.empty() ? -1 : st.top();
            ll width = i - left - 1;
            best = max(best, height * width);
        }
        st.push(i);
    }
    return best;
}