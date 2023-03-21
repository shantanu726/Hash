/*
Given an array of integers and a number k, write a function that returns true if given array can be divided into pairs such that sum of every pair is divisible by k.
 

Example 1 :

Input : arr = [9, 5, 7, 3], k = 6
Output: True
Explanation: {(9, 3), (5, 7)} is a 
possible solution. 9 + 3 = 12 is divisible
by 6 and 7 + 5 = 12 is also divisible by 6.

Example 2:

Input : arr = [2, 4, 1, 3], k = 4
Output: False
Explanation: There is no possible solution.
*/


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
        // Code here.
        if(nums.size()%2)
        {
            return false;
        }
        
        int arr[k] = {0};
        
        for(int i = 0; i < nums.size(); i++)
        {
            arr[nums[i]%k]++;
        }
        
        // for(int i = 0; i < k; i++)
        // {
        //     cout<<arr[i]<<" ";
        // }
        
        if(arr[0]%2 || arr[k/2]%2 )
        {
            return false;
        }
        
        for(int i = 1; i < k/2; i++)
        {
            if((arr[i] != arr[k-i]))
            {
                return false;
            }
        }
        
        return true;
    }
};



//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}
// } Driver Code Ends