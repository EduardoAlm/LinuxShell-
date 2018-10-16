#include "shell.h"

#define MYFLAGS S_IRUSR|S_IWUSR


void *socp (void *args){

     copiar_t * ptr = (copiar_t *)args;
    int fdin=open (ptr->fonte, O_RDONLY);
    int fdout=creat (ptr->destino, MYFLAGS);
    int size = ptr->size;
    char *buf=(char *)malloc(size*sizeof(char));
    int n;

    while((n = read(fdin, buf, size))>0)
        write(fdout, buf, n);
    
    free(ptr);
    return NULL;
}
