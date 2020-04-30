class Solution:
    def reverse(self, x: int) -> int:
        if x>0:
            si=1
        else:
            si=-1
        s=str(abs(x))
        s=s[::-1]
        return si*int(s) if si*int(s)<=2**31-1 and si*int(s)>=-2**31 else 0