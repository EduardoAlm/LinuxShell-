#include "shell.h"

void aviso (char *xmsg, int tempo){
    while(tempo>0){
        sleep(1);
        tempo--;
    }
    fprintf(stderr,"Aviso: %s\n", xmsg);
}
