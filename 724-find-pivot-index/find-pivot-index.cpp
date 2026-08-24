class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=nums.size();
        int leftsum=0;
        int totalsum=0;
        for(int x: nums){
            totalsum+=x;
        }
        for(int i=0; i<n; i++){
         int rightsum=totalsum-nums[i]-leftsum;
         if(leftsum==rightsum){
            return i;
         }
         leftsum+=nums[i];
        }
        return -1;
    }
};