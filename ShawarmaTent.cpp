#include <bits/stdc++.h>

using namespace std;

int n;
pair<int,int> school;
pair<int,int> house[200001];

// direction
// 0 = down
// 1 = right
// 2 = up
// 3 = left
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int directionCount[4];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> school.first >> school.second;
    for(int i = 0; i < n; i++)
        cin >> house[i].first >> house[i].second;

    int sx = school.first;
    int sy = school.second;
    for(int i = 0; i < n; i++) {
        int x = house[i].first;
        int y = house[i].second;

        if(x < sx) {
            directionCount[2]++;
        }
        if(x > sx) {
            directionCount[0]++;
        }
        if(y < sy) {
            directionCount[3]++;
        }
        if(y > sy) {
            directionCount[1]++;
        }
    }
    int bestI = 0;
    int mostH = 0;
    for(int i = 0; i < 4; i++) {
        if(directionCount[i] > mostH) {
            mostH = directionCount[i];
            bestI = i;
        }
    }
    cout << mostH << "\n" << school.first+dx[bestI] << " " << school.second+dy[bestI]; 
}