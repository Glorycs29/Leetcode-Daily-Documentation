class Solution {
public:
    int divisorSubstrings(int num, int k) {
        const string s = to_string(num);
        int answer = 0;

        for(int i = 0;i + k <= s.length();i ++) {
            int x = stoi(s.substr(i, k));
            if(x != 0 && num % x == 0)
                answer ++;
        }
        return answer;
    }
};