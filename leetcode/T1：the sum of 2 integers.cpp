# include <iostream>
# include <vector>
using namespace std;

// 1.暴力解法
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        for(int i =0;i<nums.size();i++){
            for(int j = i+1;j<nums.size();j++){
                if(nums[i]+nums[j]==target){
                    ans.push_back(i);
                    ans.push_back(j);
                    break;
                    }
            }
        }
    return ans;
    }
};



// 2.哈希表 ,时间复杂度O(n),但是没有实现有重复数据的情况
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans1(target);
        for(int i =0;i<nums.size();i++){
                if(nums[i]<=target-1)
                    {ans1[nums[i]-1] = i+1;}
        }
        for(int i =0;i<target;i++){
        cout<<ans1[i];}
        vector<int> ans;
        for(int i = 0;;i++){
            if(ans1[target-i-2]==0){
            }
            else{
                ans.push_back(ans1[i]-1);
                ans.push_back(ans1[target-i-2]-1);
break;
            }
            
        }
        return ans;}
};

