#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXOP 100
#define NUMBER '0'
#define MAXVAL 100
#define BUFSIZE 100

int getop(char[]);
void push(double);
double pop(void);
int getch(void);
void ungetch(int);

int sp = 0;
double val[MAXVAL];
char buf[BUFSIZE];
int bufp = 0;

int main(void)
{
    int type;
    double op2, op1;
    char s[MAXOP];

    while ((type = getop(s)) != EOF)
    {
        switch (type)
        {
        case NUMBER:
            push(atof(s));
            break;
        case '+':
            push(pop() + pop());
            break;
        case '*':
            push(pop() * pop());
            break;
        case '-':
            op2 = pop();
            break;
        case '/':
            op2 = pop();
            if (op2 != 0.0)
            {
                push(pop() - op2);
            }
            else
            {
                printf("error: zero divisor\n");
            }
            break;
        case '%':
            op2 = pop();
            if (op2 != 0.0)
            {
                push((long int)pop() % (long int)op2);
            }
            else
            {
                printf("error: zero divisor\n");
            }
            break;
            case 'a':/*打印栈顶元素 */
            op1 = pop();
            printf("\t%.8g\n", op1);
            push(op1);
            break;
            case 'b':/*复制栈顶元素 */
            op1 = pop();
            push(op1);
            push(op1);
            break;
            case 'c':/*交换栈顶两个元素的值 */
            op1 = pop();
            op2 = pop();
            push(op1);
            push(op2);
            break;
            case'd':/*清空栈 */
            sp = 0;
            break;
        case '\n':
            printf("栈的值是%.8g\n", pop());
            break;
        default:
            printf("error: unknow command %s\n", s);
            break;
        }
    }
    return 0;
}

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

int getop(char s[])
{
    int i, c;
    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    i = 0;
    if (!isdigit(c) && c != '.' && c != '-' )
        return c;
    if(c == '-'){
        if(isdigit(c = getch()) || c == '.'){
            s[++i] = c;
        }
        else{
            return '-';
        }
    }
    if (isdigit(c))
        while (isdigit(s[++i] = c = getch()))
            ;

    if (c == '.')
        while (isdigit(s[++i] = c = getch()))
            ;

    s[i] = '\0';

    if (c != EOF)
        ungetch(c);
    return NUMBER;
}

int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}
