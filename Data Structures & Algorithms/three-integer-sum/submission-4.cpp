class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::sort(std::begin(nums),std::end(nums));
        std::vector<std::vector<int>> solutions{};
        for(int index=0;index < std::size(nums); index++){
            int target = nums[index];
            target *= (-1);

            if(index > 0 && nums[index] == nums[index-1]){
                continue; 
            }
            //equasion is nums[index] + nums[front_index] + nums[back_index] = 0;
            // -nums[inded] = nums[front_index] + nums[back_index];

            int front_index = index + 1;

            int back_index = std::size(nums) -1;

            while(front_index < back_index){
                if(target < nums[front_index] + nums[back_index]){
                    back_index--;
                } else if (target > nums[front_index] + nums[back_index]){
                    front_index++;
                } else {
                    solutions.push_back({nums[index],nums[front_index],nums[back_index]});
                    while(front_index < back_index && nums[front_index] == nums[front_index+1]) front_index++;
                    while(front_index < back_index && nums[back_index] == nums[back_index-1]) back_index--;
                    front_index++;
                }
            }
        }

        return solutions;
    }
};
