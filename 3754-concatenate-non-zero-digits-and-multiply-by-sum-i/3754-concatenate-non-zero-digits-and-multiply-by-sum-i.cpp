class Solution {
public:
    long long sumAndMultiply(int n) {
        long long sum = 0, res = 0, m = 1;
        while(n) {
            int digit = n % 10;
            if(digit) {
                res = digit * m + res;
                m *= 10;
                sum += digit;
            }

            n /= 10;
        }

        return res * sum;
    }
};