#include <stdio.h>
int bitcount(unsigned x);
int main (void)
{
    int n;
    printf("Input n:\n");
    scanf("%d", &n);
    printf("%d\n", bitcount(n));
    return 0;
    }
int bitcount(unsigned x)
{
    int b;
    for(b = 0;x != 0; x >>=1)
    {
        if(x & 01)
        {
            b++;
        }
    }
    return b;
}