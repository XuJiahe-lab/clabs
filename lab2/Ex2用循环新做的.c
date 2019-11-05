#include <stdio.h>
int bitcount(unsigned x);
int main(void)
{
    char X[6];
    int i;
    int n = 0;
    for (i = 0; i < 7; i = i + 1)
    {
        X[i] = getchar();
        if(X[i] == '\n')
        {
            break;
        }
        n = n*10 + (X[i] - '0');
    }
    printf("二进制中1的个数是%d\n", bitcount(n));
    return 0;
}
int bitcount(unsigned x)
{
    int b;
    for (b = 0; x != 0; x >>= 1)
    {
        if (x & 01)
        {
            b++;
        }
    }
    return b;
}
