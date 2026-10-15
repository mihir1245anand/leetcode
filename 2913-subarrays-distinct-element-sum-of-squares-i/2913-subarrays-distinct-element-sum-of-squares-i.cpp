#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < (int)nums.size(); ++i) {
            unordered_set<int> seen;
            for (int j = i; j < (int)nums.size(); ++j) {
                seen.insert(nums[j]);
                int s = seen.size();
                ans += s * s;
            }
        }
        return ans;
    }
};