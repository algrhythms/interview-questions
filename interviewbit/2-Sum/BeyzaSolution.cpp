struct Node
{
    int val, index;
    Node *next;
    Node()
    {
        val=0;
        index = 0;
        next = NULL;
    }
    Node(int x, int k)
    {
        val = x;
        index = k;
        next = NULL;
    }
    Node(int x, int k, Node* p)
    {
        val = x;
        index = k;
        next = p;
    }
};

int NextPrime(int x)
{
    if(x <= 2)
        return x;
    if(x % 2 == 0)
        x++;
    bool flag = true;
    while(flag)
    {
        flag = false;
        for(int i=3; i <= x/2; i++)
            if(x % i == 0)
            {
                flag = true;
                x += 2;
            }
    }
    return x;
}

void Add(Node *hashTable, int n, int x, int k)
{
    int hash = (x % n + n) % n;
    Node *t = new Node(x, k);
    if(!hashTable[hash].next)
    {
        hashTable[hash].next = t;
        return;
    }
    Node *p = hashTable[hash].next;
    while(p->next)
        p = p->next;
    p->next = t;
}

int Find(Node *hashTable, int n, int x)
{
    int hash = (x % n + n) % n;
    if(!hashTable[hash].next)
        return -1;
    Node *t = hashTable[hash].next;
    while(t && t->val != x)
        t = t->next;
    if(!t)
        return -1;
    else
        return t->index;
}

vector<int> Solution::twoSum(const vector<int> &A, int B) {
    vector<int> result;
    if(A.size() < 2)
        return result;
    int n = NextPrime(A.size());
    Node *hashTable = new Node[n];
    for(int i=0; i < A.size(); i++)
    {
        int k = Find(hashTable, n, B - A[i]);
        if(k != -1)
        {
            result.push_back(k+1);
            result.push_back(i+1);
            break;
        }
        else
            Add(hashTable, n, A[i], i);
    }
    return result;
    
}
