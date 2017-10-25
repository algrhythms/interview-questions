#include <iostream>
#include <vector>
using namespace std;

void Solution(vector<vector<int> > &matrix)
{
    if(matrix.size() < 2)
        return;
    int start = 0, end = matrix.size()-1;
    for(int i=0; i < matrix.size()/2; i++)
    {
        for(int j=start; j < end; j++)
        {
            int x = matrix[i][j];
            int a=i, b=j;
            for(int k=0; k < 4; k++)
            {
                int y = matrix[b][matrix.size()-1-a];
                matrix[b][matrix.size()-1-a] = x;
                int t1 = b;
                int t2 = matrix.size()-1-a;
                a = t1;
                b = t2;
                x = y;
                
            }
        }
        start++;
        end--;
    }
}

int main()
{
    cout << "enter N of NxN matrix to be rotated 90 degree" << endl;
    int N;
    cin >> N;
    cout << "enter NxN matrix" << endl;
    vector<vector<int> > matrix;
    for(int i=0; i < N; i++)
    {
        vector<int> v;
        for(int j=0; j < N; j++)
        {
            int x;
            cin >> x;
            v.push_back(x);
        }
        matrix.push_back(v);
    }
    Solution(matrix);
    for(int i=0; i < N; i++)
    {
        for(int j=0; j < N; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
    return 0;
}
