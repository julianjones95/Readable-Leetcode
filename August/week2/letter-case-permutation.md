# Intuition
I was able to tell this was backtracking immediately since we are dealing with
permutations.

# Approach

Use backtracking to permute each possible character. If the character is
lowercase flip to uppercase and vice versa. In the case the current character
is not a letter recurse to the next case.


# Complexity
- Time complexity:
This is O(2^N) as each letter this bifurcates into 2 different paths each time
it finds a letter.

- Space complexity:
The space complexity here is O(2^N) as this will record a new string for each
time this splits.

# Code
```
class Solution {
public:

    void stringFinder(string soFar, int index, vector<string> &output) {
        if(index >= soFar.size()) {
            output.push_back(soFar);
            return;
        }

        if(isdigit(soFar[index])) {
            stringFinder(soFar, index+1, output);
        } else{
            stringFinder(soFar, index+1, output);
            if(islower(soFar[index])) {
                soFar[index] = toupper(soFar[index]);
            } else {
                soFar[index] = tolower(soFar[index]);
            }
            stringFinder(soFar, index+1, output);
        }
    }

    vector<string> letterCasePermutation(string s) {
        vector<string> output;
        stringFinder(s, 0, output);
        return output;
    }
};
```
