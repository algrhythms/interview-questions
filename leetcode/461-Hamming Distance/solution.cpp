class Solution {
public:
    string toBinary(int a)
    {
        string str="";
        while(a >= 2)
        {
            int r = a % 2;
            str += ('0' + r);
            a /= 2;
        }
        str += ('0' + a);
        for(int i=0; i < str.length()/2; i++)
        {
            char c = str[i];
            str[i] = str[str.length()-1-i];
            str[str.length()-1-i] = c;
        }
        return str;
    }
    
    int hammingDistance(int x, int y) {
        string str1, str2;
        str1 = toBinary(x);
        str2 = toBinary(y);
        while(str1.length() > str2.length())
            str2 = '0' + str2;
        while(str2.length() > str1.length())
            str1 = '0' + str1;
        int cnt=0;
        for(int i=0; i < str1.length(); i++)
            if(str1[i] != str2[i])
                cnt++;
        return cnt;
    }
};
