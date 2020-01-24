#include <stdio.h>
#include <dirent.h>

int main (void) {
    DIR *dir;
    struct dirent *ent;

    char directory[255] = "./";
    dir = opendir(directory);

    while ((ent=readdir(dir)) != NULL){
        printf("%s %d\n", ent->d_name, ent->d_ino);
    }
    closedir(dir);
    return 0;
}