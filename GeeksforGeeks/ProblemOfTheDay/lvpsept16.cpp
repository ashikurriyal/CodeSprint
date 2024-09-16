//Problem Name: Longest valid Parentheses


/* Given a string str consisting of opening and closing parenthesis '(' and ')'. Find length of the longest valid parenthesis substring.

A parenthesis string is valid if:

For every opening parenthesis, there is a closing parenthesis.
Opening parenthesis must be closed in the correct order.
Examples :

Input: str = ((()
Output: 2
Explaination: The longest valid parenthesis substring is "()".
Input: str = )()())
Output: 4
Explaination: The longest valid parenthesis substring is "()()".
Expected Time Complexity: O(|str|)
Expected Auxiliary Space: O(|str|)

Constraints:
1 ≤ |str| ≤ 105   */

#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
  public:
    int maxLength(string s) {
        int sum = 0;
        map<int, int> mp;
        mp[0] = 0;
        int prev = 0, big = 0;
        
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(')
                sum++;
            else
                sum--;
            if (sum < 0) {
                sum = 0;
                prev = i + 1;
                mp[0] = i + 1;
                continue;
            }
            
            if (s[i] == ')' && mp.find(sum) != mp.end()) {
                if (mp[sum] >= prev)
                    big = max(big, i + 1 - mp[sum]);
                else
                    mp[sum] = i + 1;
            } else {
                mp[sum] = i + 1;
            }
        }
        return big;
    }
};

int main() {
    Solution sol;

    // Test cases
    string str1 = "((()";
    string str2 = ")()())";

    cout << "Longest valid parentheses in str1: " << sol.maxLength(str1) << endl;  // Output: 2
    cout << "Longest valid parentheses in str2: " << sol.maxLength(str2) << endl;  // Output: 4

    return 0;
}
