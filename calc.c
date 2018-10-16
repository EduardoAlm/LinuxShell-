#include "shell.h"

void calc (char *value, char *op, char *value2){

    double val = atof( value);
    double val2 = atof(value2);
    double res = 0.00;
    
    switch(op[0]){
        case '+':
            res=val+val2; 
                printf("O resultado é: %f\n", res);
            
            break;
        case '*':
            res= val*val2;
                printf("O resultado é: %f\n", res);
            
            break;
        case '-':    
            res= val-val2;
                printf("O resultado é: %f\n", res);
            
            break;
        case '/':
            if(val2==0.00){
                printf("Not possible to divide by zero\n");
            }else {
                res= val/val2;
                printf("O resultado é: %f\n", res);
            }
            break;
        case '^':
                res= powf(val, val2);
                    printf("O resultado é: %f\n", res);
            break;
    }
    
}
