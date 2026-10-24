class Solution {
    private String generate(String str) {
        int[] arr = new int[26];
        for(char ch : str.toCharArray()) {
            arr[ch - 'a']++;
        }

        StringBuilder newString = new StringBuilder();
        for(int i = 0; i < 26; i++) {
            int freq = arr[i];
            for (int j = 0; j < freq; j++) {
                newString.append((char) ('a' + i));
            }
        }

        return newString.toString();
    }

    public List<List<String>> groupAnagrams(String[] strs) {
        HashMap<String, List<String>> map = new HashMap<>();
        for(String s : strs) {
            String key = generate(s);
            
            if(!map.containsKey(key)) {
                map.put(key, new ArrayList<>());
            }

            map.get(key).add(s);
        }

        return new ArrayList<>(map.values());
    }
}