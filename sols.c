#include "shell.h"

int sols (int noArgs, char **args){

    DIR *dp;
    struct dirent *dirp;

    
    if(noArgs !=2){
        fprintf(stderr, "Usage: %s Um argumeto é necessário\n", args[0]);
    return 1;
    }
    if((dp=opendir(args[1]))==NULL){
        fprintf(stderr, "Can't open %s\n", args[1]);
        return 1;
    }
    while((dirp=readdir(dp))!=NULL){
        
            struct stat fileStat;
            stat(dirp->d_name, &fileStat);
        
        printf("Information of %s\n\n", dirp->d_name);
        
        printf("File Permissions: \t\n");
            printf( (S_ISDIR(fileStat.st_mode)) ? "d" : "-");
            printf( (fileStat.st_mode & S_IRUSR) ? "r" : "-");
            printf( (fileStat.st_mode & S_IWUSR) ? "w" : "-");
            printf( (fileStat.st_mode & S_IXUSR) ? "x" : "-");
            printf( (fileStat.st_mode & S_IRGRP) ? "r" : "-");
            printf( (fileStat.st_mode & S_IWGRP) ? "w" : "-");
            printf( (fileStat.st_mode & S_IXGRP) ? "x" : "-");
            printf( (fileStat.st_mode & S_IROTH) ? "r" : "-");
            printf( (fileStat.st_mode & S_IWOTH) ? "w" : "-");
            printf( (fileStat.st_mode & S_IXOTH) ? "x" : "-");
            printf("\n");
            
        printf("File inode: \t%ld\n",fileStat.st_ino);
            
        if ((fileStat.st_mode & S_IFREG)==S_IFREG)
            printf("%s %ld\n\n\n", dirp->d_name,(long)fileStat.st_size);
        else 
            printf("%s Not Reg File \n\n\n", dirp->d_name);
    }
 
    closedir(dp);
       return 0;
    
}
