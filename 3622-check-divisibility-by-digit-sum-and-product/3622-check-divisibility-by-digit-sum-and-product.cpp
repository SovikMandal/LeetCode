class Solution {
public:
    bool checkDivisibility(int n) {
        long long product = 1;
        long long sum = 0;
        int temp = n;

        while(temp > 0) {
            int digit = temp % 10;
            product *= digit;
            sum += digit;
            temp /= 10;
        }

        if(n % (product + sum) == 0) {
            return true;
        }

        return false;
    }
};