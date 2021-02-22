//Submitted on Leetcode
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
class Solution 
{
 public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
     const int DIM = nums.size();
    std::vector<int> res(2);
    std::map<int, int> ma;
    
    for(int i = 0; i < DIM; i++)
    {
        const int numj = target - nums[i];
        const auto it = ma.find(numj);
        
        if (it != ma.end())
        {
            res[0] = ma[numj];
            res[1] = i;
            
            return res;
        }
        
        ma.insert(std::pair<int, int>(nums[i], i));
    }
                       
    return res;
    }
};
int main()
{
 int target;
 cin>>target;
 vector<int> nums;
 nums.push_back(2); nums.push_back(7); nums_push_back(11); nums_push_back(15);
 Solution obj;
 int res = obj.twoSum(nums,target);
}
