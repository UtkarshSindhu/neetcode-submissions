class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> copy = nums ; 
        sort(nums.begin() , nums.end()) ;
        int left = 0 ;
        int right = nums.size() - 1 ; 
        vector<int> answer(2) ; 
        while (left<right) {
            int sum = nums[left] + nums[right] ; 
            if (sum == target) {
               for (int i = 0 ; i<nums.size() ; i++) {
                   if (copy[i] == nums[left] ) {
                    answer[0] = i ; 
                    break ; 
                   }
               }
               for (int i = nums.size()-1 ; i >=0 ; i--) {
                if (copy[i] == nums[right]) {
                    answer[1] = i ; 
                    break;
                }
               } 
               sort(answer.begin() , answer.end()) ; 
               return answer ; 
            }
            if (sum < target) {
                left++ ; 
            }
            else {
                right--;
            }
            

        }
    }
};
