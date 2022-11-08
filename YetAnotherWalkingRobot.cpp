#include <bits/stdc++.h>

using namespace std;

int q, n;
int dx[4] = {0,0,1,-1};
int dy[4] = {-1,1,0,0};
pair<int,int> currPoint;
map<char,int> movement;

void m(char temp) {
    currPoint.first += dx[movement[temp]];
    currPoint.second += dy[movement[temp]];
}


int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> q;
    
    movement['L'] = 0;
    movement['R'] = 1;
    movement['D'] = 2;
    movement['U'] = 3;
    while(q--) {
        cin >> n;
        
        map<pair<int,int>,int> grid;

        int minDist = INT_MAX;
        pair<int,int> minGap = {-1,-1};

        char temp;
        currPoint = {0,0};
        grid[currPoint] = 1;
        for(int i = 2; i <= n+1; i++) {
            cin >> temp;
            m(temp);
            if(grid[currPoint] != 0) {
                if(i - grid[currPoint] < minDist) {
                    minDist = i - grid[currPoint];
                    minGap.first = grid[currPoint];
                    minGap.second = i-1;
                }
                
            } 
            grid[currPoint] = i;
        }
        if(minDist != INT_MAX) {
            cout << minGap.first << " " << minGap.second << "\n";
        } else {
            cout << -1 << "\n";
        }
        
    }
}