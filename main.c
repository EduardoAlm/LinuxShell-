#include "shell.h"

#define MYFLAGS S_IRUSR|S_IWUSR

char prompt[100];

int main ()
{
  int len;
  char buf[1024];		/* um comando */
  char *args[64];		/* com um maximo de 64 argumentos */

  strcpy (prompt, "SOSHELL: Introduza um comando : prompt>");

   while (1)
    {
      printf ("%s", prompt);

      if ( fgets(buf,1023,stdin) == NULL)
	{
	  printf ("\n");
	  exit (0);
	}
	len=strlen(buf);
	if ( 1==len ) continue;  // string is only a barra n
	if ( buf[len-1] == '\n' ) buf[len-1] ='\0';
	
        int noArgs=parse (buf, args);	/* particiona a string em argumentos */

        if (!builtin (args,noArgs))
	  execute (args, noArgs);		/* executa o comando */
    }
  return 0;
}

int builtin (char **args, int noArgs)
{
  if (strcmp (args[0], "sair") == 0||strcmp (args[0], "exit") == 0)
    {
      exit (0);
      return 1;
    }
  if (strncmp (args[0], "42", 2)==0)
    {
        printf("Answer to all things in the UNIVEEEEEERSE!! o.o MIND BOGGLING\n");
        return 1;
    }
   if(strcmp (args[0], "quem sou eu")==0||strcmp (args[0], "who am i") == 0){
       system("id");
       return 1;
    }
    if(strncmp (args[0], "PS1", 3)==0){
        
        strcpy(prompt, strcat(args[0]+4, " |prompt>"));
        return 1;
        
    }
    if(strcmp (args[0], "socp")==0){
        
        pthread_t th;
        copiar_t * ptr=(copiar_t *) malloc (sizeof(copiar_t));
        strcpy(ptr->fonte, args[1]);
        strcpy(ptr->destino, args[2]);
        ptr->size=atoi(args[3]);
        pthread_create(&th, NULL, socp ,ptr);
        
        return 1;
    }
    
    
    if(0==strcmp (args[0], "cd")){
        int err;
        if(args[1]==NULL || strcmp(args[1], "~")==0){
            err=chdir(getenv("HOME"));
        }else if(  strcmp (args[1], "..")==0){
            chdir("..");
        }
        else {
            err=chdir(args[1]);;
        }
        
        if(err<0) perror ("chdir failed");
    /*  todo:  char wd[100];
        strcat(getcwd(wd, 99),prompt);
        strcpy(prompt, wd);*/
        return 1;//comando embutido
    }
    
    if(0==strcmp(args[0],"calc") && noArgs==4){
    
        calc(args[1], args[2], args[3]);
        return 1;
        
    }
    
    if(0==strcmp(args[0],"bits") && noArgs==4){
    
        bits(args[1], args[2], args[3]);
        return 1;
        
    }
    
    if(0==strcmp(args[0],"isjpg")){
    int fd=-1;
    if((fd=open(args[1], O_RDONLY)) < 0){
                return 0;
    }
    if(isjpg(fd)==1){
        printf("Its a image.\n");
    }else {
        printf ("Better luck next time.\n");
    }
    return 1;
        
    }
    
    if(0==strcmp(args[0],"aviso")){
        pthread_t th;
        aviso_t * ptr=(aviso_t *) malloc (sizeof(aviso_t));
        strcpy(ptr->msg, args[1]);
        ptr->tempo=atoi(args[2]);
        pthread_create(&th, NULL, avisoWrapper,ptr);
        return 1;
        
    }
    
    if(0==strcmp(args[0],"sols")){
       int retCol = sols(noArgs, args);
       return retCol;
    }
    
  return 0;
}
