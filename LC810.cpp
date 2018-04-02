class Solution {
public:
    bool xorGame(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            sum ^= nums[i];
        }
        if (!sum) return true;
        return !(n&1);
    }
};
