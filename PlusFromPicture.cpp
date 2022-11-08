#include <bits/stdc++.h>
#define ll long long
using namespace std;

//ifstream fin(".in");
//ofstream fout(".out");

int h, w;
string inpString;
char grid[505][505];
bool visited[505][505];
int ans = 0;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

void bfs(int i, int j) {
    vector<pair<int,int>> q;
    q.push_back({i,j});
    visited[i][j] = true;

    while(!q.empty()) {
        vector<pair<int,int>> temp;
        
        for(pair<int,int> node : q) {

            for(int i = 0; i < 4; i++) {
                int nX = node.first + dx[i];
                int nY = node.second + dy[i];

                if(grid[nX][nY] == '*' && !visited[nX][nY]) {
                    temp.push_back({nX,nY});
                    visited[nX][nY] = true;

                }
            }
        }
        q = temp;
    }
}

bool dfs(int i, int j) {
    // 0 = down
    // 1 = right
    // 2 = up
    // 3 = left
    memset(visited,0,sizeof(visited));
    visited[i][j] = true;

    vector<pair<int,int>> q;
    
    for(int dir = 0; dir < 4; dir++) {
        q.push_back({i+dx[dir],j+dy[dir]});
        visited[i+dx[dir]][j+dy[dir]] = true;
        while(!q.empty()) {
            vector<pair<int,int>> temp;
            
            for(pair<int,int> node : q) {

                for(int i = 0; i < 4; i++) {
                    int nX = node.first + dx[i];
                    int nY = node.second + dy[i];

                    if(grid[nX][nY] == '*' && !visited[nX][nY]) {
                        if(dir != i)
                            return false;
                        temp.push_back({nX,nY});
                        visited[nX][nY] = true;
                    }
                }
            }
            q = temp;
        }
    }
    return true;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    // takes in the input
    cin >> h >> w;
    pair<int,int> randomPoint;
    for(int i = 0; i <= h; i++) {
        getline(cin,inpString);
        for(int j = 1; j <= w; j++) {
            grid[i][j] = inpString[j-1];
            if(grid[i][j] == '*') {
                randomPoint.first = i;
                randomPoint.second = j;
            }
        }
    }

    // checks if everything is in one part
    bfs(randomPoint.first,randomPoint.second);
    //for(int i = 1; i <= h; i++) {for(int j = 1; j <= w; j++) cout << grid[i][j]; cout << "\n";}
    for(int i = 1; i <= h; i++) {
        for(int j = 1; j <= w; j++) {
            if(grid[i][j] == '*' && visited[i][j] == false) {
                cout << "NO";
                return 0;
            }
        }
    }

    // checks all the directions
    for(int i = 1; i <= h; i++) {
        for(int j = 1; j <= w; j++) {
            if(grid[i][j] == '*' && grid[i+1][j] == '*' && grid[i-1][j] == '*' && grid[i][j+1] == '*' && grid[i][j-1] == '*') {
                if(!dfs(i,j)) {
                    cout << "NO";
                    return 0;
                } else {
                    ans++;
                }

            } 
        }
    }

    if(ans == 1)
        cout << "YES";
    else   
        cout << "NO";
}