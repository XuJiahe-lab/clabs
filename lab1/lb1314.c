#include <stdio.h>
int main()
{
           int celsius, fahr;
           int lower, upper, step;

           lower=0;
           upper=100;
           step=5;
            
           celsius=lower;
           while(celsius <= upper) {
                       fahr=9*celsius/5+32;
                       printf("%d\t%d\n", celsius,  fahr);
                       celsius=celsius+step;
           }
}