#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> adj[26];
bool used[26];
int visited[26];

void dfs(int i, int marker) {
    if(!visited[i]) {
        visited[i] = marker;
        for(int next : adj[i]) {
            dfs(next,marker);
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;
    for(int i = 0; i < n; i++) {
        string temp;
        cin >> temp;
        used[(int)temp[0] - 'a'] = true;
        for(int j = 1; j < (int)temp.size(); j++) {
            adj[(int)temp[j] - 'a'].push_back((int)temp[j-1] - 'a');
            adj[(int)temp[j-1] - 'a'].push_back((int)temp[j] - 'a');
            used[(int)temp[j] - 'a'] = true;
        }
    }

    int marker = 1;
    for(int i = 0; i < 26; i++) {
        if(used[i] && !visited[i]) {
            dfs(i,marker++);
        }
    }

    set<int> ans;
    for(int i = 0; i < 26; i++) {
        if(used[i])
            ans.insert(visited[i]);
    }
    cout << (int)ans.size();
}