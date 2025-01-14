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

// better approach
int subarraysWithXorK(vector<int> a, int k) {
    int n = a.size(); //size of the given array.
    int cnt = 0;

    // Step 1: Generating subarrays:
    for (int i = 0; i < n; i++) {
        int xorr = 0;
        for (int j = i; j < n; j++) {

            //step 2:calculate XOR of all
            // elements:
            xorr = xorr ^ a[j];

            // step 3:check XOR and count:
            if (xorr == k) cnt++;
        }
    }
    return cnt;
}
//Time Complexity: O(N2)

// Optimal approach
int subarraywithXOrk(vector<int> a, int k){
    int n = a.size();
    int xr = 0;
    map<int, int> mpp;
    mpp[xr]++;
    int cnt = 0;

    for(int i = 0; i < n; i++){
        xr = xr ^ a[i];

        // by formulae x = xr ^ k;
        int x = xr ^ k;

        cnt += mpp[x];

        // insert the prefix of xor till index
        mpp[xr]++;
    }
    return cnt;
}
//Time Complexity: O(N) or O(N*logN

int main()
{
    vector<int> a = {4, 2, 2, 6, 4};
    int k = 6;
    int ans = subarraysWithXorK(a, k);
    cout << "The number of subarrays with XOR k is: "
         << ans << "\n";
    return 0;
}

//Merge Overlapping Sub-intervals
// brute force
vector<vector<int>> mergeOverlapping(vector<vector<int>> &arr){
    int n = arr.size();

    // sort the intervals
    sort(arr.begin(), arr.end());

    vector<vector<int>> ans;

    for(int i = 0; i < n; i++){
        int start = arr[i][0];
        int end = arr[i][1];

        // skip all the merged intervals
        if(!ans.empty() && end <= ans.back()[1]){
            continue;
        }

        // check fir the rest of the intervals
        for(int j = i + 1; j < n; j++){
            if(arr[j][0] <= end){
                end = max(end, arr[j][1]);
            }
            else{
                break;
            }
        }
        ans.push_back({stard, end});
    }
    return ans;
}

//Time Complexity: O(N*logN) + O(2*N)

int main()
{
    vector<vector<int>> arr = {{1, 3}, {8, 10}, {2, 6}, {15, 18}};
    vector<vector<int>> ans = mergeOverlappingIntervals(arr);
    cout << "The merged intervals are: " << "\n";
    for (auto it : ans) {
        cout << "[" << it[0] << ", " << it[1] << "] ";
    }
    cout << endl;
    return 0;
}
