class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int oddSum = 0;
        int evenSum = 0;
        int i = 1;

        while(n) {
            if(i % 2 == 0) {
                evenSum += i;
                i++;
                n--;
            } else {
                oddSum += i;
                i++;
            }
        }

        int ans = gcd(oddSum, evenSum);
        return ans;
    }
};