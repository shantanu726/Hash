/*
Given two unsorted arrays A of size N and B of size M of distinct elements, the task is to find all pairs from both arrays whose sum is equal to X.

Note: All pairs should be printed in increasing order of u. For eg. for two pairs (u1,v1) and (u2,v2), if u1 < u2 then
(u1,v1) should be printed first else second.

Example 1:

Input:
A[] = {1, 2, 4, 5, 7}
B[] = {5, 6, 3, 4, 8} 
X = 9 
Output: 
1 8
4 5 
5 4
Explanation:
(1, 8), (4, 5), (5, 4) are the
pairs which sum to 9.
Example 2:
Input:
A[] = {-1, -2, 4, -6, 5, 7}
B[] = {6, 3, 4, 0} 
X = 8 
Output:
4 4 
5 3
*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    
    
    bool binary(int A[],int l,int h,int k)
    {
       
       while(l<=h)
       {
           int mid =l+(h-l)/2;
           if(A[mid]==k) return 1;
           
           else if(A[mid]>k)
            h=mid-1;
           
           else l=mid+1;
       }
       
       return 0;
    }
    vector<pair<int,int>> allPairs(int A[], int B[], int N, int M, int X)
    {
       /* vector<pair<int,int>>p;
        set<int>s;
        for(int i=0; i<M; i++){
            s.insert(B[i]);
        }
        
        for(int j=0; j<N; j++){
            int df=X-A[j];
            if(s.find(df)!=s.end()){
                p.push_back({A[j],df});
            }
        }
        sort(p.begin(),p.end());
        
        return p;
        */
        
           sort(A,A+N);
        sort(B,B+M);
        
        vector<pair<int,int>> v;
        
        for(int i=0;i<N;i++)
        {
            
            if(binary(B,0,M-1,X-A[i]))
               {
                                     

              v.push_back(make_pair(A[i],X-A[i]));
                   
                 
               }
            
        }
        
        return v;
        
    }
};




//{ Driver Code Starts.
int main() {
	long long t;
	cin >> t;
	
	while(t--){
	    int N, M, X;
	    cin >> N >> M >> X;
        int A[N], B[M];
        
	    for(int i = 0;i<N;i++)
	        cin >> A[i];
	    for(int i = 0;i<M;i++)
	        cin >> B[i];
	        
	   Solution ob;
	   vector<pair<int,int>> vp = ob.allPairs(A, B, N, M, X);
	   int sz = vp.size();
        if(sz==0)
        cout<<-1<<endl;
        else{
            for(int i=0;i<sz;i++){
                if(i==0)
                cout<<vp[i].first<<" "<<vp[i].second;
                else
                cout<<", "<<vp[i].first<<" "<<vp[i].second;
            }
            cout<<endl;
        }
	}
	return 0;
}
// } Driver Code Ends