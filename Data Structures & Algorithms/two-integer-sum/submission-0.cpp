class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int,int> diff_to_index{};
        for(int index=0; index < std::size(nums); index++){
            if(diff_to_index[target - nums[index]] == 0){
                diff_to_index[nums[index]] = index + 1;
            } else {
                return {diff_to_index[target - nums[index]] -1, index};
            }
        }
    }
};
