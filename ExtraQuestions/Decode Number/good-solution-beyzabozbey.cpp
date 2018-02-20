#include <iostream>
#include <vector>
using namespace std;


int solution(vector<int> &nums)
{
	if(nums.size() == 0)
		return 0;
	vector<int> temp(nums.size(), 0);
	vector<vector<int> > v(2, temp);
	if(nums[0] == 0)
		return 0;
	v[0][0] = 1;
	v[0][1] = 0;
	for(int i=1; i < nums.size(); i++)
	{
		if(nums[i] == 0)
		{
			v[0][i] = 0;
			if(nums[i-1] == 1 || nums[i-1] == 2)
				v[1][i] = v[0][i-1];
			else
				return 0;
		}
		else
		{
			v[0][i] = v[0][i-1] + v[1][i-1];
			int x = nums[i-1]*10 + nums[i];
			if(nums[i-1] != 0 &&  1 <= x && x <= 26)
				v[1][i] = v[0][i-1];
			else
				v[1][i] = 0;
		}
	}
	return (v[0][nums.size()-1] + v[1][nums.size()-1]);

}

int main()
{
	int arr[] = {1, 1, 1, 1};
	int num = 4;
	vector<int> nums;
	for(int i = 0; i < num; i++)
		nums.push_back(arr[i]);
	cout << solution(nums) << endl;
	return 0;
}