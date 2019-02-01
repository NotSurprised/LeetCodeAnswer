int numJewelsInStones(char* J, char* S) {
    char *tempS = S;
    char *tempJ = J;
    int ans = 0;
    while(*tempS != '\0'){     
        tempJ = J;
        while(*tempJ != '\0'){
            if(*tempJ == *tempS){
                ans++;
                break;
            }
            else{
                tempJ++;
            }            
        }        
        tempS++;
    }
    return ans;
}