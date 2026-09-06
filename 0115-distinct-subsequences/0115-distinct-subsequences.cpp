class Solution {
public:
    int numDistinct(string s, string t) {
        vector<vector<int>> dp(s.length()+1, vector<int>(t.length()+1, -1));

        function<int(int, int)> solve = [&](int i, int j) -> int{
            if(j == t.length()) return 1;
            if(i == s.length()) return 0;

            if(dp[i][j] != -1) return dp[i][j];

            int ans = solve(i+1, j);
            if(s[i] == t[j]) ans += solve(i+1, j+1);

            return dp[i][j] = ans;
        };

        return solve(0, 0);
    }
};