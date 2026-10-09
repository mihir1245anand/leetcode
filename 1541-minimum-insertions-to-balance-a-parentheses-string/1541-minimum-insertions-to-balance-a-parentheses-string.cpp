class Solution {
public:
    int minInsertions(string s) {
        int temp = 0;
        int count = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                temp += 2;
                if (temp % 2 != 0) {
                    temp--;
                    count++;
                }
            } else {
                temp--;
                if (temp < 0) {
                    count++;
                    temp = 1;
                }
            }
        }

        return count + temp;
    }
};