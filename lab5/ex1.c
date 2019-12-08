#include<stdio.h>
#include<string.h>

void reverse (char s[]);
void swap (char s[], int k, int i);
int i = 0;
int main(void){
    char s[50];
   while(s[i] != EOF){
        s[i] = getchar();
        if(s[i] == '\n'){
            break;
        }
        i++;
    }
    reverse(s);
    printf("%s", s);
}

void reverse(char s[]){
swap(s, 0, i);
}

void swap(char s[], int k, int i){
    int c, j;
    j = i - (k + 1);
    if (k < j){
        c = s[k];
        s[k] = s[j];
        s[j] = c;
        swap (s, ++k, i);
    }
}
