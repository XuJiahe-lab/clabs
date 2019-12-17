#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int x = 0, y = 0, z = 0;
int len, l, k, m;

void getop(char p[]);
void clear(void);
int year(int m, int x);

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};
int day_of_year(int year, int month, int day);
int day_of_year(int year, int month, int day)
{
    int i, leap;
    leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    for (i = 0; i < month; i++)
    {
        day += daytab[leap][i];
    }
    return day;
}

void getop(char p[])
{
    int n = 0;
    if (n < len)
    {
        while (isdigit(p[n]))
        {
            x = x * 10 + p[n] - '0';
            n++;
        }
        if (p[n] == '/')
        {
            ++n;
        }
        while (isdigit(p[n]))
        {
            y = y * 10 + p[n] - '0';
            n++;
        }
        if (p[n] == '/')
        {
            ++n;
        }
        while (isdigit(p[n]))
        {
            z = z * 10 + p[n] - '0';
            n++;
        }
        if (p[n] == '/')
        {
            ++n;
        }
    }
}

int main(int argc, char *argv[])
{
    len = strlen(argv[1]);
    getop(argv[1]);
    l = day_of_year(x, y, z);
    m = x;
    clear();
    len = strlen(argv[2]);
    getop(argv[2]);
    k = day_of_year(x, y, z);
    printf("%d", k - l + year(m, x));
}

void clear(void)
{
    x = 0;
    y = 0;
    z = 0;
}

int year(int m, int x){
    int w = 0;
    int q;
    q = m;
    while(q < x){
        if(q / 4 == 0){
            w += 366;
        }
        else {
            w += 365;
        }
        ++q;
    }
    return w;
}
