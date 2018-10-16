#include "shell.h"

void bits (char *value, char *op, char *value2){

    int val = atoi( value);
    int val2 = atoi(value2);
   
    
    switch(op[0]){
        case '&':
             
                printf("O resultado é: %d\n", val&val2);
            
            break;
        case '^':
            
                printf("O resultado é: %d\n", val^val2);
            
            break;
        case '|':    
            
                printf("O resultado é: %d\n", val|val2);
            
            break;
        case '<':    
            
                printf("O resultado é: %d\n", val<<val2);
            
            break;
        case '>':    
            
                printf("O resultado é: %d\n", val>>val2);
            
            break;
        case '~':    
            
                printf("O resultado é: %d %d\n", (~val), (~val2));
            
            break;
        
    }
    
}
