string toString(int x)
{
    string str="";
    if(x == 0)
        return "0";
    bool flag=false;
    if(x < 0)
    {
        flag = true;
        x *= -1;
    }
    
    while(x)
    {
        str += ('0' + (x % 10));
        x /= 10;
    }
    //cout << "str " << str << endl;
    if(flag)
        str += "-";
    for(int i=0; i < str.length()/2; i++)
    {
        char c=str[i];
        str[i] = str[str.length()-1-i];
        str[str.length()-1-i] = c;
    }
    //cout << "String " << str << endl;
    return str;
}

int Solution::evalRPN(vector<string> &A) {
    vector<string> stack;
    for(int i=0; i < A.size(); i++)
    {
        if(A[i] == "+" || A[i] == "-" || A[i] == "*" || A[i] == "/")
        {
            int y = atoi(stack.back().c_str());
            stack.pop_back();
            int x = atoi(stack.back().c_str());
            stack.pop_back();
            //cout << x << " " << y << endl;
            if(A[i] == "+")
                x += y;
            else if(A[i] == "-")
                x -= y;
            else if(A[i] == "/")
                x /= y;
            else if(A[i] == "*")
                x *= y;
            //cout << x << endl;
            stack.push_back(toString(x));
        }
        else
        {
            stack.push_back(A[i]);
        }
    }
    return atoi(stack[0].c_str());
}
