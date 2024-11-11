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



//
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashtable; //哈希表
        for (int i = 0; i < nums.size(); ++i) { //遍历数组
            auto it = hashtable.find(target - nums[i]);//查找是否有对应的值 //返回一个迭代器指向键值为key的元素，如果没找到就返回end() //返回一个迭代器指向键值为key的元素，如果没找到就返回end()
            if (it != hashtable.end()) { //     //如果找到了//返回一个迭代器指向键值为key的元素，如果没找到就返回end()
                return {it->second, i};// 返回找到的值的下标和当前值的下标
            }//如果没有找到，就把当前值和下标存入哈希表
            hashtable[nums[i]] = i;//把当前值和下标存入哈希表 //哈希表的键是值，值是下标
        }
        return {};
    }
};

// 3.哈希表 good job!
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        vector <int>ans;
        
        for(int i=0;i<nums.size();i++){
            if(map[nums[i]] && 2*nums[i]== target ){
            ans.push_back(map[nums[i]]-1);
            ans.push_back(i);
            return ans;
            }

            else{
            map[nums[i]] = i+1;  
            } 
        }
        
        unordered_map<int, int>::iterator iter = map.begin();
        for( ; iter != map.end(); iter++){
            if( map.find(target - iter->first) != map.end() && map.find(target - iter->first) !=iter) {
                ans.push_back(iter->second-1);
                ans.push_back(map[target - iter->first]-1);
                return ans;
            }

            }
        return ans;
           
        
        
    return ans;
    }
    
};