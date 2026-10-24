class Solution {
    public boolean containsDuplicate(int[] nums) {
        HashMap<Integer, Integer> freq = new HashMap<>();
        for(int num : nums) {
            if(freq.containsKey(num)) {
                return true;
            }

            freq.put(num, 1);
        }

        return false;
    }
}