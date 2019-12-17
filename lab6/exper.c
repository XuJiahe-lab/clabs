#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAXOP 100
#define NUMBER '0'
#define MAXVAL 100
#define BUFSIZE 100

char getop(char s[]);
void push(double);
double pop(void);

int n;
int sp = 0;
double val[MAXVAL];

void push(double f)
{
    if (sp < MAXVAL)
    {
        val[sp++] = f;
    }
    else
    {
        printf("error: stack full, can't push %g\n", f);
    }
}

double pop(void)
{
    if (sp > 0)
    {
        return val[--sp];
    }
    else
    {
        printf("error: stack empty\n");
        return 0.0;
    }
}

int main(int argc, char *argv[])
{
    double op2;
    int n;

    for (n = 1; --argc > 0; n++)
    {
        switch (getop(argv[n]))
        {
        case NUMBER:
            push(atof(argv[n]));
            break;
        case '+':
            push(pop() + pop());
            break;
        case '*':
            push(pop() * pop());
            break;
        case '-':
            op2 = pop();
            push(pop() - op2);
            break;
        case '/':
            op2 = pop();
            if (op2 != 0.0)
            {
                push(pop() / op2);
            }
            else
            {
                printf("error: zero divisor\n");
            }
            break;
        default:
            printf("error: unknow command %s\n", argv[n]);
            argc = 1;
            break;
        }
    }
    printf("\t%.8g\n", pop());
    return 0;
}

char getop(char s[])
{

    if ((s[0] == '-' && isdigit(s[1])) || (isdigit(s[0])))
    {
        return NUMBER;
    }
    else if (s[0] == '-' || s[0] == '+' || s[0] == '/' || s[0] == '*')
    {
        return s[0];
    }
    else
    {
        return 0;
    }
}
