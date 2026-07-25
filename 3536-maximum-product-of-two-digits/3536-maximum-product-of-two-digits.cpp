class Solution {
public:
    int maxProduct(int n) {
        int firstMax = 0;
        int secondMax = 0;

        while(n) {
            int digit = n % 10;
            if(digit > firstMax) {
                secondMax = firstMax;
                firstMax = digit;
            } else {
                secondMax = max(secondMax, digit);
            }

            n /= 10;
        }

        return (firstMax * secondMax);
    }
};