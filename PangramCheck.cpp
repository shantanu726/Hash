/*

Given a string check if it is Pangram or not. A pangram is a sentence containing every letter in the English Alphabet (either lowercase or uppercase or both). For example, we say the letter A is present in the string if either 'a' is present or 'A' is present.

Example 1:

Input:
S = Bawds jog, flick quartz, vex nymph
Output: 1
Explanation: In the given input, there
are all the letters of the English
alphabet. Hence, the output is 1.
Example 2:

Input:
S = sdfs
Output: 0
Explanation: In the given input, there
aren't all the letters present in the
English alphabet. Hence, the output
is 0.

*/

//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    //Function to check if a string is Pangram or not.
    bool checkPangram (string &str) {
        
        
        int n=str.length();
        if(n<26) return false;
        
        int con[26]={0};
        int s=0;
        for(int i=0; i<n; i++){
            con[tolower(str[i])-'a']++;
        }
        
        for(int i=0; i<26; i++){
            if(con[i]==0) return false;
        }
        
        return true;
        
    }

};

//{ Driver Code Starts.

// Driver Program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--){
        string str;
        getline(cin, str);
        Solution obj;
        if (obj.checkPangram(str) == true)
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }
    return(0);
}

// } Driver Code Ends