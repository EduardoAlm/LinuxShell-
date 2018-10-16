/*
   execute . cria um processo progénito e executa um programa
*/
#include "shell.h"
 
int ultimo (char **args, int *noArgs){

    if(args[*noArgs-1][0]=='&'){
        //(*noArgs)--;
        args[--*noArgs]=NULL;
        return BG;
    }
    return FG; 
}
 
void execute (char **args, int noArgs)
{
    int pid, status;
    int code =ultimo(args, &noArgs);
     int indice, pidNovoFilho, fd[2];
    //if(code==BG){noArgs--;}

    if ((pid = fork ()) < 0)
    {				/* cria um processo progenito */
      perror ("forks");		/* NOTE: perror() produz uma pequema mensagem
				 * de erro para o stream */
      exit (1);			/* estandardizado de erros que descreve o
				 * ultimo erro encontrado */
      /* durante uma chamada ao sistema ou funcao duma biblioteca */
    }

    if (pid == 0)
    {
        
      
     indice = containsPipe(noArgs, args);
     if (indice > 0){
    printf("pipe detected at index %d\n", indice);
    printf("Remove pipe symbol. Create pipe. Fork(). Exec in 2 processes\n");
    args[indice] = NULL;
    pipe(fd);
    pidNovoFilho = fork();
    
    //write
    if(pidNovoFilho == 0){
        noArgs=indice;
        printf ("cmd write to pipe:   %s   numArgs:   %d   \n", args[0], noArgs);
        dup2 (fd[1], STDOUT_FILENO);
        close(fd[0]);
    }
    //read
    else {
        args = args + indice + 1;
        noArgs = noArgs - indice - 1;
        if(noArgs==0){ printf("cmd read to pipe. No Args found!\n");exit(0);}
        else {printf ("cmd read to pipe:   %s   numArgs:   %d   \n", args[0], noArgs);
        dup2 (fd[0], STDIN_FILENO);
        close(fd[1]);
    
        }
        }
     }
        
      redirects (noArgs, args);
      execvp (*args, args);	/* NOTE: as versoes execv() e
				 * execvp() de execl() sao uteis
				 * quando */
      perror (*args);		/* o numero de argumentos nao e. conhecido.
				 * Os argumentos de  */
      exit (1);			/* execv() e execvp() sao o nome do ficheiro
				 * a ser executado e um */
    }				/* vector de strings que contem os
				 * argumentos. O ultimo argument */

    if(FG==code) {
          while (wait (&status) != pid);
    }
				 

  return;
}
