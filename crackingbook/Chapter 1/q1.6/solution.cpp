#include <iostream>
using namespace std;

string toString(int x)
{
    if(x == 0)
        return "0";
    string result="";
    while(x)
    {
        int k = x % 10;
        result += '0' + k;
        x /= 10;
    }
    for(int i=0; i < result.length()/2; i++)
    {
        char c = result[i];
        result[i] = result[result.length()-1-i];
        result[result.length()-1-i] = c;
    }
    return result;
}

string Solution(string &str)
{
    if(str.length() < 3)
        return str;
    string result = "";
    char current = str[0];
    int cnt = 1;
    for(int i=1; i < str.length(); i++)
    {
        if(current != str[i])
        {
            result += current;
            result += toString(cnt);
            current = str[i];
            cnt = 1;
        }
        else
        {
            cnt++;
        }
    }
    result += current;
    result += toString(cnt);
    if(result.length() >= str.length())
        result = str;
    return result;
}

int main()
{
    string str;
    cout << "enter a string to compress" << endl;
    cin >> str;
    cout << Solution(str) << endl;
    return 0;
}
