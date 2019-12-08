#include <stdio.h>
#include <ctype.h>
#define NUMBER '0'
#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch(void);
void ungetch(int);
char getfloat(double *pn);

int main(void)
{
    int n;
    double s[100];
    double w = 0;

    for (n = 0; n < 100 ; n++)
    {
       
        if(getfloat(&s[n]) == '\n'){
            w = w + s[n];
            break;
        }
         w = w + s[n];
    }

    printf("%f", w);
    return 0;
}

char getfloat(double *pn)
{
    char c;
    int a;
    int b = 1;
    while (isspace(c = getch()))
    {
        ;
    }
    if (!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.')
    {
        ungetch(c);
        return 0;
    }
    a = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-')
    {
        c = getch();
    }
    for (*pn = 0; isdigit(c); c = getch())
    {
        *pn = 10 * *pn + (c - '0');
    }
    if (c == '.')
    {
        c = getchar();
        if (!isdigit(c))
        {
            ungetch(c);
        }
        for (; isdigit(c); c = getchar())
        {
            b *= 10;
            *pn = 10 * *pn + (c - '0');
        }
    }
    *pn = *pn / b * a;
    if (c != EOF)
    {
        ungetch(c);
    }
    return c;
}

int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
    if (bufp >= BUFSIZE)
    {
        printf("ungetch too many characters\n");
    }
    else
    {
        buf[bufp++] = c;
    }
}
