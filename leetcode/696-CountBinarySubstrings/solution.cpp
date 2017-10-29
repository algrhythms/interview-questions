class Solution {
public:
    int countBinarySubstrings(string s) {
        if(s.length() < 2)
            return 0;
        int cnt=0;
        int prev = 0;
        int current = 1;
        for(int i=1; i < s.length(); i++)
        {
            if(s[i-1] == s[i])
                current++;
            else
            {
                prev = current;
                current = 1;
            }
            if(prev >= current)
                cnt++;
        }
        return cnt;
        
    }
};
