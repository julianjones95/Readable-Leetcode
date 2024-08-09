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
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        // If sixe not possible return original
        if(r*c != mat.size()*mat[0].size()) {
            return mat;
        }
        
        // Create the correctlz sized vector
        vector<vector<int>> output(r, vector<int> (c, 0));
        
        int x = 0;
        int y = 0;

        for(int i=0; i<mat.size(); i++) {
            for(int j=0; j<mat[0].size(); j++) {
                if(x == c) {
                    y++;
                    x = 0;
                }
                output[y][x] = mat[i][j];
                x++;
            }
        }
        return output;
    }
};
```
