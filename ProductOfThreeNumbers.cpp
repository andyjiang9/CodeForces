#include <bits/stdc++.h>

using namespace std;

int t;

vector<int> factor(int n) {
	vector<int> ret;
	for (int i = 2; i * i <= n; i++) {
		while (n % i == 0) {
			ret.push_back(i);
			n /= i;
		}
	}
	if (n > 1) ret.push_back(n);
	return ret;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> factors = factor(n);
        if(factors.size() == 3) {
            cout << "YES\n";
            for(int num : factors) cout << num << " ";
        } else {
            cout << "NO";
        }
        if(t > 0) cout << "\n";
    }
}