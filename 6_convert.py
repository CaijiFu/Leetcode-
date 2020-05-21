class Solution:
    def convert(self, s: str, numRows: int) -> str:
        # ����numRows������
        mtrx = ['' for i in range(numRows)]
        res = ''
        if numRows==1:
            return s
        # ���ν�����е�˳��Ϊ0����numRows-1����0, ���Կ���2*numRows-2һ��ѭ��
        for i in range(len(s)):
            row = i%(2*numRows-2)
            if row <= numRows-1:
                mtrx[row] += s[i]
            else:
                mtrx[2*(numRows-1)-row] +=s[i]
        # ����mtrx��ƴ�Ӽ���
        for i in range(numRows):
            res += mtrx[i]
        return res