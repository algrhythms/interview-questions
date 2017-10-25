class Solution {
public:
    string countAndSay(int n) {
        if(n < 1)
            return "";
        if(n == 1)
            return "1";
        string current = "1";
        for(int j=2; j <= n; j++)
        {
            char temp;
            int cnt = 0;
            string next = "";
            for(int i=0; i < current.length(); i++)
            {
                if(i && current[i] == temp)
                {
                    cnt++;
                }
                else
                {
                    if(i != 0)
                    {
                        char c = '0'+cnt;
                        next += c;
                        next += temp;
                    }
                    temp = current[i];
                    cnt = 1;
                }
            }
            char c = '0'+cnt;
            next += c;
            next += temp;
            current = next;
        }
        return current;
    }
};
