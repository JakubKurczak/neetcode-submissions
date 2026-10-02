class Solution {
public:
    bool isAnagram(string s, string t) {
        if(std::size(s) != std::size(t)){
            return false;
        }
        std::unordered_map<char,int> chars_in_s;
        std::unordered_map<char,int> chars_in_t;

        for(const auto& c: s){
            chars_in_s[c] += 1;
        }

        for(const auto& c: t){
            chars_in_t[c] += 1;
        }

        return chars_in_s == chars_in_t;
    }
};
