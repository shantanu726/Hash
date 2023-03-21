/*
There are N jobs and the start and finish time of the jobs are given in arrays start[] and end[] respectively. Each job requires one laptop and laptops can't be shared. Find the minimum number of laptops required given that you can give your laptop to someone else when you are not doing your job.


Example 1:

Input:
N = 3
start[] = {1, 2, 3}
end[] = {4, 4, 6}
Output:
3
Explanation:
We can clearly see that everyone's supposed to
be doing their job at time 3. So, 3 laptops
will be required at minimum.
Example 2:

Input:
N = 3
start[] = {1, 5, 2}
end[] = {2, 6, 3}
Output :
1
Explanation:
All jobs can be done using 1 laptop only.




Implementation:
Steps:

Step 1: We will declare a hash map where we will mark the start and end times of using the laptop.

Step 2: Iterate through the start and end array in a same loop. We will increment the hash value of start[i] by 1 and decrement the hash value of end[i] by 1 as we are trying to store the current number of laptops which are in use.

Step 3: We have to use a hash map data structure which always remains sorted.

Step 4: We will keep a variable named, "maxx" which is used to maintain the maximum number of laptops that we need at a particular moment.

Step 5: Iterate through the hash map where you have marked the starting point as +1 and ending point as -1. Keep a variable named, cnt which indicates the number of laptops which are in use currently.

Step 6: In each iteration add the hash map value to cnt and compare it with maxx.

Complexity:
Time Complexity:  O(N*logN), N is for iteration in the array and extra logN is to maintain the hash map.
Space complexity: O(N) as we are maintaining an extra hash map.

*/


#include <bits/stdc++.h>
using namespace std;

/*
class Solution {
  public:
    int minLaptops(int N, int start[], int end[]) {
       sort(start,start+N);
       sort(end,end+N);

      int c=1,j=0;

      for(int i=1;i<N;i++){

          if(start[i]<end[j]){
              c++;
          }else{
              j++;
          }
      }


      return c;
    }
};
*/

class Solution
{
public:
    int minLaptops(int N, int start[], int end[])
    {
        map<int, int> mp;

        for (int i = 0; i < N; i++)
        {
            mp[start[i]] += 1;
            mp[end[i]] -= 1;
        }

        vector<pair<int, int>> s;

        for (auto it : mp)
            s.push_back(it);
        sort(s.begin(), s.end());

        int c = 0, ans = 0;

        for (pair<int, int> i : s)
        {
            c += i.second;
            ans = max(ans, c);
        }
        return ans;
    }
};


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        int start[N], end[N];
        for (int i = 0; i < N; i++)
            cin >> start[i];
        for (int i = 0; i < N; i++)
            cin >> end[i];

        Solution ob;
        cout << ob.minLaptops(N, start, end) << endl;
    }
}