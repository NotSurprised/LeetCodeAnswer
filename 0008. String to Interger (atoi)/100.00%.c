bool isNumeric(char s) {
    if (s >= '0' && s <= '9')
    {
        return true;
    }
    return false;
}

int Char2Int(char s) {
    return s - '0';
}

int myAtoi(char *str) {
    int signFlag = 0;
    int result = 0;
    while (*str) {
        if (*str == ' ') {
            if (signFlag != 0) { // we must finish atoi after sign and before space.
                break;
            }
            
            str++;
            continue;
        }

        if (!isNumeric(*str)) {
            if (signFlag != 0) { // we must finish atoi after sign and before non numeric char.
                break;
            }
            
            if (*str == '+') {
                signFlag = 1;
            } else if (*str == '-') {
                signFlag = -1;
            } else { // begin with non numeric char, then we stop and return.
                break;
            }
            
            str++;
            continue;
        }

        if (signFlag == 0) { // directly start with number, or start with space, this might be positive number but without positive sign. 
            signFlag = 1;
        }

        if (signFlag == -1 && signFlag * result <= (INT_MIN + Char2Int(*str)) / 10.0) { //without float, you will meet some unexpectable round up.
            return INT_MIN;
        }

        if (signFlag == 1 && result >= (INT_MAX - Char2Int(*str)) / 10.0) {
            return INT_MAX;
        }

        result = result * 10 + Char2Int(*str); // add new numeric char.
        str++;
    }
    return result * signFlag;
}