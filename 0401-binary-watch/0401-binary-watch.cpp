class Solution {
public:
    vector<string> readBinaryWatch(int num) {   // let num be 6
    int mask = 1 << 10;                     // mask = "10000000000
    vector<string>ans;
    for (int i = 0; i < mask; i++)
    {
        if (__builtin_popcount(i) == num)   // counts number of set bits
        {                                   // let i = "101001111"
            int hr = i >> 6;                // hours = "101" = 5
            int mn = (hr << 6)^i;           // hr<<6 ="101000000"  
                                            // xor of i and hr<<6 will give us minutes 
			if (hr < 12 && mn < 60)
            {
                ans.push_back(to_string(hr) + ((mn < 10) ? ":0" : ":") + to_string(mn));
            }
        }
    }
    return ans;

    }
};