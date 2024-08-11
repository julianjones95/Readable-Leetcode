# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->

# Approach
<!-- Describe your approach to solving the problem. -->

# Complexity
- Time complexity:
<!-- Add your time complexity here, e.g. $$O(n)$$ -->

- Space complexity:
<!-- Add your space complexity here, e.g. $$O(n)$$ -->

# Code
```
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> output;
        map<string, vector<string>> anagramMap;

        for(string str : strs) {
            string unSortedStr = str;
            sort(str.begin(), str.end());
            anagramMap[str].push_back(unSortedStr);
        }

        for(const auto& [key, value] : anagramMap) {
            output.push_back(value);
        }

        return output;
        
    }
};
```
