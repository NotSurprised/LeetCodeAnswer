int romanToInt(char* s) {
    int num;
    num = 0;
    char *temp = s;
    unsigned char tempchar;
    unsigned char last;
    unsigned char next;

    while(*temp != '\0') {
        tempchar = *temp;
        next = *(temp+1);
        last = *(temp-1);
        if(((tempchar == 'V')||(tempchar == 'X')) && (*temp != '\0') && (last == 'I')) {
            num += (find_num(tempchar)-2*find_num(last));
            temp++;
        } else if(*temp == '\0') {
            break;
        } else {
            if(((tempchar=='L')||(tempchar=='C')) && (*temp != '\0') && (last == 'X')) {
                num += (find_num(tempchar)-2*find_num(last));
                temp++;
            } else if(*temp == '\0') {
                break;
            } else {
                if(((tempchar == 'D')||(tempchar == 'M')) && (*temp != '\0') && (last == 'C')) {
                    num += (find_num(tempchar)-2*find_num(last));
                    temp++;
                } else {
                    num += find_num(tempchar);
                    temp++;
                }
            }
        }
    }
    return num;
}