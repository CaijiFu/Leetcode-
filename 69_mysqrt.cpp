class Solution {
public:
    int mySqrt(int x) {
        if(x==0) return 0;
        double c=x,x1=x,x0=x;
        while(true){
            x1=0.5*(x0+c/x0);
            if((x0-x1)<1e-7) break;
            x0=x1;
        }
        return (int)x0;
    }
};