#include <stdio.h>
#define MAXLINE 1000
int main(void){
char s[MAXLINE];
char t[MAXLINE];
int m = 0;
int n = 0;
while ((s[m] = getchar()) != EOF)
{
    if (s[m] == ' ')
    {
        break;
    }
    m++;
}
while (s[m] == ' ' && (t[n] = getchar()) != EOF && t[n] != '\n')
{
    if (t[n] == '\n')
    {
        break;
    }
    n++;
}
 int p;
 p = n - 1;
 int i, j, k;
    for (i = m - 1; i > 0; i--)
    {
        for (j = i, k = p ; s[j] == t[k]; j--, k--)
            ;
        if (k < 0 )
        {
            printf("t在s最右边出现的位置为：%d\n", j + 1);
            return i;
        }
    }
    printf("没有找到");
}
