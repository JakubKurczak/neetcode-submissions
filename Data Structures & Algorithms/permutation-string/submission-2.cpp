class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(std::size(s1) > std::size(s2)){
            return false;
        }

        std::unordered_map<char,int> s1_char_nums{};

        for(char c: s1){
            s1_char_nums[c] += 1;
        }

        std::unordered_map<char,int> s2_substr_char_nums{};

        for(int index=0; index<std::size(s1); index++){
            s2_substr_char_nums[s2[index]] += 1;
        }

        if(s2_substr_char_nums == s1_char_nums){
            return true;
        }
        

        int start_index = 0;
        for(int end_index=std::size(s1); end_index<std::size(s2); end_index++){
            s2_substr_char_nums[s2[end_index]] += 1;

            s2_substr_char_nums[s2[start_index]] -= 1;

            if(s2_substr_char_nums[s2[start_index]] == 0){
                s2_substr_char_nums.erase(s2[start_index]);
            }

            start_index += 1;
            
            if(s2_substr_char_nums == s1_char_nums){
                return true;
            }
        }

        return false;
    }
};
