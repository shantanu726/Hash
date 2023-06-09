/*
Given a sequence of strings, the task is to find out the second most repeated (or frequent) string in the given sequence.

Note: No two strings are the second most repeated, there will be always a single string.

Example 1:

Input:
N = 6
arr[] = {aaa, bbb, ccc, bbb, aaa, aaa}
Output: bbb
Explanation: "bbb" is the second most
occurring string with frequency 2.

â€‹Example 2:

Input:
N = 6
arr[] = {geek, for, geek, for, geek, aaa}
Output: for
Explanation: "for" is the second most
occurring string with frequency 2.

*/












#include <bits/stdc++.h>
using namespace std;

// class Solution
// {
//   public:
//     string secFrequent (string arr[], int n)
//     {
//         //code here.
//     }
// };

class Solution
{
public:
    string secFrequent(string arr[], int n)
    {
        unordered_map<string, int> m;

        for (int i = 0; i < n; ++i)
            m[arr[i]]++;

        // first and second most occurred strings
        int mx1 = INT_MIN, mx2 = INT_MIN;

        for (auto i : m)
        {
            // we got a new mx1
            // hence, current mx1 is stored in mx2

            if (i.second > mx1)
            {
                mx2 = mx1;
                mx1 = i.second;
            }

            // we got a new mx2
            else if (i.second > mx2 and i.second != mx1)
            {
                mx2 = i.second;
            }

            for (auto i : m)
                if (i.second == mx2)
                    return i.first;

            return "";
        }
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        Solution ob;
        cout << ob.secFrequent(arr, n) << endl;
    }
}