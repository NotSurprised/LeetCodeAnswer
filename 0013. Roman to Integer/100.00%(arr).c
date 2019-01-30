int find_num(char c) {
    int num;
    switch (c) {
        case 'I':
            num = 1;
            break;
        case 'V':
            num = 5;
            break;
        case 'X':
            num = 10;
            break;
        case 'L':
            num = 50;
            break;
        case 'C':
            num = 100;
            break;
        case 'D':
            num = 500;
            break;
        case 'M':
            num = 1000;
            break;
        default:
            num = 0;
            break;
    }
    return num;
}

int romanToInt(char* s) {
    int i;
    int num;
    num = 0;
    i = strlen(s)-1;

    while(i >= 0) {
        if(((s[i] == 'V')||(s[i] == 'X')) && (i > 0) && (s[i-1] == 'I')) {
            num += (find_num(s[i])-find_num(s[i-1]));
            i--;
        } else {
            if(((s[i]=='L')||(s[i]=='C')) && (i > 0) && (s[i-1] == 'X')) {
                num += (find_num(s[i])-find_num(s[i-1]));
                i--;
            } else {
                if(((s[i] == 'D')||(s[i] == 'M')) && (i > 0) && (s[i-1] == 'C')) {
                    num += (find_num(s[i])-find_num(s[i-1]));
                    i--;
                } else {
                    num += find_num(s[i]);
                }
            }
        }
        i--;
    }
    return num;
}