#include <bits/stdc++.h>
using namespace std;
int main(){
    int a[]={2,3,4,7,9,1};
   int has[100]={0};
   int n=sizeof(a)/sizeof(int);

   for(int i=0; i<n; i++){
    has[a[i]]=i;
   }

   cout<<has[7];
}
