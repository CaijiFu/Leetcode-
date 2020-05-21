class Solution:
    def convert(self, s: str, numRows: int) -> str:
        # 构造numRows个队列
        mtrx = ['' for i in range(numRows)]
        res = ''
        if numRows==1:
            return s
        # 依次进入队列的顺序为0——numRows-1——0, 可以看到2*numRows-2一个循坏
        for i in range(len(s)):
            row = i%(2*numRows-2)
            if row <= numRows-1:
                mtrx[row] += s[i]
            else:
                mtrx[2*(numRows-1)-row] +=s[i]
        # 返回mtrx的拼接即可
        for i in range(numRows):
            res += mtrx[i]
        return res