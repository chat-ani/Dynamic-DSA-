Give two strings, string1 and string2 which are equal except for one character. 
We can either use replace or insert or delete modify string1 so that it becomes equal to string2.

  //Asked in Microsoft
Ex:
  string1="abc"
  string2="abe"
  Here, replace 'c' with 'e' in string1 will make string1 and sting2 equal

  string1="ab"
  string2="abc"
  Here inserting 'c' to string1 will make string1 and string2 equal

  string1="abcd"
  string2="abc"
  Here, deleting 'd' from string1 will make string1 and string2 equal.

Nothing was mentioned about ordering or duplicates.
    
 
My Solution:

#include<bits/stdc++.h>
#define vec vector<int> 
#define td_vec vector<vector<int>> 
using namespace std;

//recursion
/*int fun(string a, string b, int i, int j)
{
    if(i == 0 || j == 0)    return 0;
    if(a[i - 1] == b[j - 1])    return 1 + fun(a, b, i - 1, j -1);
    return max(fun(a, b, i - 1, j), fun(a, b, i, j - 1));
}
*/

//memoization
/*int fun(string a, string b, int i, int j, td_vec dp)
{
    if(i == 0 || j == 0)    return 0;
    if(dp[i][j] != -1)  return dp[i][j];
    if(a[i - 1] == b[j - 1])    return dp[i][j] = 1 + fun(a, b, i - 1, j -1, dp);
    else    return dp[i][j] = max(fun(a, b, i - 1, j, dp), fun(a, b, i, j - 1, dp));
}
*/

//tabulation
/*int fun(string a, string b, int m, int n)
{
    td_vec dp(m + 1, vec(n + 1, 0));
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            if(a[i - 1] == b[j - 1])    dp[i][j] = 1 + dp[i - 1][j - 1];
            else    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[m][n];
}
*/

//space optimization
int fun(string a, string b, int m, int n)
{
    vec prev(n + 1, 0);
    for(int i = 1; i <= m; i++){
        vec curr(n + 1, 0);
        for(int j = 1; j <= n; j++){
            if(a[i - 1] == b[j - 1])    curr[j] = 1 + prev[j - 1];
            else    curr[j] = max(prev[j], curr[j - 1]);
        }
        prev = curr;
    }
    return prev[n];
}

int main()
{
    string a = "abcd", b = "abce";
    int m = a.length();
    int n = b.length();
    /*
    td_vec dp(m + 1, vec(n + 1, -1));
    int length = fun(a, b, m, n, dp);
    */
    int length = fun(a, b, m, n);
    cout << length << endl;
    if((abs(m - length) == 1 && abs(n - length) == 1) || (length + 1 == n && abs(n - length) == 1) || 
            (abs(m - length) == 1 && length + 1 == m))
        cout << "Yes" << endl;
    else    
        cout << "No" << endl;
    return 0;
}


Plz contribute your code and explanation also. That will bw very help full.
And correct me if I am wrong.
  

Thank you :)
