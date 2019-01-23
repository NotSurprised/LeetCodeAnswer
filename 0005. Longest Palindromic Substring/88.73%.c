char* longestPalindrome(char* s) {
    int temp = 0;
    int maxlen = 0;
    int anshead = 0;
    while(s[temp] != '\0'){
        int len = 1;
        int head = 0;
        int left = temp - 1;
        int right = temp + 1;
        if(s[left] == s[right]){
            head = temp;
            while(s[left] == s[right] && s[left] != '\0'){
                len += 2;
                head = left;
                left--;
                right++;
            }
        }
        if(len > maxlen){
            maxlen = len;
            anshead = head;
        }
        left = temp - 1;
        right = temp + 1;
        if(s[right] == s[temp]){
            right++;
            len = 2;
            head = temp;
            while(s[left] == s[right] && s[left] != '\0'){
                len += 2;
                head = left;
                left--;
                right++;
            }
        }
        if(len > maxlen){
            maxlen = len;
            anshead = head;
        }
        temp++;
    }
    char *ans = (char *) malloc(sizeof(char) * (maxlen + 1));
    int i;
    for( i = 0; i < maxlen; i++){
        ans[i] = s[anshead + i];
    }
    ans[i] = '\0';
    return ans;
}