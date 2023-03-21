#include <iostream>
#include <vector>
#include <algorithm>
#include<queue>

using namespace std;
int main(){
    int a[]={2,4,1,2,1,4,4,7,1,9,87,6,7};
    int n=sizeof(a)/sizeof(int);
    
    queue<int>q;
    int has[n]={0},k[n],f=0;
    for(int i=0; i<n; i++){
    has[a[i]]++;
    if(has[a[i]]==1){
      // k[f++]=a[i];
      q.push(a[i]);
    }
    }

/*
cout<<f<<"\n";
    for(int i=0; i<f; i++){
        cout<<k[i]<<" ";
    }
*/

while(!q.empty()){
    cout<<q.front()<<" ";
    q.pop();
}
    
}