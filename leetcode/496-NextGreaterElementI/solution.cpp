class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        vector<int> result;
        for(int i=0; i < findNums.size(); i++)
        {
            result.push_back(-1);
            bool flag = false;
            for(int j=0; j < nums.size(); j++)
            {
                if(nums[j] == findNums[i])
                {
                    flag = true;
                    continue;
                }
                if(flag && nums[j] > findNums[i])
                {
                    result[i] = nums[j];
                    break;
                }
            }
        }
        return result;
    }
};

// slower version
class Solution {
public:
    struct Node
    {
        int val;
        int nGreater;
        Node *next;
        Node()
        {
            val = 0;
            nGreater = 0;
            next = NULL;
        }
        Node(int x, int y)
        {
            val = x;
            nGreater = y;
            next = NULL;
        }
    };
    int NextPrime(int x)
    {
        if(x <= 2)
            return 2;
        if(x%2 == 0)
            x++;
        bool flag = 1;
        while(flag)
        {
            flag = 0;
            for(int i=3; i <= x/2; i++)
                if(x % i == 0)
                {
                    x += 2;
                    flag = 1;
                    break;
                }
        }
        return x;
    }
    void Add(Node *hashTable, int n, int x, int y)
    {
        Node *p = new Node(x, y);
        int index = (x % n + n) % n;
        p->next = hashTable[index].next;
        hashTable[index].next = p;
    }
    int Get(Node *hashTable, int n, int x)
    {
        int index = (x % n + n) % n;
        Node *t = hashTable[index].next;
        while(t && t->val != x)
            t = t->next;
        if(t)
            return t->nGreater;
        else
            return -1;
    }
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        vector<int> result;
        vector<int> stack;
        int n = NextPrime(nums.size());
        Node *hashTable = new Node[n];
        for(int i=0; i < nums.size(); i++)
        {
            while(stack.size() && stack.back() < nums[i])
            {
                int x = stack.back();
                stack.pop_back();
                Add(hashTable, n, x, nums[i]);
            }
            stack.push_back(nums[i]);
        }
        while(stack.size())
        {
            int x = stack.back();
            stack.pop_back();
            Add(hashTable, n, x, -1);
        }
        
        for(int i=0; i < findNums.size(); i++)
            result.push_back(Get(hashTable, n, findNums[i]));
        
        return result;
    }
};
