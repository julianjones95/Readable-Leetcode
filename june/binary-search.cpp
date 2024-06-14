#include <vector>

class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int l = 0;
        int mid;
        int r = nums.size()-1;

        
        while(l<=r){

            mid = l + (r-l) /2;

            if(target> nums[mid]){
                l = mid + 1;
            }
            else if(target<nums[mid]){
                r = mid - 1;
            }
            else{
                return mid;
            }

        }



        return -1;
    }
};
