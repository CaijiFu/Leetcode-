class Solution:
    def longestPalindrome(self, s: str) -> str:
        n= len(s)
        dp = [[False]*n for _ in range(n)]
        res = ''
        # �ԽǱ����������Խǣ��ٴζԽ�
        # i, j�ֱ�����к��У�dp[i][j]��˼�Ǵ�s[i]��s[j]�Ƿ�Ϊ���Ĵ�
        for j in range(n):
            i = 0
            while j < n:
                if i == j:
                    dp[i][j] = True
                elif i == j - 1:
                    dp[i][j] = s[i] == s[j]
                else:
                     dp[i][j] = s[i] == s[j] and dp[i+1][j-1]
                if dp[i][j] and len(res) < j-i+1:
                    res = s[i:j+1]
                i += 1
                j += 1
        return res