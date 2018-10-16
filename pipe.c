#include "shell.h"


int containsPipe(int numArgs, char **args){

    int index;
    for(index = 0;index<numArgs;index++){
    
        if(args[index][0] == '|'){
        
            return index;
            
        }
        
    }
    
    return -1;
    
}
/*
int main(){

    int indice, pidNovoFilho, fd[2], numArgs;
    
   // char *myargs[]={"ls","-l", "-a", NULL};
    //char *myargs[]={"ls","-l", "-a", "|", "wc", "-c", NULL};
   char *myargs[]={"cat","-t", "/etc/passwd","|", "grep", "root", NULL};
    
    
    char **args = myargs;
     numArgs = 6;
     indice = containsPipe(numArgs, args);
     if(indice==-1){
        execvp(*args, args);
    }
    printf("pipe detected at index %d\n", indice);
    printf("Remove pipe symbol. Create pipe. Fork(). Exec in 2 processes\n");
    args[indice] = NULL;
    pipe(fd);
    pidNovoFilho = fork();
    
    //write
    if(pidNovoFilho == 0){
        numArgs=indice;
        printf ("cmd write to pipe:   %s   numArgs:   %d   \n", args[0], numArgs);
        dup2 (fd[1], STDOUT_FILENO);
        close(fd[0]);
    }
    //read
    else {
        args = args + indice + 1;
        numArgs = numArgs - indice - 1;
        printf ("cmd read to pipe:   %s   numArgs:   %d   \n", args[0], numArgs);
        dup2 (fd[0], STDIN_FILENO);
        close(fd[1]);
    }
    
    execvp(*args, args);
    return 0;
}
*/
