#include <iostream>
using namespace std;

bool isSubstring(string &s1, string &s2)
{
    if(s1.length() != s2.length() || s1 == "" || s2 == "")
        return false;
    s2 += s2;
    int index = s2.find(s1);
    if(index != -1)
        return true;
    else
        return false;
}

int main()
{
    cout << "enter two strings" << endl;
    string s1, s2;
    cin >> s1 >> s2;
    if(isSubstring(s1, s2))
        cout << "True" << endl;
    else
        cout << "False" << endl;
    return 0;
}
