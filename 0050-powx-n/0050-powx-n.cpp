class Solution {
public:
    double myPow(double x, int n) {
        // Optimal approach
        // We will take ans variable to store aqnswer
        // We do if n%2==0 then we do x=x*x and n=n/2
        // if n%2==1 then we do ans=ans*x and n=n-1;
        // if negative value of ans is there then we simly make n positive and we store it in long for overflow then at the end of following above method we do ans=1/ans;

        // code
        double ans=1.0;
        long nn=n;
        if(n<0) nn=-1*nn;
        while(nn>0){
            if(nn%2==0){
                x=x*x;
                nn=nn/2;
            }
            else{
                ans=ans*x;
                nn=nn-1;
            }
        }
        if(n<0) ans=1.0/ans;
        return ans;
    }
};