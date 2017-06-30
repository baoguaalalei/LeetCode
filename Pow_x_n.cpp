
//该计算应该考虑数据是负值最大的时候，INT_MIN，这个时候直接转换为正直会报错
class Solution {
public :
double myPow(double x, int n) {
     
     if(n==0) return 1.0;
     
     double half=(double)myPow(x,n/2);
     
    if(n%2==0) return half*half;
    
    else return (n>0)?(half*half*x):(half*half*1.0/x);
     
    }
};
