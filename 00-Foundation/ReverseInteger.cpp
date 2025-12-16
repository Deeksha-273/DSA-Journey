/*
 * Problem: Reverse Integer (LeetCode #7)
 * Link: https://leetcode.com/problems/reverse-integer/
 *
 * Approach: Modulo Arithmetic with Overflow Check
 * 1. Extract the last digit using % 10.
 * 2. Append it to the new number using * 10 + digit.
 * 3. CRITICAL: Check for overflow BEFORE multiplying by 10.
 * If ans > INT_MAX / 10, adding another digit will crash.
 *
 * Complexity:
 * Time: O(log(x)) - We process roughly one digit per iteration.
 * Space: O(1)
 */

#include <climits> 

class Solution {
public:
    int reverse(int x) {
        int ans = 0;
        while (x != 0) {
            int digit = x % 10;
    
            if (ans > INT_MAX / 10 || ans < INT_MIN / 10) {
                return 0;
            }
            
            ans = (ans * 10) + digit;
            x = x / 10;
        }
        return ans;
    }
};