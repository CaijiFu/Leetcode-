class Solution {
public:
    double pow_abs(double x,long long n){
        if(n==1) return x;
        if(n==0) return 1;
        if(n>0&&n%2==0) return myPow(x*x,n/2);
        else return x*myPow(x,n-1);
    }
    double myPow(double x, long long n) {
        if(n>=0) return pow_abs(x,n);
        else return 1.0/pow_abs(x,-n); 
    }
};