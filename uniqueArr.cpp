/*

Given an array arr[ ] of N elements, your task is to find the minimum number of increment operations required to make all the elements of the array unique. ie- no value in the array should occur more than once. In an operation a value can be incremented by 1 only.

Example 1:

Input:
N = 3
arr[] = {1, 2, 2}
Output:
1
Explanation:
If we increase arr[2] by 1 then the resulting
array becomes {1, 2, 3} and has all unique values.
Hence, the answer is 1 in this case.
Example 2:

Input:
N = 4
arr[] = {1, 1, 2, 3}
Output:
3
Explanation:
If we increase arr[0] by 3, then all array
elements will be unique. Hence, the answer
is 3 in this case.

*/

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

/*
class Solution {
  public:
    long long int minIncrements(vector<int> arr, int N) {
        int ans=0;
        sort(arr.begin(), arr.end());

        for(int i=1; i<N; i++){
            if(arr[i]<=arr[i-1]){
                int dif=arr[i-1]-arr[i];
                ans+=dif+1;
                arr[i]=arr[i-1]+1;

            }
        }
        return ans;
    }
};
*/
class Solution
{
public:
    long long int minIncrements(vector<int> a, int n)
    {
        unordered_map<long long int, long long int> m;
        sort(a.begin(), a.end());
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            m[a[i]]++;
        }
        for (int i = 0; i < n; i++)
        {
            if (m[a[i]] > 1)
            {
                int p = a[i];
                while (m[p] > 0)
                {
                    p++;
                }
                m[a[i]]--;
                m[p]++;
                ans += (p - a[i]);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++)
        {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minIncrements(arr, N) << endl;
    }
}
// } Driver Code Ends