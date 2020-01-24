#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>



int main(void){
    struct dirent ** nl;
    struct dirent ** tmp;
    DIR *cat;
    FILE *curfile;
    char curname[256];
    int n, i, j;
    int *arr, tmpint;
	system("cls");
    n = scandir("DIR", &nl, NULL, compare);
    scandir("DIR", &tmp, NULL, compare);
    //printf("%d\n", n);
    if (n == -1)
        return 1;
    n--;

    arr = (int*)malloc(sizeof(int) * n);

    for (i = 2; i < n; i++){
        sprintf(curname, "DIR/%s", nl[i]->d_name);
        if (!(curfile = fopen(curname, "r"))){
            printf("err\n");
            return -2;
        }
        printf("%s\n", nl[i]->d_name);
        fseek(curfile, 0, SEEK_END);
        arr[i] = ftell(curfile);
        fclose(curfile);
        printf("%d\n", arr[i]);
    }

    for (i = 2; i < n; i++){
        for (j = i; ((j > 2) && (arr[j - 1] > arr[j])); j--){
            tmp[0] = nl[j];
            nl[j] = nl[j-1];
            nl[j-1] = tmp[0];
            tmpint = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = tmpint;
        }
    }

    for (i = 2; i < n; i++){
        printf("%s   %d bytes\n", nl[i]->d_name, arr[i]);
        free(nl[i]);
        free(tmp[i]);
    }
    free(nl[1]);
    free(nl[n]);
    free(tmp[1]);
    free(nl[n]);
    free(nl);
    free(tmp);
    free(tmp);
    free(arr);
    return 0;
}
