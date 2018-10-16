#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <math.h>
#include <unistd.h>
#include <pthread.h>
#include <ctype.h>
#include <sys/wait.h>
#include <dirent.h>

typedef struct {

    char msg[100];
    int tempo;
    
} aviso_t;

typedef struct {

    char fonte[100];
    char destino[100];
    int size;
    
} copiar_t;


int parse(char *buf, char **args);

void execute(char **args, int noArgs);

int builtin (char **args, int noArgs);

void *socp (void *args);

void calc (char *value, char *op, char *value2);

void bits (char *value, char *op, char *value2);

int isjpg (int fileDescriptor);

int redirects (int numargs, char *args[]);

int containsPipe(int numArgs, char **args);

void aviso(char *xmsg, int tempo);

void *avisoWrapper(void *args);

int sols (int noArgs, char **args);

/* constantes que podem tornar uteis*/

#define BG 0
#define FG 1
