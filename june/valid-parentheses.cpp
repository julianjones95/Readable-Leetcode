#include <string>

class Solution {
public:
    bool isValid(string s) {
        
        if(s.length()<2){
            return false;
        }

        stack<int> stack;
        


        for(int i=0; i<s.length(); i++){
            

            if(s[i]=='{' || s[i]=='(' || s[i]=='['){
                stack.push(s[i]);
            }
            else if(stack.size() == 0){
                return false;
            }
            else if(s[i]=='}' ){
                if(stack.top()=='{'){
                    stack.pop();
                }
                else{
                    return false;
                }
            }
            else if(s[i]==']'){
                if(stack.top()=='['){
                    stack.pop();
                }
                else{
                    return false;
                }
            }
            else if(s[i]==')' ){
                if(stack.top()=='('){
                    stack.pop();
                }
                else {
                    return false;
                }
            }

        }

        if(stack.size()>0){
            return false;
        }

        return true;
    }
};
