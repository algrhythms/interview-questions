#include <iostream>
using namespace std;

bool Solution(string &str1, string &str2)
{
    if(str1 == str2)
        return true;
    int diff = str1.length() - str2.length();
    if(diff)
    {
        if(diff != 1 && diff != -1)
            return false;
        if(str1.length() > str2.length())
        {
            string temp = str1;
            str1 = str2;
            str2 = temp;
        }
        for(int i=0; i < str1.length(); i++)
        {
            if(str1[i] != str2[i])
            {
                if(i && str1 == (str2.substr(0, i) + str2.substr(i+1, str2.length())))
                    return true;
                else if(!i && str1 == str2.substr(1, str2.length()))
                    return true;
                return false;
            }
        }
        return true;
    }
    else
    {
        bool flag = false;
        for(int i=0; i < str1.length(); i++)
        {
            if(str1[i] != str2[i] && !flag)
            {
                flag = true;
            }
            else if(str1[i] != str2[i])
                return false;
        }
        return true;
    }
}

int main()
{
    string str1, str2;
    cout << "Enter two strings" << endl;
    cin >> str1 >> str2;
    if(Solution(str1, str2))
        cout << "True" << endl;
    else
        cout << "False" << endl;
    return 0;
}
