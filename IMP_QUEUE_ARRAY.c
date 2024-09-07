#include<stdio.h>
#include<stdlib.h>
#define MAX 10
void insertion();
void deletion();
void display();
int i,choice,rear,front,queue[MAX],items;
int n;
int main()
{
    front = 0;
    rear = -1;
   for(;;)
    {   printf("\nQueue Operations\n");
        printf("1.Insertion\n");
        printf("2.Deletion\n");
        printf("3.display\n");
        scanf("%d",&choice);
        switch(choice)
        {   case 1:
            insertion();
            break;
            case 2:
            deletion();
            break;
            case 3: 
            display();
            break;
             case 4:
            exit(0);
            default:printf("wrong input");
         }
        printf("\nDo you want to continue\n 1 for continue \n 2 for exit \n");
        scanf("%d",&n);
        if(n==2)
        {  break;
        }}
    return 0;
}
void insertion()
{  if(rear == MAX-1)
    {        printf("\nQueue is over flow\n");
    }
    else
    {
        printf("Enter the item to be inserted\n");
        scanf("%d",&items);
        rear++;
        queue[rear] = items;
    }}
void deletion()
{
    if(front>rear)
    {
        printf("\nQueue is empty or under flow\n");
    }
    else
    {       items = queue[front];
        for(i=0;i<=rear;i++)
        {            queue[i] = queue[i+1];
            rear--;
            printf("\nThe deleted elements for thr array is %d \n",items);

        }}}
void display()
{
int i;
    if (rear==-1)  
      {
        printf("\nQueue is empty\n");
    }
    else
    {
        printf("\nQueue elements are\n");
        for (i=front;i<=rear;i++)
        {
            printf("%d at %d \n",queue[i],i);
        }}}