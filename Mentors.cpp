#include <bits/stdc++.h>

#define ll long long;

using namespace std;

int n, k;
int skills[(int)2e5+1];
int p[(int)2e5+1];
int c[(int)2e5+1];

bool cmp(int a, int b) {
    return skills[a] < skills[b];
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> skills[i];
        p[i] = i;
    }
    sort(p,p+n,cmp);
    for(int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;

        if(skills[a] > skills[b]) {
            c[a]--;
        } else if(skills[a] < skills[b]) {
            c[b]--;
        }
            
    }

    int numSmaller = 0;
    for(int i = 1; i < n; i++) {
        if(skills[p[i]] == skills[p[i-1]]) {
            c[p[i]] += numSmaller;
        } else {
            numSmaller = i;
            c[p[i]] += numSmaller;
        }
        
    }
    
    for(int i = 0; i < n; i++) {
        cout << c[i]  << " ";
    }
}

/*
In BerSoft n programmers work, the programmer i is characterized by a skill ri.

A programmer a can be a mentor of a programmer b if and only if the skill of the programmer a is strictly greater than the skill of the programmer b (ra>rb) and programmers a and b are not in a quarrel.

You are given the skills of each programmers and a list of k pairs of the programmers, which are in a quarrel (pairs are unordered). For each programmer i, find the number of programmers, for which the programmer i can be a mentor.

Input
The first line contains two integers n and k (2≤n≤2⋅105, 0≤k≤min(2⋅105,n⋅(n−1)2)) — total number of programmers and number of pairs of programmers which are in a quarrel.

The second line contains a sequence of integers r1,r2,…,rn (1≤ri≤109), where ri equals to the skill of the i-th programmer.

Each of the following k lines contains two distinct integers x, y (1≤x,y≤n, x≠y) — pair of programmers in a quarrel. The pairs are unordered, it means that if x is in a quarrel with y then y is in a quarrel with x. Guaranteed, that for each pair (x,y) there are no other pairs (x,y) and (y,x) in the input.

Output
Print n integers, the i-th number should be equal to the number of programmers, for which the i-th programmer can be a mentor. Programmers are numbered in the same order that their skills are given in the input.

Examples
inputCopy
4 2
10 4 10 15
1 2
4 3
outputCopy
0 0 1 2 
inputCopy
10 4
5 4 1 5 4 3 7 1 2 5
4 6
2 1
10 8
3 5
outputCopy
5 4 0 5 3 3 9 0 2 5 
Note
In the first example, the first programmer can not be mentor of any other (because only the second programmer has a skill, lower than first programmer skill, but they are in a quarrel). The second programmer can not be mentor of any other programmer, because his skill is minimal among others. The third programmer can be a mentor of the second programmer. The fourth programmer can be a mentor of the first and of the second programmers. He can not be a mentor of the third programmer, because they are in a quarrel.
*/