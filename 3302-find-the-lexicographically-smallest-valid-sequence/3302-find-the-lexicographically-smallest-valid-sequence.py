class Solution:
    def validSequence(self, word1: str, word2: str) -> list[int]:
        n, m = len(word1), len(word2)

        # suf[i] = earliest unmatched position in word2
        # after matching word1[i:] from the end
        suf = [0] * (n + 1)
        j = m - 1
        suf[n] = m

        for i in range(n - 1, -1, -1):
            if j >= 0 and word1[i] == word2[j]:
                j -= 1
            suf[i] = j + 1

        ans = []
        i = 0
        used_change = False

        for j in range(m):
            while i < n:
                # Exact match
                if word1[i] == word2[j]:
                    ans.append(i)
                    i += 1
                    break

                # Use the one allowed modification
                if not used_change and suf[i + 1] <= j + 1:
                    ans.append(i)
                    used_change = True
                    i += 1
                    break

                i += 1
            else:
                return []

        return ans 