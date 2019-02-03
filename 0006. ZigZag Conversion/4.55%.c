char* convert(char* s, int numRows) {
    // fill back
    char *temp = s;
    int slen = 0;
    int length = 0;
    int point = 0;
    if ((numRows*2-2) == 0){
        return s;
    }
    while(*temp != '\0'){
        point++;
        length++;
        slen++;
        if( point % (numRows*2-2) == 0 || point % (numRows*2-2) >= numRows){
            length = length+numRows-2;
        }
        temp++;
    }
    int column = length / numRows;
    if((length % numRows) != 0){
        column++;
    }
    // dynamic declare 2D array
    char **ansMatrix = (char**)malloc(sizeof(char*) * column);
    for (int i = 0; i < column; i++){
            ansMatrix[i] = (char*)malloc(sizeof(char) * numRows);
    }
    int tempLen = 0;
    int interval = 0;
    temp = s;
    for(int i = 0; i < column; i++){
        for(int j = 0; j < numRows; j++){
            if(*temp == '\0'){
                ansMatrix[i][j] = ' ';
            } else if((tempLen != 0 && tempLen % (numRows*2-2) == 0 && interval < numRows-2)||(tempLen % (numRows*2-2) >= numRows && interval < numRows-2)){
                ansMatrix[i][j] = ' ';
                char check = ansMatrix[i][j];
                interval++;
            } else {
                ansMatrix[i][j] = *temp;
                char check = ansMatrix[i][j];
                temp++;
                tempLen++;
                if(interval >= numRows-2){
                    interval = 0;
                }
            }
        }
    }
    char *ans = (char*)malloc(sizeof(char) * tempLen+1);
    for (int i = 0; i < tempLen+1; i++){
        ans[i] = ' ';
    }
    int tempCount =0;
    for(int i = 0; i < numRows; i++){
        for(int j = 0; j < column; j++){
            char output = ansMatrix[j][i];
            if(output != ' '){
                ans[tempCount] = output;
                tempCount++;
            }
        }
    }
    ans[tempLen] = '\0';
    return ans;
}