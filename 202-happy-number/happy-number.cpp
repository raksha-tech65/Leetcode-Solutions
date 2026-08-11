class Solution {
public:
int fun(int n){
    int sum=0;
    while(n>0){
    int digit=n%10;
    sum+=digit*digit;
    n=n/10;
}
   return sum;
}
    bool isHappy(int n) {
        int slow = n;
        int fast = n;
        while(true){
            slow = fun(slow);
            fast = fun(fast);
            fast = fun(fast);
            if(fast==1){
                return true;
            }
            if(slow==fast){
                return false;
            }
        }
    }
};