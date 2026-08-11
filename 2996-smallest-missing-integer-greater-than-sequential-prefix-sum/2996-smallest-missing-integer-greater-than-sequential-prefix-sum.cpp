#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int sum = nums[0];

        // Find the sum of the longest sequential prefix
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1] + 1)
                sum += nums[i];
            else
                break;
        }

        // Store all elements in a set
        unordered_set<int> st(nums.begin(), nums.end());

        // Find the smallest missing integer >= sum
        while (st.count(sum))
            sum++;

        return sum;
    }
};