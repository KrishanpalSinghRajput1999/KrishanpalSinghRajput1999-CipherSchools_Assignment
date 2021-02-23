//submitted on leetcode
class Solution {
    public int lengthOfLongestSubstring(String s) {
        Map<Character, Integer> map = new HashMap();
        int longest = 0, i = 0, j = 0, n = s.length();
        while(j < n) {
            if(map.containsKey(s.charAt(j)))
                i = Math.max(map.get(s.charAt(j)), i);
            map.put(s.charAt(j), j + 1);
            longest = Math.max(longest, j - i + 1);
            j++;
        }
        return longest;
    }
}
