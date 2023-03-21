/*
Lamp
Unable to Crack Interviews of Your Dream Companies ? Click Here to End This Problem!

Given an array arr[] of n integers. Check whether it contains a triplet that sums up to zero. 

Example 1:

Input: n = 5, arr[] = {0, -1, 2, -3, 1}
Output: 1
Explanation: 0, -1 and 1 forms a triplet
with sum equal to 0.
Example 2:

Input: n = 3, arr[] = {1, 2, 3}
Output: 0
Explanation: No triplet with zero sum exists. 
*/


//{ Driver Code Starts
#include<bits/stdc++.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

// } Driver Code Ends
/* You are required to complete the function below
*  arr[]: input array
*  n: size of array
*/
class Solution{
  public:
    //Function to find triplets with zero sum.
    bool findTriplets(int a[], int n)
    { 
        sort(a,a+n);
       
//         int i=0,j=n-1;
//         while(i<j){
//             int mid=(i+j)/2;
//             if(A[i]+A[j]+A[mid]==0){
//                 return true;
//             }
//             else if(A[i]+A[j]+A[mid]>0){ ////////////// fail;
//                 j--;
//             }else if(A[i]+A[j]+A[mid]<0){
//                 i++;
//             }
//         }
// return false;

for(int i=0; i<n; i ++){
    int st=i+1;
    int en=n-1;
    
    while(st<en){
        int sum=a[i]+a[st]+a[en];
        if(sum<0){
            st++;
        }
        else if(sum==0){
            return 1;
        }else{
            en--;
        }
    }
}
return 0;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
	cin>>t;
	while(t--){
    	int n;
    	cin>>n;
    	int arr[n]={0};
    	for(int i=0;i<n;i++)
    		cin>>arr[i];
    	Solution obj;
        if(obj.findTriplets(arr, n))
            cout<<"1"<<endl;
        else 
            cout<<"0"<<endl;
	}
    return 0;
}
// } Driver Code Ends