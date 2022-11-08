#include <bits/stdc++.h>

using namespace std;

int q;

bool check(long long mid, long long k, long long n, long long a, long long b){
    if(mid <= n && k-(mid*a)-((n-mid)*b) > 0)
        return true;
    return false;
}

int main(){
    cin >> q;
    while(q--){
        long long k, n, a, b;
        cin >> k >> n >> a >> b;
        long long low = 0;
        long long high = 1000000005;
        long long ans = -1;
        while(low <= high){
            long long mid = (high+low)/2;
            if(check(mid, k, n, a, b)){
                ans = mid;
                low = mid+1;
            }else
                high = mid-1;
        }
        cout << ans << endl;
    }
}

/*
Vova is playing a computer game. There are in total n turns in the game and Vova really wants to play all of them. The initial charge of his laptop battery (i.e. the charge before the start of the game) is k.

During each turn Vova can choose what to do:

If the current charge of his laptop battery is strictly greater than a, Vova can just play, and then the charge of his laptop battery will decrease by a;
if the current charge of his laptop battery is strictly greater than b (b<a), Vova can play and charge his laptop, and then the charge of his laptop battery will decrease by b;
if the current charge of his laptop battery is less than or equal to a and b at the same time then Vova cannot do anything and loses the game.
Regardless of Vova's turns the charge of the laptop battery is always decreases.

Vova wants to complete the game (Vova can complete the game if after each of n turns the charge of the laptop battery is strictly greater than 0). Vova has to play exactly n turns. Among all possible ways to complete the game, Vova wants to choose the one where the number of turns when he just plays (first type turn) is the maximum possible. It is possible that Vova cannot complete the game at all.

Your task is to find out the maximum possible number of turns Vova can just play (make the first type turn) or report that Vova cannot complete the game.

You have to answer q independent queries.

Input
The first line of the input contains one integer q (1≤q≤105) — the number of queries. Each query is presented by a single line.

The only line of the query contains four integers k,n,a and b (1≤k,n≤109,1≤b<a≤109) — the initial charge of Vova's laptop battery, the number of turns in the game and values a and b, correspondingly.

Output
For each query print one integer: -1 if Vova cannot complete the game or the maximum number of turns Vova can just play (make the first type turn) otherwise.

Example
inputCopy
6
15 5 3 2
15 5 4 3
15 5 2 1
15 5 5 1
16 7 5 2
20 5 7 3
outputCopy
4
-1
5
2
0
1
*/