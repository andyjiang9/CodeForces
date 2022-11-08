#include <bits/stdc++.h>

using namespace std;

int n;
string str;
int c[3];
int r[3];
int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> str;

    for(int i = 0; i < n; i++) {
        c[(int)str[i]-48] += 1;
    }

    for(int i = 0; i < 3; i++) {
        r[i] = (n/3) - c[i];
    }
    
    for(int i = 0; i < n; i++) {
        if(r[0] > 0 && str[i] == '2' && r[2] < 0) {
            str[i] = '0';
            r[0]--;
            r[2]++;
        } else if(r[0] > 0 && str[i] == '1' && r[1] < 0) {
            str[i] = '0';
            r[0]--;
            r[1]++;
        } else if(r[1] > 0 && str[i] == '2' && r[2] < 0) {
            str[i] = '1';
            r[1]--;
            r[2]++;
        } 
    }
    for(int i = n-1; i >= 0; i--) {
        if(r[2] > 0 && str[i] == '0' && r[0] < 0) {
            str[i] = '2';
            r[2]--;
            r[0]++;
        }
        else if(r[2] > 0 && str[i] == '1' && r[1] < 0) {
            str[i] = '2';
            r[2]--;
            r[1]++;
        } 
        else if(r[1] > 0 && str[i] == '0' && r[0] < 0) {
            str[i] = '1';
            r[1]--;
            r[0]++;
        } 
    }
    
    cout << str;
}

/*
You are given a string s consisting of exactly n characters, and each character is either '0', '1' or '2'. Such strings are called ternary strings.

Your task is to replace minimum number of characters in this string with other characters to obtain a balanced ternary string (balanced ternary string is a ternary string such that the number of characters '0' in this string is equal to the number of characters '1', and the number of characters '1' (and '0' obviously) is equal to the number of characters '2').

Among all possible balanced ternary strings you have to obtain the lexicographically (alphabetically) smallest.

Note that you can neither remove characters from the string nor add characters to the string. Also note that you can replace the given characters only with characters '0', '1' and '2'.

It is guaranteed that the answer exists.

Input
The first line of the input contains one integer n (3≤n≤3⋅105, n is divisible by 3) — the number of characters in s.

The second line contains the string s consisting of exactly n characters '0', '1' and '2'.

Output
Print one string — the lexicographically (alphabetically) smallest balanced ternary string which can be obtained from the given one with minimum number of replacements.

Because n is divisible by 3 it is obvious that the answer exists. And it is obvious that there is only one possible answer.

Examples
inputCopy
3
121
outputCopy
021
inputCopy
6
000000
outputCopy
001122
inputCopy
6
211200
outputCopy
211200
inputCopy
6
120110
outputCopy
120120
*/