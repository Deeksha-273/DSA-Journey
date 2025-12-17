/*
 * Problem: Complement of Base 10 Integer (LeetCode #1009)
 *
 * Description:
 * The complement of an integer is the number you get when you flip all the 0s to 1s
 * and all the 1s to 0s in its binary representation.
 *
 * Approach: Bit Masking
 * 1. Simple inversion (~n) is dangerous because integers are 32-bit.
 * Example: ~5 (0...00101) becomes (1...11010), which is a huge negative number.
 * 2. We need to ignore the leading 1s created by the inversion.
 * 3. Strategy: Create a "mask" that has 1s only for the length of the number.
 * Example for 5 (101): Mask should be 111 (7).
 * 4. Result = (~n) & mask.
 *
 * Complexity:
 * Time: O(log n) - We iterate through the bits of n.
 * Space: O(1)
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int bitwiseComplement(int n) {
        // Edge Case
        if (n == 0) return 1;

        int m = n;
        int mask = 0;

    
        while (m != 0) {
            mask = (mask << 1) | 1; 
            m = m >> 1;             
        }

        int ans = (~n) & mask;
        return ans;
    }
};

int main() {
    Solution sol;
    int n = 5; 
    
    cout << "Input: " << n << endl;
    cout << "Complement: " << sol.bitwiseComplement(n) << endl; 
    
    return 0;
}