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
