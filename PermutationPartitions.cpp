#include <bits/stdc++.h>

using namespace std;

int n, k;
vector<long long> inds;
long long ans = 1;
long long total = 0;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        if(temp > n-k) {
            inds.push_back(i);
            total += temp;
        }
    }

    for(int i = 0; i < (int)inds.size()-1; i++) {
        ans = (ans * (inds[i+1]-inds[i]) % 998244353);
    }

    cout << total << " " << ans;
}