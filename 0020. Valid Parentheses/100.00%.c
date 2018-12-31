int top;
char *stack;
int isEmpty(){
	if(top == -1){
		return 1; 
	}else{
		return 0;
	}
} 
void push(char data){
    top++;
    stack[top] = data;
}
char pop(){
	char data;
    data = stack[top];
    top--;
    return data;	
}
bool isValid(char* s){
    bool result = true;
    top = -1; // reset top after every round
    int stringlen = 0;
    int i = 0;
    while(s[stringlen] != NULL){
        stringlen = stringlen + 1;
    }
    stack = (char*) malloc(stringlen * sizeof(char));    
    while(s[i] != NULL){
        char new = s[i];
        if(new == '(' || new == '[' || new == '{'){ // add to stack
            push(new);
            i=i+1;
        } else if(new == ')'){ // pop out stack data to compare
            if('(' != pop()){               
               result = false;
               break;
            }
            i=i+1;
        } else if(new == ']'){ // pop out stack data to compare
            if('[' != pop()){               
               result = false;
               break;
            }
            i=i+1;
        } else if(new == '}'){ // pop out stack data to compare
            if('{' != pop()){               
               result = false;
               break;
            }
            i = i + 1;
        }        
    }    
    free(stack);
    if(isEmpty() == 0){
        return false;
    }
    return result;    
}