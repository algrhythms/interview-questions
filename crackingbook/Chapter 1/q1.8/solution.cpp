#include <iostream>
#include <set>
#include <vector>
using namespace std;

void Solution(vector<vector<int> > &matrix)
{
    set<int> rows, columns;
    for(int i=0; i < matrix.size(); i++)
    {
        for(int j=0; j < matrix[i].size(); j++)
        {
            if(!matrix[i][j])
            {
                rows.insert(i);
                columns.insert(j);
            }
        }
    }
    set<int>::iterator it;
    for(int i=0; i < matrix.size(); i++)
    {
        it = rows.find(i);
        bool flag = false;
        if(it != rows.end())
            flag = true;
        for(int j=0; j < matrix[i].size(); j++)
        {
            if(flag)
                matrix[i][j] = 0;
            else
            {
                it = columns.find(j);
                if(it != columns.end())
                    matrix[i][j] = 0;
            }
        }
    }
}

void Print(vector<vector<int> > &matrix)
{
    for(int i=0; i < matrix.size(); i++)
    {
        for(int j=0; j < matrix[i].size(); j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
}

int main()
{
    cout << "enter M and N of MxN matrix" << endl;
    int M, N;
    cin >> M >> N;
    cout << "enter the MxN matrix" << endl;
    vector<vector<int> > matrix;
    for(int i=0; i < M; i++)
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
    Print(matrix);
    return 0;
}
