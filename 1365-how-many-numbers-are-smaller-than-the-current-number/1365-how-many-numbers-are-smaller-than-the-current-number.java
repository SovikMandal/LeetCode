class Solution {
    public int[] smallerNumbersThanCurrent(int[] nums) {
        int n = nums.length;
        int[] arr = new int[n];

        for(int i = 0; i < n; i++) {
            int val = nums[i];
            int count = 0;
            for(int j = 0; j < n; j++) {
                if(val > nums[j]) {
                    count++;
                }
            }

            arr[i] = count;
        }

        return arr;
    }
}