import java.util.HashMap;
import java.util.Map;

class Solution {
    public int similarPairs(String[] words) {
        int answer = 0;
        Map<Integer, Integer> letterCombinationCount = new HashMap<>();

        for (String word : words) {
            int bitmaskValue = 0;

            for (int i = 0; i < word.length(); ++i) {
                bitmaskValue |= 1 << (word.charAt(i) - 'a');
            }

            answer += letterCombinationCount.getOrDefault(bitmaskValue, 0);
            letterCombinationCount.put(bitmaskValue, letterCombinationCount.getOrDefault(bitmaskValue, 0) + 1);
        }

        return answer;
    }
}
