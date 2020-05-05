class Solution {
public:
    bool isPalindrome(int x) {
       if(x<0) return false;
       long res=0,a=0,cur=x;
       while(cur!=0){
           a=cur%10;
           res=res*10+a;
           cur=cur/10;
       }
       if(res==x) return true;
       else return false;


    }
};