#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX 100
int main(int argc, char *argv[])
{
    double a[MAX], min;
    int i, k = 0;
    while(k < 100){
        if(argv[k + 1] == 0){
            break;
        }
        a[k] = atof(argv[k + 1]);
        k++;
    }
    min = a[0];
    for (i = 0; i < k; i++)
    {
        if(min > a[i]){
            min = a[i];
        }
    }
    printf("%f", min);
    return 0;
}
