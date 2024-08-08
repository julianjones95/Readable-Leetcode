# Intuition
This uses 2 pointers. 

# Approach
You can use 2 pointers here to move through this array checking to see if at
any point the end array is different from the initial array. If it is different
you know that it must have changed. At this point you can append the necessary
characters and move the start to be equal the end array.

# Complexity
- Time complexity:
The time complexity here is O(N), as this moves through each element in the
array until end is at the end.

- Space complexity:
Space complexity here is O(1) as it does not need to store any extra data to
accomplish this.

# Code
```
class Solution {
public:

    void numericalInsert(int &start, int &end, vector<char> &input,
        vector<char> &chars, int &counter) {
        if(end - start < 10){
            input.push_back('0' + end - start);
            counter++;
        } else {
            string length = to_string(end-start);
            for(char ch: length) {
                input.push_back(ch);
                counter++;
            }
        }
    }

    void insertCharacters(int &start, int &end, vector<char> &input,
        vector<char> &chars, int &counter){
        if(end-start > 1) {
            input.push_back(chars[start]);
            numericalInsert(start, end, input, chars, counter);
        } else {
            input.push_back(chars[start]);
        }
        counter++;
        start = end;
    }

    int compress(vector<char>& chars) {
        int counter, start, end = 0;
        vector<char> input;

        while(start < chars.size()) {
            if(end >= chars.size()) {
                insertCharacters(start, end, input, chars, counter);
                break;
            }

            if(chars[start] == chars[end]) {
                end++;
            } else {
                insertCharacters(start, end, input, chars, counter);
            }
        }
        chars = input;
        return counter;
    }
};
```
