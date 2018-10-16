#include "shell.h"

void *avisoWrapper (void *args){
    
    aviso_t * ptr = (aviso_t *)args;
    aviso(ptr->msg, ptr->tempo);
    free(ptr);
    return NULL;
    
}
