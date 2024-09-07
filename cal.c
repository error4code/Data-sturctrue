#include<stdio.h>
#include<math.h>
int main()
{
    int sum=0,sub=0,mul=-1;
    int ch;
    int a,b;
    printf("Enter the value of A and B\n");
    scanf("%d%d",&a,&b);
    printf("enter the 1 for add\n 2 for sub\n 3 for multi\n");
    scanf("%d",&ch);
    switch ((ch))
    {
    case 1:
    sum = a+b;
    printf("sum of a and b is %d",sum);

        break;
    case 2:
     sub = a-b;
    printf("sub of a and b is %d ",sub);
    break;
    case 3:
     mul=a*b;
    printf("mul of a and b is %d",mul);
    break;
    
default:
printf("invalid choice");
        break;
    }
}