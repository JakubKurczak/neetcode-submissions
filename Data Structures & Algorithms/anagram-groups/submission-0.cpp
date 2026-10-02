class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::vector<std::vector<std::string>> groups_of_anagrams;
        std::unordered_map<std::string,int> anagram_group_to_index;

        for(std::string s: strs){
            std::string s_cp{s};
            std::sort(s.begin(),s.end());
            if(anagram_group_to_index[s] == 0){
                groups_of_anagrams.push_back(std::vector<std::string>{s_cp});
                anagram_group_to_index[s] = std::size(groups_of_anagrams);
            } else {
                groups_of_anagrams[anagram_group_to_index[s] - 1].push_back(s_cp);
            }
        }
        return groups_of_anagrams;
    }
};
