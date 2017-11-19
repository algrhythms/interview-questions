class Solution {
public:
    
    bool helper(vector<int> &bits, int pos)
    {
        if(pos < 0)
            return true;
        if(pos == 0)
            return (bits[pos]==0);
        if(bits[pos] == 0)
        {
            if(bits[pos-1] == 0)
                return helper(bits, pos-1);
            else
            {
                if(helper(bits, pos-1))
                    return true;
                else
                    return helper(bits, pos-2);
            }
        }
        else
        {
            if(bits[pos-1] == 1)
                return helper(bits, pos-2);
            else
                return false;
        }
        
        
    }
    
    bool isOneBitCharacter(vector<int>& bits) {
        int len = bits.size();
        if(bits[len-1] == 1)
            return false;
        return helper(bits, len-2);
    }
};
