class Solution {
    public int majorityElement(int[] nums) {
        HashMap<Integer, Integer> map = new HashMap<>();
        for(int x : nums) {
            if(map.containsKey(x)) {
                map.put(x, map.get(x) + 1);
            } else {
                map.put(x, 1);
            }
        }

        for(int key : map.keySet()) {
            if(map.get(key) > nums.length/2) {
                return key;
            }
        }

        return -1;
    }
}