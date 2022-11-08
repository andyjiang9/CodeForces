#include <bits/stdc++.h>

using namespace std;

int q;
pair<int, pair<int,int>> arr[105];

int main(){
    cin >> q;
    while(q--){
        int n, m;
        cin >> n >> m;
        for(int i = 0; i < n; i++){
           cin >> arr[i].first >> arr[i].second.first >> arr[i].second.second;
        }
        arr[n].first = 0;
        arr[n].second.first = m;
        arr[n].second.second = m;
        sort(arr, arr+n+1);
        bool check = true;
        for(int i = 1; i <= n; i++){
            int time = arr[i].first - arr[i-1].first;
            if(arr[i].second.first >= arr[i-1].second.first && arr[i].second.second <= arr[i-1].second.second)
                continue;
            else if(arr[i].second.first <= arr[i-1].second.first && arr[i].second.second >= arr[i-1].second.second){
                arr[i].second.first = max(arr[i].second.first, arr[i-1].second.first-time);
                arr[i].second.second = min(arr[i].second.second, arr[i-1].second.second+time);
                continue;
            }
            else if(arr[i].second.first < arr[i-1].second.first){
                if(arr[i].second.second + time < arr[i-1].second.first){
                    cout << "NO" << endl;
                    check = false;
                    break;
                }
                arr[i].second.first = max(arr[i].second.first, arr[i-1].second.first-time);
                continue;   
            }
            else if(arr[i].second.second > arr[i-1].second.second){
                if(arr[i].second.first - time > arr[i-1].second.second){
                    cout << "NO" << endl;
                    check = false;
                    break;
                }
                arr[i].second.second = min(arr[i].second.second, arr[i-1].second.second + time);
                continue;
            }

        }
        /*for(int i = 0; i <= n; i++){
            cout << arr[i].first << " " << arr[i].second.first << " " << arr[i].second.second << endl;
        }*/
        if(check){
            cout << "YES" << endl;
        }

        
    }
}