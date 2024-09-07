#include<stdio.h>
#define N 5
void insertion();
void D();
void display();

int queue[N];
int a[N];
int front=-1;
int rear=-1;
int choice,n;

int main()
{
    for(;;)
    {
        printf("\n1-Insertion\n2-Delection\n3-Display\n");
        printf("\nEnter your choice:\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            insertion();
            break;
            case 2:
            D();
            break;
            case 3:
            display();
            break;
            default:
            printf("\nInvalid choice\n");
            }
            printf("\nDo you want to continue\n1-continue\n2-exit\n");
            scanf("%d",&n);
            if(n==2){
                break;
            }
    }
    return(0);


}

void insertion()
{

    int item;
    printf("\nEnter the item to be inserted:\n");
    scanf("%d",&item);
    if(front==-1)
    {
        front=0;
        rear=0;
        queue[rear]=item;
        }
        else if(((rear+1)%N)==front)
        {
            printf("\nQueue is full\n");
            }
        
        else
        {
           rear=(rear+1)%N;
           queue[rear]=item;
           
           
        
            printf("\n%d has been inserted\n",item);
        }
            }


    void D()
            {
                int item;
                if(front==-1)
                {
                    printf("\nQueue is empty\n");
                    }
                    else if(front==rear)
                    {
                        item=queue[front];
                        front=-1;
                        rear=-1;
                        printf("\n%d has been deleted\n",item);
                        }
                        else {
                            item=queue[front];
                            printf("\nDelected element is %d",item);
                            front=(front+1)%N;
                        }
                        

            }

        void display()
        {
            int i=front;
            if(front==-1)
            {
                printf("\nQueue is empty\n");
            }
            else{
                printf("\nQueue elements are\n");
                while(i!=rear)
                {
                    printf("%d",queue[i]);
                    i=(i+1)%N;
                }
                printf("%d",queue[rear]);
                 }

        }        
        