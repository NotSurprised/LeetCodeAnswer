int reverse(int x) {
    int rev = 0;
    while(x != 0){
        int pop = x % 10;
        if (rev > INT_MAX/10 || (rev == INT_MAX/10 && pop > 7) || rev < INT_MIN/10 || (rev == INT_MIN/10 && pop < -8)) return 0; //(2^31 - 1)%10 = 7 (-2^31)%10 = 2/-8
        x = x/10;
        rev = rev * 10 + pop;
    }
    return rev;
}