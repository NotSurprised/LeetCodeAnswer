int lengthOfLongestSubstring(char* s) {
    int maxlen = 1;
    int sublen = 1;
    char *last = s;
    char *new = s;
    char *current = s;
    char *temp;
    if(*s == '\0'){
        return 0;
    }
    while(*current != '\0'){
        sublen = 1;
        temp = new;
        while(temp != current){
            if(*temp == *current){ // same within last string, reset new
                new = temp+1;  // reset after same charater
                break;
            }
            if(*temp != *current){ // count substr len
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