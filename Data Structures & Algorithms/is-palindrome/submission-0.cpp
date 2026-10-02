class Solution {
public:
// from A 65 to a 97 is +32
// if not between 65(A) and 90 (Z)

    bool isPalindrome(string s) {
        int front_index=0;
        int back_index=std::size(s) -1;
        while(front_index < back_index){
            
            
            if(not std::isalnum(s[front_index])){
                front_index++;
                continue;
            }

            while(not std::isalnum(s[back_index])){
                    back_index--;
                    continue;
            }

            if(std::tolower(s[front_index]) != std::tolower(s[back_index])){
                return false;
            } else {
                front_index++;
                back_index--;
            }
        }

        return true;
    }
};