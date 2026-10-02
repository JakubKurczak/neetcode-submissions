class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(std::empty(s)){
            return 0;
        }
        int first_index = 0;
        int max_length = 0;
        std::unordered_map<char,int> num_of_chars{};
        
        num_of_chars[s[first_index]] += 1;

        for(int second_index = 1; second_index < std::size(s); second_index++){
            num_of_chars[s[second_index]] += 1;
            if(num_of_chars[s[second_index]] == 1){
                max_length = std::max(max_length, second_index - first_index);
            } else {
                while(num_of_chars[s[second_index]] != 1){
                    num_of_chars[s[first_index]] -= 1;
                    first_index += 1;
                }
            }
        }
        return max_length + 1;
    }
};
