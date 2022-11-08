#include <bits/stdc++.h>

using namespace std;

int n, m;
pair<int,int> pairs[(int)3e5+1];
vector<int> adj[(int)3e5+1];

bool secondLayer(int y, int ind, bool Gvisited[]) {
    bool visited[(int)3e5+1];
    for(int i = 0; i < m; i++) {
        visited[i] = Gvisited[i];
    }

    visited[ind] = true;
    
    for(int neighbor : adj[y]) {
        visited[neighbor] = true;
    }

    for(int i = 0; i < m; i++) {
        if(visited[i] == false) {
            return false;
        }
    }
    
    return true;
}

bool firstLayer(int x) {
    bool visited[(int)3e5+1];
    memset(visited,0,sizeof(visited-(sizeof(visited)-m)));
    visited[0] = true;
    
    for(int neighbor : adj[x]) {
        visited[neighbor] = true;
        
    }
    
    int y1, y2;
    for(int i = 0; i < m; i++) {
        if(visited[i] == false) {
            y1 = pairs[i].first;
            y2 = pairs[i].second;
                    
            return secondLayer(y1, i, visited) || secondLayer(y2, i, visited);
            break;
        }
    }
    

    return true;
}   

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        cin >> pairs[i].first >> pairs[i].second;
        adj[pairs[i].first].push_back(i);
        adj[pairs[i].second].push_back(i);
    }

    if(firstLayer(pairs[0].first) || firstLayer(pairs[0].second)) {
        
        cout << "YES";
    } else {
        cout << "NO";
    }


}

/*
Toad Ivan has m pairs of integers, each integer is between 1 and n, inclusive. The pairs are (a1,b1),(a2,b2),…,(am,bm).

He asks you to check if there exist two integers x and y (1≤x<y≤n) such that in each given pair at least one integer is equal to x or y.

Input
The first line contains two space-separated integers n and m (2≤n≤300000, 1≤m≤300000) — the upper bound on the values of integers in the pairs, and the number of given pairs.

The next m lines contain two integers each, the i-th of them contains two space-separated integers ai and bi (1≤ai,bi≤n,ai≠bi) — the integers in the i-th pair.

Output
Output "YES" if there exist two integers x and y (1≤x<y≤n) such that in each given pair at least one integer is equal to x or y. Otherwise, print "NO". You can print each letter in any case (upper or lower).

Examples
inputCopy
4 6
1 2
1 3
1 4
2 3
2 4
3 4
outputCopy
NO
inputCopy
5 4
1 2
2 3
3 4
4 5
outputCopy
YES
inputCopy
300000 5
1 2
1 2
1 2
1 2
1 2
outputCopy
YES
Note
In the first example, you can't choose any x, y because for each such pair you can find a given pair where both numbers are different from chosen integers.

In the second example, you can choose x=2 and y=4.

In the third example, you can choose x=1 and y=2.
*/