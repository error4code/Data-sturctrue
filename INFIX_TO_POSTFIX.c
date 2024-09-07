#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100

char stack[MAX];
char infix[MAX];
char postfix[MAX];
int top = -1;
 
 void push(char);
 char pop();
 int isEmpty();
 void intopost();
 int space(char);
 void print();
 int precedence(char);

 int main()
 {
    printf("\nEnter the infix expresion\n");
    gets(infix);

    intopost();
    print();

  return 0;
 }


  void intopost()
 {
    int i,j=0;
    char symbol,next;
    for(int i=0;i<strlen(infix);i++)
    {
      symbol = infix[i];
      if(!space(symbol)){

      
      switch (symbol)
      {
      case '(':
        push(symbol);
        break;

        case ')':
        while((next=pop())!= '(')
             postfix[j++] = next;
            break;
         
          case '+':
          case '-':
          case '*':
          case '/':
          case '^':
            while(!isEmpty() && precedence(stack[top]) >= precedence(symbol))
            {
             postfix[j++] = pop();
             push(symbol);
             }
             break;

        default:
        postfix[j++] = symbol;
        break;
      }
      }
    }
    while(!isEmpty())
    postfix[j++] = pop();
    postfix[j] = '\0';
    }




     int space(char c)
     {
        if(c == ' '|| c == '\t')
        return 1;
        else
        return 0;
     }




    int precedence(char symbol)
    {
      switch(symbol)
      {
          case '+':
          case '-':
           return 1;
          case '*':
          case '/':
            return 2;
          case '^': 
          return 3;
      }

    }

    void print()
    {
        int i=0;
        printf("\nThe equivalent postfix expression is:\n");
        while(postfix[i])
        {
            printf("%c",postfix[i++]);

        } printf("\n");


    }

    void push(char c)
    {
        if(top== MAX-1)
        {
            printf("\nStack is Full\n");
            return;
        }
        top++;
        stack[top] = c;

    }



    char pop()
    {
        char c;
        if(top == -1)
        {
            printf("\nStack Underflow\n");
            exit(1);

        }
       
       c = stack[top];
       top = top-1;
       return c;


    }

    int isEmpty()
    {
        if(top == -1)
        return 1;
        else 
        return 0;

    }