int lengthOfLongestSubstring(char* s) {
    int maxlen = 1;
    int sublen = 1;
    int last = 0;
    int new = 0;
    int current = 0;
    int temp;
    if(*s == '\0'){
        return 0;
    }
    while(s[current] != '\0'){
        sublen = 1;
        temp = new;
        while(temp != current){
            if(s[temp] == s[current]){ // same within last string, reset new
                new = temp+1;  // reset after same charater
                break;
            }
            if(s[temp] != s[current]){ // count substr len
                sublen++;
                temp++;
            }
        }
        if(sublen >= maxlen){
            maxlen = sublen;
            last = new;
        }
        current++;
    }
    return maxlen;
}