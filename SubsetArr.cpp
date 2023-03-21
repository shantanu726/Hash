/*
Given two arrays: a1[0..n-1] of size n and a2[0..m-1] of size m. Task is to check whether a2[] is a subset of a1[] or not. Both the arrays can be sorted or unsorted. 
 

Example 1:

Input:
a1[] = {11, 1, 13, 21, 3, 7}
a2[] = {11, 3, 7, 1}
Output:
Yes
Explanation:
a2[] is a subset of a1[]

Example 2:

Input:
a1[] = {1, 2, 3, 4, 5, 6}
a2[] = {1, 2, 4}
Output:
Yes
Explanation:
a2[] is a subset of a1[]

Example 3:

Input:
a1[] = {10, 5, 2, 23, 19}
a2[] = {19, 5, 3}
Output:
No
Explanation:
a2[] is not a subset of a1[]

*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

string isSubset(int a1[], int a2[], int n, int m) ;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;
        int a1[n], a2[m];

        for (int i = 0; i < n; i++) {
            cin >> a1[i];
        }
        for (int i = 0; i < m; i++) {
            cin >> a2[i];
        }

        cout << isSubset(a1, a2, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends


string isSubset(int a1[], int a2[], int n, int m) {
   /*
   
    sort(a1,a1+n);
    sort(a2,a2+m);
    
    int i=0,j=0;
    
    while(i<n && j<m){
        
        if(a1[i]==a2[j]){
            i++;j++;
        }
        //his solution has a time complexity of O(n log n) due to the sorting, 
        //and uses O(1) auxiliary space.
        else if(a1[i]<a2[j]){
            i++;
        }
        else{
            return "No";
        }
    }
    
    return (j==m) ? "Yes":"No";
    */
    
    unordered_map<int,int>mp;
    for(int i=0; i<n; i++){
        mp[a1[i]]++;
    }
    
    for(int i=0; i<m; i++){
        if(mp[a2[i]]==0){
            return"No";
        }
        else{
            mp[a2[i]]--;
        }
       
    }
     return "Yes";
    
}