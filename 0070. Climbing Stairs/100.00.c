int climbStairs(int n) {
    int last1 = 1;
    int last2 = 1;
    int target = 0;
    if(n < 2){
        return 1;
    }
    for(int i = 2; i <= n; i++){
       target = last1 + last2; // target = all last1 methods + 1 step & last2 methods + 2 steps
       last2 = last1; // setting new value for next round
       last1 = target;
    }
    return target;
}