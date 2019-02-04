char* convert(char* s, int numRows) {
    if (numRows == 1){
        return s;
    }
    
    int len = strlen(s);
    char *ans = (char*)malloc((len + 1) * sizeof(char));
    ans[len] = '\0';
    
    int index = 0;
    int interval = numRows*2-2;
    for (int x =0; x < len; x += interval){
        ans[index++] = s[x];
    }
    
    for (int i = 1; i < numRows - 1; i++) {
        for (int x = i; x < len; x += interval) {
            int y = x + 2 * (numRows - i - 1);
            ans[index++] = s[x];
            if (y < len){
                ans[index++] = s[y];
            }
        }
    }
    for (int x = numRows - 1; x < len; x += interval){
        ans[index++] = s[x];
    }
    return ans;
}