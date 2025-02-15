class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0;
        int n = nums.size();
        int end = n - 1;
        while(start<=end){
            int mid = start + ((end - start)/2);

            if(nums[mid] == target){
                return mid;
            }
            if(target > nums[mid]){
                start = mid + 1;
            }
            if( target < nums[mid]){
                end = mid - 1;
            }
        }
        return -1;
    }
};