class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0) return false; 
        double power = log2(n);
        return floor(power) == power;
    }
};