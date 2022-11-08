#include <bits/stdc++.h>

using namespace std;

int n;
int kids[(int)2e5+1];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> kids[i];
    sort(kids,kids+n);
    int s = 0;
    int largestGroup = 1;
    for(int i = 0; i < n; i++) {
        while(s < i && kids[i]-kids[s] > 5) {
            s++;
        }
        if(i-s+1 > largestGroup)
            largestGroup = i-s+1;
    }
    cout << largestGroup;
}