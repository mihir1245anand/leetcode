class Solution {
public:
    bool uniformArray(vector<int>& nums) {
        int mini = *min_element(nums.begin(), nums.end());

        if (mini % 2 == 1)
            return true;

        for (int x : nums) {
            if (x % 2 == 1)
                return false;
        }

        return true;
    }
};