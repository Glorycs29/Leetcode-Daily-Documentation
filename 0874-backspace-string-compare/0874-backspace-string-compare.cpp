class Solution {
public:
    bool backspaceCompare(std::string s, std::string t) {
        std::stack<char> s1;
        std::stack<char> s2;

        for (char ch : s) {
            if (ch == '#') {
                if (!s1.empty()) {
                    s1.pop();
                }
                continue;
            }
            s1.push(ch);
        }

        for (char ch : t) {
            if (ch == '#') {
                if (!s2.empty()) {
                    s2.pop();
                }
                continue;
            }
            s2.push(ch);
        }

        std::string res1 = "";
        std::string res2 = "";

        while (!s1.empty()) {
            res1 += s1.top();
            s1.pop();
        }

        while (!s2.empty()) {
            res2 += s2.top();
            s2.pop();
        }

        return res1 == res2;
    }
};