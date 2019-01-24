bool isPalindrome(int x) {
    if(x < 0 || (x % 10 == 0 && x != 0)) {
        return false;
    }
    int halfRevert = 0;
    while(x/10 > halfRevert) {
        halfRevert = halfRevert * 10 + x % 10;
        x /= 10;
    }
    if(x == halfRevert || x/10 == halfRevert){
        return true;
    } else {
        return false;
    }
}