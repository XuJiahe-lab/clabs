#include <stdio.h>
int bitcount(unsigned x);
int main(void)
{
   int a, b, c, d, e;
   a = getchar(); 
   b = getchar();
   if(b != '\n')
     {
       c = getchar();
        if(c != '\n')
          {
            d = getchar();
            if(d != '\n')
            {
              e = getchar();
              if(e !='\n')
              {
                getchar();
              }
            }
          }
     }      
    int n;
    if (b == '\n')
    {
        n = a - '0';
    }
    else if (b != '\n' && c == '\n')
    {
        n = (a - '0') * 10 + (b - '0');
    }
    else if (c != '\n' && d == '\n')
    {
        n = (a - '0') * 100 + (b - '0') * 10 + (c - '0');
    }
    else if (d != '\n' && e == '\n')
    {
        n = (a - '0') * 1000 + (b - '0') * 100 + (c - '0') * 10 + (d - '0');
    }
    else if (e != '\n')
    {
        n = (a - '0') * 10000 + (b - '0') * 1000 + (c - '0') * 100 + (d - '0') * 10 + (e - '0');
    }
    printf("二进制中1的个数是%d\n", bitcount(n));
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
