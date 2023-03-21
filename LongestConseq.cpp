/*
Given an array of positive integers. Find the length of the longest sub-sequence such that elements in the subsequence are consecutive integers, the consecutive numbers can be in any order.
 

Example 1:

Input:
N = 7
a[] = {2,6,1,9,4,5,3}
Output:
6
Explanation:
The consecutive numbers here
are 1, 2, 3, 4, 5, 6. These 6 
numbers form the longest consecutive
subsquence.
Example 2:

Input:
N = 7
a[] = {1,9,3,10,4,20,2}
Output:
4
Explanation:
1, 2, 3, 4 is the longest
consecutive subsequence.

*/





#include <bits/stdc++.h>
using namespace std;

class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
   int findLongestConseqSubseq(int arr[], int n)
    {
    /*	sort(arr, arr+N);
    	int longest = 0, cur_longest = 1;
    	for(int i = 1; i < N; i++) 
    		if(arr[i] == arr[i - 1]) continue;
    		else if(arr[i] == arr[i - 1] + 1) cur_longest++; // consecutive element - update current streak length
    		else longest = max(longest, cur_longest), cur_longest = 1;  // reset current streak length
    	return max(longest, cur_longest);
    */
    int ans = 0, count = 0;

    // sort the array
    sort(arr, arr + n);

    vector<int> v;
    v.push_back(arr[0]);

    // insert repeated elements only once in the vector
    for (int i = 1; i < n; i++) {
        if (arr[i] != arr[i - 1])
            v.push_back(arr[i]);
    }
    // find the maximum length
    // by traversing the array
    for (int i = 0; i < v.size(); i++) {

        // Check if the current element is equal
        // to previous element +1
        if (i > 0 && v[i] == v[i - 1] + 1)
            count++;
        // reset the count
        else
            count = 1;

        // update the maximum
        ans = max(ans, count);
    }
    return ans;
}
    
};

int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}