class MinStack {
public:
    std::shared_ptr<MinStack>  _top{nullptr};
    int _val{0};
    int _min_val{std::numeric_limits<int>::max()};
    MinStack() {
        
    }
    
    void push(int val) {
        auto _top_old = _top;
        _top = std::make_shared<MinStack>();
        _top->_val = val;
        if(_top_old != nullptr)
            _top->_min_val = std::min(val,_top_old->_min_val);
        else
            _top->_min_val = val;
        _top->_top = _top_old;
    }
    
    void pop() {
        if(_top != nullptr){
            _top = _top->_top;
        }
    }
    
    int top() {
        if(_top != nullptr){
            return _top->_val;
        }

        return -1;
    }
    
    int getMin() {
        return _top->_min_val;
    }
};
