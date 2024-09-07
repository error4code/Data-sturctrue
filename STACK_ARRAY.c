#include<stdio.h>
#define MAX 10
int main()
{
    int n,ch,top=-1,a[MAX],x,i;
    char ch1;
    do
    {
        printf("\n1-PUSH\n2-POP\n3-DISPLAY\n");
        printf("\nEnter the choice\n");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
         printf("\nEnter the element to PUSH\n");
         scanf("%d",&x);
         if(top==MAX-1)
         {
            printf("\noverflow\n");
         }
         else{
            top++;
            a[top]=x;
            printf("\nThe element %d has been PUSHED \n",x);


         }
            break;
            case 2:
            if (top==-1)
            {
             printf("\nUnderflow\n");
             break;
        
            }
            else{
                x=a[top];
                top--;
                printf("\nElement %d has been POPED OUT",x);

            }break;
            case 3:
            if(top==-1)
            {
                printf("\nStack is empty\n");
                break;

            }
            else{
                printf("\nElements of the stacks are\n");
                for ( i = top; i >=0; i--)
                {
                   printf("%d",a[i]);

                }
                break;
                
            }
            
        
        default:printf("\nWrong choice\n");

            break;
        }
        printf("\nDo you want to continue\n(y/n)");
        scanf("%s",&ch1);
    } while (ch1=='y');
    return(0);

    
}