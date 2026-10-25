class Solution {
    public int[] intersect(int[] nums1, int[] nums2) {
        HashMap<Integer, Integer> map = new HashMap<>();
        ArrayList<Integer> res = new ArrayList<>();
        for(int x : nums1) {
            if(map.containsKey(x)) {
                map.put(x, map.get(x) + 1);
            } else {
                map.put(x, 1);
            }
        }

        for (int x : nums2) {
            if (map.getOrDefault(x, 0) > 0) {
                res.add(x);
                map.put(x, map.get(x) - 1);
            }
        }

        int[] ans = new int[res.size()];
        for(int i = 0; i < res.size(); i++) {
            ans[i] = res.get(i);
        }
        return ans;
    }
}