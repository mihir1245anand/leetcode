class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mn = *min_element(nums.begin(), nums.end());
        long long moves = 0;
        for (int x : nums) {
            moves += (long long)x - mn;
        }
        return (int)moves;
    }
};