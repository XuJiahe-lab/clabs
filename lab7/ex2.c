#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
int main(int argc, char *argv[])
{
    double a[6];
    int i, j, k = 0;
    while(k < 6){
        a[k] = atof(argv[k + 1]);
        k++;
    }
    for (i = 0; i < 6; i++)
    {
        for (j = 0; a[i] <= a[j]; j++)
            ;
        if (j == 5)
        {
            break;
        }
    }
    printf("%f", a[i]);
    return 0;
}
