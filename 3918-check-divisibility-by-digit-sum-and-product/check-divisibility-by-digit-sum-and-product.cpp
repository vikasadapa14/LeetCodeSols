class Solution {
public:
    bool checkDivisibility(int n) {
        long long sum=0,prod=1;
        int original=n;
        while(n>0){
            int digit=n%10;
            sum+=digit;
            prod*=digit;
            n/=10;
        }
        if(original % (sum+prod) == 0) return true;
        return false;;
 
    }
};