#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char s[20]; 
int top = -1;  


void push(char x) {
    s[++top] = x;
}


char pop() {
    if (top == -1) {
        return -1;  
    } else {
        return s[top--];
    }
}

int priority(char x) {
    if (x == '(') return 0;
    if (x == '+' || x == '-') return 1;
    if (x == '*' || x == '/') return 2;
    return -1;  
}


int main() {
    char exp[20];
    char *e;
    char x;

    printf("Enter the expression:\n");
  fgets(exp,sizeof(exp),stdin);
    e = exp;
 
    exp[strcspn(exp, "\n")] = 0;

    while (*e != '\0') {
        if (isalnum(*e)) {
            printf("%c", *e);
        } else if (*e == '(') {
            push(*e);
        } else if (*e == ')') {
            while ((x = pop()) != '(') {
                if (x == -1) {
                    printf("Error: Mismatched parentheses\n");
                    return 1;
                }
                printf("%c", x);
            }
        } else {
            while (top != -1 && priority(s[top]) >= priority(*e)) {
                printf("%c", pop());
            }
            push(*e);
        }
        e++;
    }

   
    while (top != -1) {
        printf("%c", pop());
    }

    printf("\n");
    return 0;
}
