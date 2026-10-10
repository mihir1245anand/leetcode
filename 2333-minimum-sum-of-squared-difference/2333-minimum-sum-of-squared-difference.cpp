class Solution {
public:
    using ll = long long;

    long long minSumSquareDiff(vector<int>& nums1,
                               vector<int>& nums2,
                               int k1, int k2) {
        int n = nums1.size();
        vector<int> freq(100001, 0);

        for (int i = 0; i < n; i++) {
            freq[abs(nums1[i] - nums2[i])]++;
        }

        int k = k1 + k2;

        for (int d = 100000; d > 0; d--) {
            if (freq[d] == 0) continue;

            int need = freq[d];

            if (k >= need) {
                freq[d - 1] += freq[d];
                k -= need;
                freq[d] = 0;
            } else {
                freq[d - 1] += k;
                freq[d] -= k;
                k = 0;
            }
        }

        ll ans = 0;

        for (int d = 1; d <= 100000; d++) {
            ans += 1LL * freq[d] * d * d;
        }

        return ans;
    }
};