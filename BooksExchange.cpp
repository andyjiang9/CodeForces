#include <bits/stdc++.h>

using namespace std;

int q;
int head[(int)2e5+1];
int numH[(int)2e5+1];
int kids[(int)2e5+1];
bool visited[(int)2e5+1];

void dfs(int pos, int marker) {
    if(pos == marker) return;
    head[pos] = marker;
    visited[pos] = true;
    numH[marker]++;
    dfs(kids[pos],marker);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> q;
    while(q--) {
        int n;
        cin >> n;
        for(int i = 0; i < n; i++) visited[i] = 0;
        for(int i = 0; i < n; i++) head[i] = 0;
        for(int i = 0; i < n; i++) numH[i] = 0;
        for(int i = 0; i < n; i++) {
            cin >> kids[i];
            kids[i]--;
        }

        for(int i = 0; i < n; i++) {
            if(visited[i] == false) {
                numH[i]++;
                visited[i] = true;
                head[i] = i;

                dfs(kids[i],i);
            }
        }

        for(int i = 0; i < n; i++) {
            cout << numH[head[i]] << " ";
        }
        cout << "\n";
    }
}