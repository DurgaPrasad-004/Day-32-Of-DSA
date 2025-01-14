#include<bits/stdc++.h>
using namespace std;

// count subarrays with sum k with xor
int subarraywithXor(vecto<int> a, int k){
    int n = a.size();
    int cnt = 0;

    // generating subarrays
    for(int i = 0; i < n; i++){
        for(int j  = i; j < n; j++){
            int xorr= 0;
            for(int k = i; k <= j; k++){
                xorr = xorr ^ a[k];
            }
            if(xorr == k) cnt++;
        }
    }
    return cnt;
}

//Time Complexity: O(N3
