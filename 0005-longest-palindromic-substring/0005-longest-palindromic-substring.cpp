class Solution {
public:
    string longestPalindrome(string s) {
        int l, h;
        int start = 0, end = 1;

        for (int i = 1; i < s.size(); i++) {
            // even length palindrome
            l = i - 1;
            h = i;
            while (l >= 0 && h < s.size() && s[l] == s[h]) {
                if (h - l + 1 > end) {
                    start = l;
                    end = h - l + 1;
                }
                l--;
                h++;
            }
            // odd length palindrome
            l = i - 1;
            h = i + 1;
            while (l >= 0 && h < s.size() && s[l] == s[h]) {
                if (h - l + 1 > end) {
                    start = l;
                    end = h - l + 1;
                }
                l--;
                h++;
            }
        }
        string ans = "";
        for (int i = start; i < start + end; i++) {
            ans += s[i];
        }
        return ans;
    }
};