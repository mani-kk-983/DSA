class Solution {
public:
    bool isPalindrome(int x) {
        //converting the intger into string and traversing the string from 0 to n/2 for palindrome 
        // we use 2 ptr mirror indexing technnique for checking purpose 
       string S = to_string(x);
       int n = S.length();
       for (int i=0; i<n/2; i++ )
       {
        if(S[i]!= S[n-i-1])
        return false;
       }
    return true;
    }
};