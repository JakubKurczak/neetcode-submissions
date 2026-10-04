class Solution {
public:
    bool isValid(string s) {
        std::vector<char> _stack;

        for(auto& c: s){
            switch(c){
                case '(':
                case '{':
                case '[':
                    _stack.push_back(c); break;
                case ')':
                    if(std::empty(_stack) || _stack.back() != '('){
                        return false;
                    }
                    _stack.pop_back();
                    break;
                case ']':
                    if(std::empty(_stack) || _stack.back() != '['){
                        return false;
                    }
                    _stack.pop_back();
                    break;
                case '}':
                    if(std::empty(_stack) || _stack.back() != '{'){
                        return false;
                    }
                    _stack.pop_back();
                    break;
                default:
                    return false;           
            }
        }
        if(!std::empty(_stack)){
            return false;
        }

        return true;
    }
};
